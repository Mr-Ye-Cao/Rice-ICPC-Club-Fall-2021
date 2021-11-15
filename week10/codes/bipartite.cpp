// This problem is orginially from Leetcode Difficulty level: medium
//https://leetcode.com/problems/is-graph-bipartite/submissions/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // create an array representing the visiting condition of 
        // all of the nodes
        int color[graph.size()];
        
        // initially, all of the nodes are not visited, so set them to 0
        for(int idx = 0 ; idx < graph.size() ; idx ++){
            color[idx] = 0;
        }

        // then start visiting the nodes
        queue<int> visits;
        // check if all components are visited
        bool isComplete;
        do{
            // by default, assume that all nodes are visited
            isComplete = true;
            // check if there is any node that has not been visited
            for(int idx = 0 ; idx < graph.size() ; idx++){
                // if not visited
                if(color[idx] == 0){
                    // set flag to not visited
                    isComplete = false;
                    // push the node for visit
                    visits.push(idx);
                    // mark as 1 / blue
                    color[idx] = 1;
                    break;
                }
            }
            // do a breath first search here
            while(!visits.empty()){
                // the parent node
                int node = visits.front();
                visits.pop();
                // access the color
                int pcolor = color[node];
                // for all children of the parent
                for(int neighbor: graph[node]){
                    // if not visited before set as the opposite color
                    if(color[neighbor] == 0){
                        color[neighbor] = -1 * pcolor;
                        visits.push(neighbor);
                    // if already visited & same color as parent
                    }else if(color[neighbor] == pcolor){
                        // return false
                        return false;
                    }
                }
            }
        }while(!isComplete);
            
        return true;
    }
};