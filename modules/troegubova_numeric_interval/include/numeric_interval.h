// Copyright 2022 Troegubova Alexandra

#ifndef MODULES_NAMERIC_INTERVAL_INCLUDE_NAMERIC_INTERVAL_H_
#define MODULES_NAMERIC_INTERVAL_INCLUDE_NAMERIC_INTERVAL_H_

#include <vector>

class NamericInterval {
public:
    NamericInterval();
    NamericInterval(int left_border_, int right_border_,
        bool right_include_, bool left_include_);

    std::vector<int> getBorderPoint();
    std::vector<int> getAllIntegerPoint();
    bool containsInterval(NamericInterval& b);
    bool containsIntegerRange(const std::vector<int>& b);
    bool overlapsRange(NamericInterval& b);
    
    bool operator == (const NamericInterval& z) const;
    bool operator != (const NamericInterval& z) const;

private:
    int left_border;
    int right_border;
    bool left_include;
    bool right_include;
};

#endif  // MODULES_NAMERIC_INTERVAL_INCLUDE_NAMERIC_INTERVAL_H_