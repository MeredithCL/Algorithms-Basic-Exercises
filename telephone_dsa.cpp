#include <bits/stdc++.h>
using namespace std;
struct Node
{
    bool end;
    Node* c[10];
    Node()
    {
        end = false;
        for (int i = 0; i < 10; ++ i)
        {
            c[i] = NULL;
        }
    }
};
void insertx(string str, Node* root)
{
    int l = str.length();
    Node* temp = root;
    for (int i = 0; i < l; ++ i)
    {
        int index = str[i] - '0';
        if (!temp->c[index])
        {
            temp->c[index] = new Node();
        }
        temp = temp->c[index];
    }
    temp->end = true;
}
bool result = true;
void searchx(Node* root, bool prevx)
{
    for (int i = 0; i < 10; ++ i)
    {
        if (root->c[i])
        {
            if (root->c[i]->end)
            {
                if (prevx)
                {
                    result = false;
                    return;
                }
                prevx = true;
            }
            searchx(root->c[i], prevx);
            prevx = false;
        }
    }
}
void freex(Node* root)
{
    for (int i = 0; i < 10; ++ i)
    {
        if (root->c[i])
        {
            freex(root->c[i]);
        }
    }
    delete root;
}
int main()
{
    int n, t;
    cin >> t;
    for (int u = 0; u < t; ++ u)
    {
        cin >> n;
        string str;
        result = true;
        Node* root = new Node();
        for (int i = 0; i < n; ++ i)
        {
            cin >> str;
            insertx(str, root);
        }
        searchx(root, false);
        if (result)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        freex(root);
    }
    getchar();
    getchar();
    return 0;
}
