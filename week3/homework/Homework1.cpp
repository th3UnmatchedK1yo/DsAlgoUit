#include<iostream>
#include<cmath>
using namespace std;

int k;

struct Point{

    int* coords=new int ;

    void input(){
        for(int i=0;i< k;i++){
            cout<<"coordinate :   ";
            int x;
            cin>>x;
            coords[i]==x;
        }
    }
};

struct Node {
    Point point ;
    Node* left;
    Node* right;

    Node(Point p): point(p), left(NULL), right(NULL){}

};


class KDTree {
    private:
    Node* root;

    public:

    KDTree(): root(NULL){}

    Node* insertNode (Node* node,Point point, int depth){
        if (node==NULL){
            return new Node(point);
        }

        int axis =depth %k;

        if (point.coords[axis]< node->point.coords[axis]){
            node->left =insertNode(node->left, point,depth +1);
        }else{
            node->right=insertNode(node->right,point,depth+1);
        }
        return node;
    }

    void insert(Point point) {
        root = insertNode(root, point, 0);
    }

    double distance(Point p1,Point p2) {
        double dist = 0;
        for (int i = 0; i < k; ++i)
            dist += pow(p1.coords[i] - p2.coords[i], 2);
        return sqrt(dist);
    }

    void nearesNeighbor (Node* node, Point target, int depth, Node* best ,double& dist ){
        if (node==NULL){
            return;
        }

        double d= distance(target, node->point);
        if (d<dist){
            dist=d;
            best=node;
        }

        int axis=depth%k;
        Node* nextBranch = (target.coords[axis] < node->point.coords[axis]) ? node->left : node->right;
        Node* otherBranch = (nextBranch == node->left) ? node->right : node->left;

        nearesNeighbor(nextBranch, target, depth + 1, best, dist);
        if (fabs(target.coords[axis] - node->point.coords[axis]) < dist)
            nearesNeighbor(otherBranch, target, depth + 1, best, dist);
    }

    Point nearesNeighbor (Point target){
        Node* best=NULL;
        double dist = 1e9;
        nearesNeighbor(root, target, 0, best, dist);
        return best->point;

    }


};

int main() {
    cout << "Enter number of dimensions (k): ";
    cin >> k;

    KDTree tree;
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Point p;
        cout << "Enter coordinates of point " << i + 1 << ":\n";
        p.input();
        tree.insert(p);
    }

    Point target;
    cout << "Enter target point coordinates:\n";
    target.input();

    Point nearest = tree.nearesNeighbor(target);
    cout << "Nearest neighbor coordinates: ";
    for (int i = 0; i < k; i++) {
        cout << nearest.coords[i] << " ";
    }
    cout << endl;

    return 0;
}


