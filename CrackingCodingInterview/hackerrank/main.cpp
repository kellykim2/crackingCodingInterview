//
//  main.cpp
//  hackerrank
//
//  Created by Kelly Kim on 6/8/19.
//  Copyright © 2019 Kelly Kim. All rights reserved.
//
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <stack>
//using namespace std;
//
//// Complete the isBalanced function below.
//string isBalanced(string s) {
//    stack<char> st;
//    unsigned long length = s.length();
//    if(length % 2 != 0){
//        return "NO";
//    }
//    for(int i = 0; i < length; i++){
//        if(s.at(0) == ')' || s.at(0) == ']' || s.at(0) == '}' )
//            return "NO";
//        if(s.at(i) == '(' || s.at(i) == '[' || s.at(i) == '{' )
//            st.push(s.at(i));
//
//        else if((s.at(i) == ')' || s.at(i) == ']' || s.at(i) == '}' ) && !st.empty()){
//            char temp = st.top();
//            switch(temp){
//                case '{':{
//                    if (s.at(i) != '}'){
//                        return "NO";
//                    }
//                    break;
//                }
//                case '(':{
//                    if (s.at(i) != ')'){
//                        return "NO";
//                    }
//                    break;
//                }
//                case '[':{
//                    if (s.at(i) != ']'){
//                        return "NO";
//                    }
//                    break;
//                }
//            }
//            st.pop();
//        }
//        else{
//            return "NO";
//        }
//    }
//
//    return "YES";
//
//
//}
//
//int main()
//{
//    //ofstream fout(getenv("OUTPUT_PATH"));
//    ifstream fin ("/Users/kellykim/Documents/hackerrank/hackerrank/hackerrank/input.txt");
//    ifstream sol ("/Users/kellykim/Documents/hackerrank/hackerrank/hackerrank/solution.txt");
//    if(fin.is_open() && sol.is_open()){
//        int t;
//        fin >> t;
//        fin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//        for (int t_itr = 0; t_itr < t; t_itr++) {
//            string s;
//            getline(fin, s);
//            string pass;
//            getline(sol, pass);
//            string result = isBalanced(s);
//            if (result != pass){
//                cout<< "Test failed [" << t_itr <<"]" <<endl;
//                cout << s << endl;
//                cout << "result came out : " << result << endl;
//                cout << "expected : " << pass << endl;
//            }
//            //cout << result << "\n";
//        }
//    }
//
//    fin.close();
//
//    return 0;
//}
/*========================================
 for problem :
 https://www.hackerrank.com/challenges/swap-nodes-algo/problem
 ========================================*/
#include <cstdio>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
int qcounter = 1;
using namespace std;
struct Node{
    Node * left;
    Node * right;
    int value;
    Node(int data){this->left = nullptr; this->right = nullptr; this->value = data;}
};
class BinaryTree{
    Node * head;
    //node pointer array pointing at next possible insertion nodes one level below
    list<Node *> nodeQ;
    
    
public:
    BinaryTree(){
        head = new Node(1);
        nodeQ.push_back(head);
    }
    void insert(vector<int> values){
        int l = values[0];
        int r = values[1];
        Node * temp = nodeQ.front();
        nodeQ.pop_front();
        temp->left = new Node(l);
        temp->right = new Node(r);
        if(l != -1){
            nodeQ.push_back(temp->left);
        }
        if( r != -1){
            nodeQ.push_back(temp->right);
        }
        
    }
    
    Node * getHead(){
        return head;
    }
    
    void swap(int level, Node * parent){
        if (level == 1){
            Node * temp = parent->left;
            parent->left = parent->right;
            parent->right = temp;
        }else{
            if(parent->left)
                swap(level - 1, parent->left);
            if(parent->right)
                swap(level - 1, parent->right);
        }
    }
    
    void inOrder(vector<int>& result, Node * curr){
        if(curr->left && curr->left->value != -1){
            inOrder(result, curr->left);
        }
        if(curr->value != -1){
            result.push_back(curr->value);
        }
        if(curr->right &&curr->right->value != -1){
            inOrder(result, curr->right);
        }
        
    }
    
    int getHeight(Node * curr){
        if (!curr->left && !curr->right)
            return 0;
        else{
            return max(getHeight(curr->left), getHeight(curr->right)) + 1;
        }
        
    }
};
/*
 * Complete the swapNodes function below.
 */
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    /*
     * Write your code here.
     */
    vector<vector<int>> results;
//    for(vector<int> v : indexes){
//        cout << "v[0] : " << v[0] << "\t v[1] : " <<v[1] <<endl;
//    }
    //process vector data to BinaryTree
    BinaryTree * tree = new BinaryTree();
    for(vector<int> v : indexes){
        tree->insert(v);
    }
    
    for(int query : queries){
        //swap as query indicates
        int height = tree->getHeight(tree->getHead());
        cout << qcounter++ << "\tDEBUG: tree height = " << height;
        cout << "\tDEBUG: query level = " << query;
        if(query <= height){
            for(int i = 1; (i * query) < height; i++){
                cout << "\n\tDEBUG: swap at " << query*i <<endl;
                tree->swap(query*i, tree->getHead());
            }
            //inOrder print
            vector<int> result;
            tree->inOrder(result, tree->getHead());
            results.push_back(result);
            //puts("\ninorder\n");
//            for(vector<int> v : results){
//                for(int i: v)
//                    cout<< i << " ";
//                cout <<endl;
//            }
        }
    }
    
    return results;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
    
    ifstream fin ("/Users/kellykim/Documents/hackerrank/hackerrank/hackerrank/input-swap.txt");
    ifstream sol ("/Users/kellykim/Documents/hackerrank/hackerrank/hackerrank/solution-swap.txt");
    
    int n;
    fin >> n;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);
        
        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            fin >> indexes[indexes_row_itr][indexes_column_itr];
        }
        
        fin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    int queries_count;
    fin >> queries_count;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    vector<int> queries(queries_count);
    
    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        fin >> queries_item;
        fin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        queries[queries_itr] = queries_item;
    }
    
    vector<vector<int>> result = swapNodes(indexes, queries);
    int solution;
    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        cout << "[" << result_row_itr << "] ";
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            cout << result[result_row_itr][result_column_itr];
            sol >> solution;
            if(solution != result[result_row_itr][result_column_itr])
                cout << "-FALSE-";
            if (result_column_itr != result[result_row_itr].size() - 1) {
                cout << " ";
            }
        }
        
        if (result_row_itr != result.size() - 1) {
            cout << "\n";
        }
    }
    
    cout << "\n";
    
    //fout.close();
    
    return 0;
}


