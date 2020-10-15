// Problem - 547. Friend Circles

/*  
    There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature.
    For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend
    circle is a group of students who are direct or indirect friends.
    
    Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, 
    then the ith and jth students are direct friends with each other, otherwise not.
    And you have to output the total number of friend circles among all the students.

Approach : 
    We will do this problem using DFS. So we will have a vector containing the visited friends
    with the variable name visited, it will initially contain all 0s and have a size of M.

    When we iterate through M, we check if we have visited that friend yet. If we have not, then we perform
    DFS on that friend and mark all of its friend as visited as well. If we have, then we continue iterating.

    Finally we will be able to find out how many friend circles are available in the matrix M.
*/

class Solution {
   public:
    void dfs(vector<vector<int>> &M, vector<int> &visited, int currentFriend) {
        for (int i = 0; i < M.size(); i++) {
            if (M[i][currentFriend] == 1 && visited[i] == 0) {
                visited[i] = 1;
                dfs(M, visited, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &M) {
        vector<int> visited(M.size(), 0);
        int totalGroup = 0;
        for (int i = 0; i < M.size(); i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                totalGroup++;
                dfs(M, visited, i);
            }
        }
        return totalGroup;
    }
};
