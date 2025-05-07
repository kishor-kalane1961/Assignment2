#include <iostream>
using namespace std;
class TBT;
class node
{
    node *left, *right;
    int data;
    bool rbit, lbit;

public:
    node()
    {
        left = NULL;
        right = NULL;
        rbit = lbit = 0;
    }
    node(int d)
    {
        left = NULL;
        right = NULL;
        rbit = lbit = 0;
        data = d;
    }
    friend class TBT;
};

class TBT
{
    node *root; // acts as a dummy node
public:
    TBT() // dummy node initialization
    {
        root = new node(9999);
        root->left = root;
        root->rbit = 1;
        root->lbit = 0;
        root->right = root;
    }
    void create();
    void insert(int data);
    node *inorder_suc(node *);
    void inorder_traversal();
    node *preorder_suc(node *c);
    void preorder_traversal();
};
void TBT::preorder_traversal()
{
    node *c = root->left;
    while (c != root)
    {
        cout << " " << c->data;
        c = preorder_suc(c);
    }
}
void TBT::inorder_traversal()
{
    node *c = root->left;
    while (c->lbit == 1)
        c = c->left;
    while (c != root)
    {
        cout << " " << c->data;
        c = inorder_suc(c);
    }
}
node *TBT::inorder_suc(node *c)
{
    if (c->rbit == 0)
        return c->right;
    else
        c = c->right;
    while (c->lbit == 1)
    {
        c = c->left;
    }
    return c;
}
node *TBT::preorder_suc(node *c)
{
    if (c->lbit == 1)
    {
        return c->left;
    }
    while (c->rbit == 0)
    {
        c = c->right;
    }
    return c->right;
}
//-------- Create Method
void TBT::create()
{
    int n;
    cout << "\nEnter number of nodes:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int info;
        cout << "\nEnter data: ";
        cin >> info;
        this->insert(info);
    }
}
void TBT::insert(int data)
{

    if (root->left == root && root->right == root) // no node in tree
    {
        node *p = new node(data);
        p->left = root->left;
        p->lbit = root->lbit; // 0
        p->rbit = 0;
        p->right = root->right;
        root->left = p;
        root->lbit = 1;
        cout << "\nInserted start" << data;
        return;
    }
    node *cur = new node;
    cur = root->left;
    while (1)
    {

        if (cur->data < data) // insert right
        {
            node *p = new node(data);
            if (cur->rbit == 0)
            {
                p->right = cur->right;
                p->rbit = cur->rbit;
                p->lbit = 0;
                p->left = cur;
                cur->rbit = 1;
                cur->right = p;
                cout << "\nInserted right " << data;
                return;
            }
            else
                cur = cur->right;
        }
        if (cur->data > data) // insert left
        {  node *p = new node(data);
            if (cur->lbit == 0)
            {
                p->left = cur->left;
                p->lbit = cur->lbit;
                p->rbit = 0;
                p->right = cur; // successor
                cur->lbit = 1;
                cur->left = p;
                cout << "\nInserted left" << data;
                return;
            }
            else
                cur = cur->left;
        }
    }
}

int main()
{  TBT t1;
    int value;
    int choice;
    do
    {
        cout << "\n-------------------------\n\t1.Create Tree\n\t2.Insert into tree\n\t3.Preorder\n\t4.Inorder\n\t5.Exit\n-------------------------\n\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            t1.create();
            break;
        case 2:
            cout << "\nEnter Number(data): ";
            cin >> value;
            t1.insert(value);
            break;
        case 3:
            cout << "\nPreorder traversal of TBT\n";
            t1.preorder_traversal();
            break;
        case 4:
            cout << "\nInoder Traversal of TBT\n";
            t1.inorder_traversal();
            break;
        case 5:
            break;
        default:
            cout << "\nWrong choice";
        } } while (choice != -1);

    return 0;
}

#include <iostream>
#include <stdlib.h>
using namespace std;
struct node 
{
    int data;
    node *left, *right;
    int lbit, rbit;
};
class tbt {
    node *temp = NULL, *t1 = NULL, *s = NULL, *head = NULL, *t = NULL;
public:
    node *create();
    void insert();
    node *insuc(node *);
    node *inpre(node *);
    void dis();
    void display(node *);
    void thr();
    void thread(node *);
};
node *tbt::create() {
    node *p = new(struct node);
    p->left = NULL;
    p->right = NULL;
    p->lbit = 0;
    p->rbit = 0;
    cout << "\n Enter the data: ";
    cin >> p->data;
    return p;
}
void tbt::insert() {
    temp = create();
    if (head == NULL) {
    node *p = new(struct node);
    head = p;
    head->left = temp;
    head->right = head;
    head->lbit = 1;
    head->rbit = 0;
    temp->left = head;
    temp->right = head;
    temp->lbit = 0;
    temp->rbit = 0;
    } else {
        t1 = head;
        t1 = t1->left;
        while (t1 != NULL) {
            s = t1;
            if (((temp->data) > (t1->data)) && t1->rbit == 1) {
                t1 = t1->right;
            } else if (((temp->data) < (t1->data)) && t1->lbit == 1) {
                t1 = t1->left;
            } else {
                break;
            }
        }
        if (temp->data > s->data) {
            s->right = temp;
            s->rbit = 1;
            temp->left = s;
            temp->right = insuc(s);
        } else {
            s->left = temp;
            s->lbit = 1;
            temp->left = inpre(s);
            temp->right = s;
        }
    }
}
node *tbt::inpre(node *m) 
{
    if (m->lbit == 1) 
    {
        while (m->right != NULL && m->rbit == 1) 
        {
            m = m->right;
        }
    }
    return m;
}
node *tbt::insuc(node *m) {
    if (m->rbit == 1) {
        while (m->left != NULL && m->lbit == 1) {
            m = m->left;
        }
    }
    return m;
}
void tbt::dis() {
    display(head->left);
}
void tbt::display(node *m) {
    if (m->lbit == 1) {
        display(m->left);
    }
    cout << "\n" << m->data;
    if (m->rbit == 1) {
        display(m->right);
    }
}
void tbt::thr() {
    cout << "\nThreaded nodes are:";
    thread(head->left);
}
void tbt::thread(node *m) {
    if (m->lbit == 1) {
        thread(m->left);
    }
    if (m->lbit == 0 || m->rbit == 0) {
        cout << "\n" << m->data;
    }
    if (m->rbit == 1) {
        thread(m->right);
    }
}
int main() {
    tbt t;
    int ch;
    while (1) {
        cout << "\n Enter the choice";
        cout << "\n 1.Insert data";
        cout << "\n 2.Display all data";
        cout << "\n 3.Display threaded node";
        cout << "\n 4.Exit";
        cout << "\n Enter Your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                t.insert();
                break;
            case 2:
                t.dis();
                break;
            case 3:
                t.thr();
                break;
            case 4:
                exit(0);
            default:
                cout << "\n Invalid entry";
        }
    }
    return 0;
}