
    bool isRectangleCover(vector<vector<int>>& val) {
        if (val.size() == 0 || val[0].size() == 0) return false;
        long x1 = INT_MAX, y1 = INT_MAX; 
        long x2 = INT_MIN, y2 = INT_MIN; 
        long long area =0;
        set<pair<int, int>> s;

        for(int i =0 ; i< val.size();i++){
            vector<int> rec = val[i];
            x1 = min((long)x1 , (long)rec[0]);
            y1 = min((long)y1 , (long)rec[1]);
            x2 = max((long)x2 , (long)rec[2]);
            y2 = max((long)y2 , (long)rec[3]);

            long long a = (rec[2] - rec[0]);
            long long b = (rec[3] - rec[1]);
            area += a*b;

            if (s.find({rec[0], rec[1]}) != s.end()) s.erase({rec[0], rec[1]});  // bottom left corner
            else s.insert({rec[0], rec[1]});

            if (s.find({rec[0], rec[3]}) != s.end()) s.erase({rec[0], rec[3]});  // top left corner
            else s.insert({rec[0], rec[3]});

            if (s.find({rec[2], rec[1]}) != s.end()) s.erase({rec[2], rec[1]});  // bottom right corner
            else s.insert({rec[2], rec[1]});

            if (s.find({rec[2], rec[3]}) != s.end()) s.erase({rec[2], rec[3]});  // top right corner
            else s.insert({rec[2], rec[3]});

        } 
        if(s.find({x1,y1}) != s.end() 
        && s.find({x1,y2}) != s.end() 
        && s.find({x2,y1}) != s.end() 
        && s.find({x2,y2})!= s.end() 
        && s.size() == 4 && area == (x2-x1) * (y2-y1)) 
        return true;

        return false;
    }