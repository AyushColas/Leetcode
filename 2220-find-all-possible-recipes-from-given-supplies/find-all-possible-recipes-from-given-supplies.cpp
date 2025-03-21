class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    unordered_set<string> supplySet(supplies.begin(), supplies.end());
    unordered_map<string, vector<string>> graph; 
    unordered_map<string, int> inDegree; 

    
    for (string& recipe : recipes) {
        inDegree[recipe] = 0;
    }

    
    for (int i = 0; i < recipes.size(); i++) {
        for (string& ing : ingredients[i]) {
            if (supplySet.count(ing) == 0) {
                graph[ing].push_back(recipes[i]);
                inDegree[recipes[i]]++;
            }
        }
    }

    queue<string> q;
    vector<string> result;

    for (string& recipe : recipes) {
        if (inDegree[recipe] == 0) {
            q.push(recipe);
        }
    }

    while (!q.empty()) {
        string recipe = q.front();
        q.pop();
        result.push_back(recipe);

        for (string& dependent : graph[recipe]) {
            inDegree[dependent]--;
            if (inDegree[dependent] == 0) {
                q.push(dependent);
            }
        }
    }

    return result;  
    
    }
};