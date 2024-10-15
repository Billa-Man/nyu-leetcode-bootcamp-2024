class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;

        int n = s.length();
        int m = p.length();

        if (m>n) {return ans;}

        map<char, int> hmap;
        for (int i = 0; i < m; i++) {
            hmap[p[i]]++;
        }

        int left_ptr = 0;
        int right_ptr = 0;
        map<char, int> window_map;
        
        while (right_ptr < n) {

            window_map[s[right_ptr]]++;

            if (right_ptr - left_ptr + 1 > m) {
                window_map[s[left_ptr]]--;
                if (window_map[s[left_ptr]] == 0) {
                    window_map.erase(s[left_ptr]);
                }
                left_ptr++;
            }

            if (window_map == hmap) {
                ans.push_back(left_ptr);
            }

            right_ptr++;
        }

        return ans;
    }
};