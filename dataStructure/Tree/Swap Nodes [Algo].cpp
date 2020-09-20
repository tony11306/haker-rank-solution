// problem source: https://www.hackerrank.com/challenges/swap-nodes-algo/problem

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the swapNodes function below.
 */

class treeNode{
    public:
        treeNode* left = nullptr;
        treeNode* right = nullptr;
        int data;
        int depth;
    treeNode(int da, int dep){
        data = da;
        depth = dep;
    }
    
};

vector<vector<treeNode*>> bfsInsert(vector<vector<int>> indexes, treeNode* root){
    vector< vector<treeNode*> > arrs;
    arrs.resize(1);
    queue<treeNode*> que;
    que.push(root);
    int i = 0;
    arrs[0].push_back(root);
    while(!que.empty()){
        if(indexes[i][0] != -1){
            treeNode* newLeftNode = new treeNode(indexes[i][0], que.front()->depth + 1);
            que.front()->left = newLeftNode;
            que.push(newLeftNode);
            if(newLeftNode->depth > arrs.size()){
                arrs.resize(newLeftNode->depth);
                arrs[newLeftNode->depth - 1].push_back(newLeftNode);
            }else{
                arrs[newLeftNode->depth - 1].push_back(newLeftNode);
            }

        }
        if(indexes[i][1] != -1){
            treeNode* newRightNode = new treeNode(indexes[i][1], que.front()->depth + 1);
            que.front()->right = newRightNode;
            que.push(newRightNode);
            if(newRightNode->depth > arrs.size()){
                arrs.resize(newRightNode->depth);
                arrs[newRightNode->depth - 1].push_back(newRightNode);
            }else{
                arrs[newRightNode->depth - 1].push_back(newRightNode);
            }
        }
        i++;
        que.pop();
    }
    return arrs;
}

vector<int> inOrder(treeNode* root, vector<int> result){
    if(root == nullptr){
        return result;
    }
    result = inOrder(root->left, result);
    result.push_back(root->data);
    result = inOrder(root->right, result);
    return result;
    
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    /*
     * Write your code here.
     */
    treeNode* root = new treeNode(1, 1);

    // 把樹轉成二維陣列，縱軸為樹的深度，橫軸為此深度的所有node
    vector< vector<treeNode*> > depthArrs = bfsInsert(indexes, root);

    treeNode* temp = root;
    vector<vector<int>> result(queries.size());
    for(int i = 0; i < queries.size(); ++i){
        for(int j = queries[i], l = 1; j <= depthArrs.size(); l++, j = queries[i] * l ){
            for(int k = 0; k < depthArrs[j-1].size(); ++k){
                temp = depthArrs[j-1][k]->left;
                depthArrs[j-1][k]->left = depthArrs[j-1][k]->right;
                depthArrs[j-1][k]->right = temp;
            }
        }
        result[i] = inOrder(root, result[i]);
    }

    
    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
