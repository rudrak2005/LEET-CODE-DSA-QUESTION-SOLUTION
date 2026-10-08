class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
  vector<int> ans;
  int n = s.size();
  int m = p.size();
  if(m>n){
    return ans;
  }      
vector<int> need(26, 0);
vector<int> window(26, 0);

for(char c : p){
    need[c-'a']++;
}

for(int i =0; i<m; i++){
    window[s[i]-'a']++;
}
if(window == need){
    ans.push_back(0);
}
for(int right = m; right < n; right++){
    window[s[right]- 'a']++;

    window[s[right -m]- 'a']--;

    if(window == need ){
        ans.push_back(right - m+1);
    }
}
return ans;


    }
};