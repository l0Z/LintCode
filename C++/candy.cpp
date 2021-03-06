// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /**
     * @param ratings Children's ratings
     * @return the minimum candies you must give
     */
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = ratings.size(); i >= 0; --i) {
            if (ratings[i - 1] > ratings[i] && candies[i - 1] <= candies[i]) {
                candies[i - 1] = candies[i] + 1;
            }
        }

        return accumulate(candies.cbegin(), candies.cend(), 0);
    }
};
