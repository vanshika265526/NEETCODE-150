class CountSquares {
public:
    
    // stores frequency of each point
    map<pair<int,int>, int> mp;

    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        
        int x = point[0];
        int y = point[1];
        
        int ans = 0;
        
        // iterate over all stored points
        for(auto &p : mp) {
            
            int x1 = p.first.first;
            int y1 = p.first.second;
            int freq = p.second;
            
            // diagonal condition for square
            if(abs(x - x1) != abs(y - y1) || x == x1 || y == y1)
                continue;
            
            // remaining two corners
            ans += freq * mp[{x, y1}] * mp[{x1, y}];
        }
        
        return ans;
    }
};
