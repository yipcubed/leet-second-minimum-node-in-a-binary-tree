#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

// #include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    void DFS(TreeNode *r, int& smallest, int rootValue) {
        if (!r) return;
        if (r->val > rootValue) {
            // candidate
            if (rootValue == smallest)
                smallest = r->val;
            else if (r->val < smallest)
                smallest = r->val;
        }
        DFS(r->left, smallest, rootValue);
        DFS(r->right, smallest, rootValue);
    }
    int findSecondMinimumValue(TreeNode *root) {
        if (!root) return -1;
        int smallest = root->val;
        DFS(root, smallest, root->val);
        return smallest == root->val ? -1 : smallest;
    }
};

void test1() {
    vector<int> v1{2, 2, 5, -1, -1, 5, 7};
    auto t1 = new TreeNode(v1, -1);

    cout << "5 ? " << Solution().findSecondMinimumValue(t1) << endl;

    vector<int> v2{2, 2, 2};
    auto t2 = new TreeNode(v2);
    cout << "-1 ? " << Solution().findSecondMinimumValue(t2) << endl;

    vector<int> v3{5, 8, 5};
    auto t3 = new TreeNode(v3);
    cout << "8 ? " << Solution().findSecondMinimumValue(t3) << endl;

    // [1,1,3,1,1,3,4,3,1,1,1,3,8,4,8,3,3,1,6,2,1]
    vector<int> v4{1,1,3,1,1,3,4,3,1,1,1,3,8,4,8,3,3,1,6,2,1};
    auto t4 = new TreeNode(v4);
    / cout << t4 << endl;
    cout << "2 ? " << Solution().findSecondMinimumValue(t4) << endl;

}

void test2() {

}

void test3() {

}