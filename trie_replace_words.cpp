#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct Node
    {
        bool end;
        Node* c[26];
        Node()
        {
            end = false;
            for (int i = 0; i < 26; ++ i)
            {
                c[i] = NULL;
            }
        }
    };
    Node* root = new Node();
    string result;
    void insertx(string str)
    {
        int l = str.length();
        Node* temp = root;
        int index;
        for (int i = 0; i < l; ++ i)
        {
            index = str[i] - 'a';
            if (!temp->c[index])
            {
                temp->c[index] = new Node();
            }
            temp = temp->c[index];
        }
        temp->end = true;
    }
    string result1;
    bool found;
    void search(Node* root, string str, string temp, int marker)
    {
        int l = str.length();
        if (marker >= l)
        {
            return;
        }
        int index = str[marker] - 'a';
        if (root->c[index])
        {
            temp += str[marker];
            if (root->c[index]->end)
            {
                found = true;
                if (result1 == "")
                {
                    result1 = temp;
                }
                else
                {
                    if (result1.length() > temp.length())
                    {
                        result1 = temp;
                    }
                    else if (result1.length() == temp.length())
                    {
                        if (result1 > temp)
                        {
                            result1 = temp;
                        }
                    }
                }
            }
            search(root->c[index], str, temp, marker + 1);
            temp.pop_back();
        }
        return;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        int size = dictionary.size();
        for (int i = 0; i < size; ++ i)
        {
            insertx(dictionary[i]);
        }
        result = "";
        string str;
        int l = sentence.length();
        int mark = 0;
        string temp;
        for (int i = 0; i < l; ++ i)
        {
            if (sentence[i] == ' ')
            {
                found = false;
                temp = "";
                result1 = "";
                search(root, str, temp, 0);
                if (found)
                {
                    if (mark)
                    {
                        result += " ";
                    }
                    result += result1;
                    str = "";
                    mark = 1;
                    continue;
                }
                if (mark)
                {
                    result += " ";
                }
                result += str;
                str = "";
                mark = 1;
                continue;
            }
            str += sentence[i];
        }
        found = false;
        temp = "";
        result1 = "";
        search(root, str, temp, 0);
        if (found)
        {
            if (mark)
            {
                result += " ";
            }
            result += result1;
            str = "";
            mark = 1;
            return result;
        }
        if (mark)
        {
            result += " ";
        }
        result += str;
        return result;
    }
};
