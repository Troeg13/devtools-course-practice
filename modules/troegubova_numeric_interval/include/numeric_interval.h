// Copyright 2022 Troegubova Alexandra

#ifndef MODULES_TROEGUBOVA_NUMERIC_INTERVAL_INCLUDE_NUMERIC_INTERVAL_H_
#define MODULES_TROEGUBOVA_NUMERIC_INTERVAL_INCLUDE_NUMERIC_INTERVAL_H_

#include <vector>

class NamericInterval {
 public:
    NamericInterval();
    NamericInterval(int left_border_, int right_border_,
        bool right_include_, bool left_include_);

    std::vector<int> getBorderPoint();
    std::vector<int> getAllIntegerPoint();
    bool containsInterval(const NamericInterval& b);
    bool containsIntegerRange(const std::vector<int>& b);
    bool overlapsRange(const NamericInterval& b);

    bool operator == (const NamericInterval& z) const;
    bool operator != (const NamericInterval& z) const;

 private:
    int left_border;
    int right_border;
    bool left_include;
    bool right_include;
};

#endif  // MODULES_TROEGUBOVA_NUMERIC_INTERVAL_INCLUDE_NUMERIC_INTERVAL_H_
