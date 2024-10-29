#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<queue>
using namespace std;
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) {
        return { 0 };
    }
    vector<vector<int>>g(n);
    vector<int>degree(n);
    vector<int>res;
    for (auto& i : edges) {
        int a = i[0], b = i[1];
        degree[a]++;
        degree[b]++;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int>q;
    for (int i = 0; i < n; i++) {
        if (degree[i] == 1)q.push(i);
    }
    while (!q.empty()) {
        res.clear();
        for (int i = q.size(); i > 0; i--) {
            int a = q.front();
            q.pop();
            res.push_back(a);
            for (int b : g[a]) {
                if (--degree[b] == 1)
                    q.push(b);
            }
        }
    }
    return res;
}
int main() {
    int n = 4;
    vector<vector<int>>edges{ {1,0},{1,2},{1,3} };
    vector<int>res=findMinHeightTrees(n, edges);
}
//class NumArray {
//public:
//    vector<int>arr;
//    vector<int>sum;
//    NumArray(vector<int>& nums) {
//        arr.resize(nums.size());
//        sum.resize(nums.size());
//        int n = nums.size();
//        sum[0] = nums[0];
//        for (int i = 0; i < nums.size() - 1; i++)
//        {
//            arr[i] = nums[i];
//            sum[i + 1] = sum[i] + nums[i + 1];
//        }
//        arr[n - 1] = nums.back();
//    }
//
//    void update(int index, int val) {
//        if (index >= arr.size())return;
//        int temp = arr[index];
//        arr[index] = val;
//        for (int i = index; i < sum.size(); i++) {
//            sum[i] -= (temp - arr[index]);
//        }
//    }
//
//    int sumRange(int left, int right) {
//        if (left < 0 || right >= arr.size())return 0;
//        return sum[right] - (left == 0 ? 0 : sum[left - 1]);
//        //return accumulate(arr.begin() + left, arr.begin() + right + 1, 0);
//    }
//};
//class Solution {
//public:
//    bool isAdditiveNumber(string num) {
//        int i = 0;
//        for (int j = i + 1; j <= num.size() - 1; j++) {
//            for (int k = j + 1; k <= num.size() - 1; k++) {
//                if (dfs(num, i, j, k)) return true;
//            }
//        }
//        return false;
//    }
//
//    bool dfs(string& s, int i, int j, int k) {
//        if ((s[i] == '0' && j - i > 1) || (s[j] == '0' && k - j > 1)) return false;
//        string a = s.substr(i, j - i);
//        string b = s.substr(j, k - j);
//        string sum = add(a, b);
//        int n = sum.size();
//        if (k + n - 1 > s.size() - 1 || sum != s.substr(k, n)) return false;
//        if (k + n - 1 == s.size() - 1) return true;
//        return dfs(s, j, k, k + n);
//    }
//
//    string add(string& a, string& b) {
//        int n1 = a.size() - 1;
//        int n2 = b.size() - 1;
//        int carry = 0;
//        string ans;
//        while (n1 >= 0 || n2 >= 0 || carry > 0) {
//            int t1 = n1 >= 0 ? a[n1--] - '0' : 0;
//            int t2 = n2 >= 0 ? b[n2--] - '0' : 0;
//            ans += (t1 + t2 + carry) % 10 + '0';
//            carry = (t1 + t2 + carry) >= 10 ? 1 : 0;
//        }
//        reverse(ans.begin(), ans.end());
//        return ans;
//    }
//};
//class Solution {
//public:
//    bool dfs(string num, int a, int b, int c) {
//        if ((num[a] =='0' && b - a > 1) || (num[b] =='0' && c - b > 1))return false;
//        string s1(num.begin() + a, num.begin() + b);
//        string s2(num.begin() + b, num.begin() + c);
//        long long num1 = stoll(s1);
//        long long num2 = stoll(s2);
//        long long num3 = num1 + num2;
//        int n = to_string(num3).length();
//        if (c + n > num.length() || stoi(num.substr(c, n)) != num3)return false;
//        if (c + n == num.length())return true;
//        return dfs(num, b, c, c + n);
//    }
//    bool isAdditiveNumber(string num) {
//        int a = 0, n = num.length();
//        for (int b = a + 1; b < n/2; b++) {
//            for (int c = b + 1; c < n; c++) {
//                
//                if (dfs(num, a, b, c))return true;
//            }
//        }
//        return false;
//    }
//};