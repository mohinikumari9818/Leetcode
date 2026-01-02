class Solution {
private:
    // primes numbers for multiplication
    const int p = 31;
    const int p1 = 37;

    // large prime numbers for modulus
    const int m = 1e9 + 9;
    const int m1 = 1e9 + 7;

public:
    string longestDupSubstring(string s) {
        int n = s.size();
        vector<long long> p_pow(n), p_pow1(n), h(n+1), h1(n+1);
        p_pow[0] = p_pow1[0] = 1;

        // pre computing powers of `p`
        for (int i=1; i<n; i++) {
            p_pow[i] = (p_pow[i-1] * p) % m;
            p_pow1[i] = (p_pow1[i-1] * p1) % m1;
        }

        // pre computing hash values of all prefixes
        for (int i=1; i<=n; i++) {
            h[i] = (h[i-1] + (s[i-1] - 'a' + 1) * p_pow[i-1]) % m;
            h1[i] = (h1[i-1] + (s[i-1] - 'a' + 1) * p_pow1[i-1]) % m1;
        }

        unordered_map<long long, long long> st;
        bool found = false;

        int lo=0, hi=n-1, mid;
        string ans="";

        while (lo <= hi) {
            mid = lo + (hi - lo)/2;

            for (int i=0; i+mid<=n; i++) {
                long long cur_h = (h[mid+i] - h[i] + m) % m;
                long long cur_h1 = (h1[mid+i] - h1[i] + m1) % m1;
                
                // for prefix starting at index `i`, coefficient is p^i.
                // Multiplying it with p^(n-i-1) makes it p^(i + n - i - 1) = p^(n-1)
                // This is done so two identical substrings starting at different index have the same hash value for comparison.
                cur_h = (cur_h * p_pow[n - i - 1]) % m;
                cur_h1 = (cur_h1 * p_pow1[n - i - 1]) % m1;

                if (st.find(cur_h) != st.end() && st[cur_h] == cur_h1) {
                    found = true;
                    ans = s.substr(i, mid);
                    break;
                } else {
                    st.insert({cur_h, cur_h1});
                }
            }

            if (found) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }

            st.clear();
            found = false;
        }

        return ans;
    }
};