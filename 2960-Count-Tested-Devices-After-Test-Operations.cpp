class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int tested = 0;
        for (auto& x : batteryPercentages) {
            x -= tested;
            if (x > 0)
                tested++;
        }
        return tested;
    }
};