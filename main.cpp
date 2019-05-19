#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cmath>

using namespace std;

// ���������
class Container
{
public:
    // ����������� ������, ����� ����������� �����
    virtual void insert(int value) = 0;
    virtual bool exists(int value) = 0;
    virtual void remove(int value) = 0;
    // ��� ����� ������� �� ������������� �������� <<
    virtual void print() = 0;

    // ����������� ����������
    virtual ~Container();
};

Container::~Container() { }

// ���������� ����������

// TODO
struct simpletree
{
    int value;
    simpletree* left;
    simpletree* right;
};
void newsimpletree(int new_value, simpletree** tree)
{
    if ((*tree) == NULL)
    {
        (*tree) = new simpletree;
        (*tree)->value = new_value;
        (*tree)->left = (*tree)->right = NULL;
        return;
    }
    if (new_value > (*tree)->value) newsimpletree(new_value, &(*tree)->right);
    else newsimpletree(new_value, &(*tree)->left);
}

void print(simpletree**tree, int n)
{
    if (*tree != NULL)
    {
        print(&((**tree).right), n + 1);
        for (int i = 1; i <= n; i++)
            cout << "   ";
        cout << (**tree).value << endl;
        print(&((**tree).left), n + 1);
    }
}

void treeprint(simpletree* root)
{
    if (root != NULL)
    {
        cout << root->value << endl;
        treeprint(root->left);
        treeprint(root->right);
    }
}

simpletree* minvalue(simpletree* tree)
{
    if (tree->left != NULL)
    {
        return minvalue(tree->left);
    }
    else
    {
        return tree;
    }
}

simpletree* maxvalue(simpletree* tree)
{
    if (tree->right != NULL)
    {
        return  maxvalue(tree->right);
    }
    else
    {
        return tree;
    }
}
int number(simpletree* tree)
{
    if (tree == NULL)
        return 0;
    return number(tree->left) + 1 + number(tree->right);
}

int heightoftree(simpletree* tree)
{
    int x = 0, y = 0;
    if (tree == NULL)
        return 0;
    if(tree->left)
        x = heightoftree(tree->left);
    if (tree->right)
        y = heightoftree(tree->right);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
simpletree* searchofelement (simpletree* tree, int key)
{
    if (tree == NULL)
        return NULL;
    if  (tree->value == key)
        return tree;
    if (key < tree->value)
        return searchofelement(tree->left, key);
    else
        return searchofelement(tree->right, key);
}

void destroyoftree(simpletree* tree)
{
    if (tree != NULL)
    {
        destroyoftree(tree->left);
        destroyoftree(tree->right);
        delete(tree);
    }
}
void test()
{
    simpletree* tree = NULL;
    int value1;
    cout << "�������� ������" << endl;
    while (_getch() != 32)
    {
        cout << "������� �������� (������ - ���������� �����) ";
        cin >> value1;
        newsimpletree(value1, &tree);
    }
    print(&tree, 0);
    cout << "������ ����� ������" << endl;
    treeprint(tree);
    cout << "����������� ������� ������-> ";
    simpletree* min = minvalue(tree);
    cout << min->value <<endl;
    cout << "������������ ������� ������-> ";
    simpletree* max = maxvalue(tree);
    cout << max->value <<endl;
    cout << "������ ������-> ";
    int heigh = heightoftree(tree);
    cout << heigh <<endl;
    cout<<"���������� ��������� � ������-> ";
    int a = number(tree);
    cout << a << endl;
    cout << "����� ��������" << endl;
    int key;
    cout << "������� �������� �������� ��� ������-> ";
    cin >> key;
    simpletree* tree1 = searchofelement(tree,key);
    if (tree1 == NULL)
        cout << "������� �� ������"<<endl;
    else
        cout << "��� �������->" << tree1->value <<endl;
    destroyoftree(tree);
}

int main()
{
    Container* c = new simpletree();// ������

    for(int i = 1; i < 10; i++)
        c->insert(i*i);

    printf("List after creation:\n");
    c->print();

    if(c->exists(25))
        cout << "Search for value 25: found" << endl;

    if(!c->exists(111))
        cout << "Search for value 111: not found" << endl;

    c->remove(25);
    cout << "List after deletion of the element:" << endl;
    c->print();

    delete c;
    return 0;
}
