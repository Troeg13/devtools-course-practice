// Copyright 2022 Troegubova Alexandra

#include "include/numeric_interval.h"

NamericInterval::NamericInterval() : left_border(0), right_border(0),
left_include(true), right_include(true) {}

NamericInterval::NamericInterval(int left_border_,
     int right_border_, bool left_include_, bool right_include_)
    : left_border(left_border_), right_border(right_border_),
    left_include(left_include_), right_include(right_include_) {}

std::vector<int> NamericInterval::getBorderPoint() {
    int beginning = left_include ? left_border : left_border + 1;
    int end = right_include ? right_border : right_border - 1;
    return { beginning, end };
}

std::vector<int> NamericInterval::getAllIntegerPoint() {
    std::vector<int> border = this->getBorderPoint();
    std::vector<int> res;
    for (int i = border[0]; i <= border[1]; i++) {
        res.push_back(i);
    }
    return res;
}

bool NamericInterval::containsInterval(const NamericInterval& b) {
    if (left_border <= b.left_border && right_border >= b.right_border) {
        if ((left_include && !b.left_include && left_border == b.left_border)
            || (right_include && !b.right_include && right_border == b.right_border)) {
            return false;
        }
        return true;
    }
    return false;
}

bool NamericInterval::containsIntegerRange(const std::vector<int>& range) {
    std::vector<int> border = this->getBorderPoint();
    int count_point = range.size();
    for (int i = 0; i < count_point; i++) {
        if (border[0] > range[i] || border[1] < range[i]) {
            return false;
        }
    }
    return true;
}

bool NamericInterval::overlapsRange(const NamericInterval& b) {
    std::vector<int> border_a = this->getBorderPoint();
    std::vector<int> border_b = const_cast<NamericInterval &>(b.getBorderPoint());
    if (border_a[0] > border_b[1] || border_a[1] < border_b[1]) {
        return false;
    }
    return true;
}

bool NamericInterval::operator == (const NamericInterval& b) const {
    bool res = true;
    if (left_border != b.left_border || right_border != b.right_border ||
        left_include != b.left_include || right_include != b.right_include)
        res = false;
    return res;
}


bool NamericInterval::operator != (const NamericInterval& b) const {
    return !(*this == b);
}