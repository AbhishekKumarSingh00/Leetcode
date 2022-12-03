class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<int, int> mp;
        for(auto c : s) {
            mp[c]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto e : mp)
            pq.push({e.second, e.first});
        
        string ans = "";
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            
            for(int i = 0; i < t.first; i++) {
                ans += t.second;
            }
        }
        return ans;
        
    }
};