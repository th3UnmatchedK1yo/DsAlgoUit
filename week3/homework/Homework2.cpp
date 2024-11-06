#include <iostream>
#include <cmath>
#include <algorithm>
#include <float.h>

using namespace std;

// Định nghĩa một điểm trong không gian 2D
struct Point {
    int x, y;
};

// Hàm so sánh cho sắp xếp theo trục x
bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

// Hàm so sánh cho sắp xếp theo trục y
bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

// Hàm tính khoảng cách giữa hai điểm
double distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Phương pháp brute force để tìm cặp gần nhất trong một tập nhỏ các điểm
double bruteForce(Point points[], int left, int right) {
    double minDist = DBL_MAX;
    for (int i = left; i < right; ++i) {
        for (int j = i + 1; j <= right; ++j) {
            minDist = min(minDist, distance(points[i], points[j]));
        }
    }
    return minDist;
}

// Tìm khoảng cách gần nhất trong vùng dải (strip)
double closestInStrip(Point strip[], int size, double d) {
    double minDist = d;
    
    // Sắp xếp dải strip theo trục y
    sort(strip, strip + size, compareY);

    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < minDist; ++j) {
            minDist = min(minDist, distance(strip[i], strip[j]));
        }
    }
    return minDist;
}

// Hàm đệ quy để tìm cặp điểm gần nhất
double closestPairRecursive(Point pointsSortedByX[], int left, int right) {
    if (right - left <= 3) {
        return bruteForce(pointsSortedByX, left, right);
    }

    int mid = left + (right - left) / 2;
    Point midPoint = pointsSortedByX[mid];

    double dLeft = closestPairRecursive(pointsSortedByX, left, mid);
    double dRight = closestPairRecursive(pointsSortedByX, mid + 1, right);
    double d = min(dLeft, dRight);

    // Tạo mảng dải (strip) chứa các điểm trong vùng lân cận của trục giữa
    Point strip[right - left + 1];
    int j = 0;
    for (int i = left; i <= right; ++i) {
        if (abs(pointsSortedByX[i].x - midPoint.x) < d) {
            strip[j++] = pointsSortedByX[i];
        }
    }

    return min(d, closestInStrip(strip, j, d));
}

// Hàm khởi động cho thuật toán, sắp xếp các điểm và gọi hàm đệ quy
double closestPair(Point points[], int n) {
    // Sắp xếp các điểm theo trục x
    sort(points, points + n, compareX);
    return closestPairRecursive(points, 0, n - 1);
}

// Ví dụ sử dụng
int main() {
    Point points[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(points) / sizeof(points[0]);
    cout << "Khonga cach nho nhat : " << closestPair(points, n) << endl;
    return 0;
}

