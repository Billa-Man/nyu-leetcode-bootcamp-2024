class Solution {
public:
    string reverseWords(string s) {

        int n = s.length();

        int write_ptr = 0;
        int space_flag = 1;

        for(int read_ptr=0; read_ptr<n; read_ptr++){
            if(s[read_ptr] != ' '){
                s[write_ptr] = s[read_ptr];
                write_ptr++;
                space_flag = 0;
            }
            else if(s[read_ptr] == ' ' && !space_flag){
                s[write_ptr] = s[read_ptr];
                write_ptr++;
                space_flag = 1;
            }
        }

        if(write_ptr > 0 && s[write_ptr - 1] == ' '){write_ptr--;}
        s.resize(write_ptr);

        reverse(s.begin(), s.end());

        int start_ptr = 0;

        for(int i=0; i<s.length(); i++){
            if(s[i] == ' '){
                reverse(s.begin()+start_ptr, s.begin()+i);
                start_ptr=i+1;
            }
        }

        reverse(s.begin()+start_ptr, s.end());

        return s;
    }
};