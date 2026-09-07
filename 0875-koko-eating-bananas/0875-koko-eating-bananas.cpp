class Solution {
private:
    int findMax(vector<int>& v) {
        int maxi = INT_MIN;

        for (int i : v) {
            maxi = max(maxi, i);
        }

        return maxi;
    }

    long long calculateTotalHours(vector<int>& v, int hourly) {
        long long totalH = 0;

        for (int i : v) {
            totalH += (i + hourly - 1) / hourly;
        }

        return totalH;
    }

    int minimumRateToEatBananas(vector<int> v, int h) {
        int low = 1;
        int high = findMax(v);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalH = calculateTotalHours(v, mid);

            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        return minimumRateToEatBananas(piles, h);
    }
};
