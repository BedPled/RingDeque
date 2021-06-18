//
// Created by BedTed on 4/5/2021.
//
#include <iostream>
#include "RingDeque.h"
#include <limits.h>

RingDeque::RingDeque (int deque_size_) {
    this->deque_size_ = deque_size_;
    deque_ = new int[deque_size_ + 1];
};

RingDeque::RingDeque(const RingDeque &deque) {
    deque_size_ = deque.deque_size_;
    deque_ = new int[deque_size_ + 1];

    for (int i = 0; i <= deque_size_; ++i) {
        deque_[i] = deque.deque_[i];
    }
    left_pointer_ = deque.left_pointer_;
    right_pointer_ = deque.right_pointer_;
};

RingDeque::~RingDeque (){
    delete[] deque_;
};

bool RingDeque::full () {
    if (left_pointer_ == right_pointer_) return true;
    return false;
};

bool RingDeque::empty () {
    if (left_pointer_ + 1 == right_pointer_ || (left_pointer_ - deque_size_ == 0) && right_pointer_ == 0) return true;
    return false;
};

int RingDeque::len () {
    if (full()) {
        return deque_size_;
    }
    if (empty()) {
        return 0;
    }
    if (right_pointer_ > left_pointer_) {
        return right_pointer_ - left_pointer_ - 1;
    } else {
        return deque_size_ + right_pointer_ - left_pointer_;
    }
};

int RingDeque::pushBack(int data) {
    if (!full()){
        deque_[right_pointer_] = data;
        right_pointer_++;
        if (right_pointer_ == deque_size_ + 1) {
            right_pointer_ = 0;
        }
        return 1;
    }
    return 0;
};

int RingDeque::pushFront(int data) {
    if (!full()){
        deque_[left_pointer_] = data;
        left_pointer_--;

        if (left_pointer_ == -1) {
            left_pointer_ = deque_size_;
        }
        return 1;
    }
    return 0;
};

int RingDeque::popBack() {
    if (!empty()) {
        right_pointer_--;

        if (right_pointer_ == -1) {
            right_pointer_ = deque_size_;
        }
        return deque_[right_pointer_];
    }
    return INT_MIN;
};

int RingDeque::popFront() {
    if (!empty()) {
        left_pointer_++;
        if (left_pointer_ == deque_size_ + 1) {
            left_pointer_ = 0;
        }
        return deque_[left_pointer_];
    }
    return INT_MIN;
};

void RingDeque::popAll () {
    left_pointer_ = 0;  // |L|_|...|_|
    right_pointer_ = 1; // |_|R|...|_|
};

void RingDeque::printDeque () {
    if (empty()){
        std::cout << "empty";
    } else if (right_pointer_ > left_pointer_) {
        for (int i = left_pointer_ + 1; i < right_pointer_; ++i) {
            std::cout << deque_[i] << " ";
        }
    } else {
        for (int i = left_pointer_ + 1; i <= deque_size_; ++i) {
            std::cout << deque_[i] << " ";
        }

        for (int i = 0; i < right_pointer_; ++i) {
            std::cout << deque_[i] << " ";
        }
    }
};

