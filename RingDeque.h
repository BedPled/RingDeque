//
// Created by BedTed on 4/5/2021.
//

#ifndef RINGDEQUE_RINGDEQUE_H
#define RINGDEQUE_RINGDEQUE_H


// ЗАЗОР В 1 ЭЛЕМЕНТ

class RingDeque {
private:
int deque_size_;
int *deque_;
int left_pointer_ = 0;  // |L|_|...|_|
int right_pointer_ = 1; // |_|R|...|_|

// |_|_|R|L|_|_|_| - пустая
// |_|_|_|R L|_|_|_| - полная

public:
    RingDeque (int deque_size_);
    RingDeque (const RingDeque &deque);
    ~RingDeque ();
    bool full ();
    bool empty ();
    int len ();
    int pushBack(int data);
    int pushFront(int data);
    int popBack();
    int popFront();
    void popAll ();
    void printDeque ();

    RingDeque &operator= (RingDeque &deque /* то, что присваиваем */){
        /* this это то, чему присваиваем */
        int j = 0;

        if (deque.deque_size_ > this->deque_size_) {
            // обрубаем то что не влезло
            if (deque.left_pointer_ < deque.right_pointer_) {
                for (int i = deque.left_pointer_ + 1; i < deque.right_pointer_; ++i) {
                    this->deque_[j] = deque.deque_[i];
                    j++;
                    if (j > this->deque_size_) {
                        this->left_pointer_ = this->deque_size_;
                        this->right_pointer_ = this->deque_size_;
                        return *this;
                    }
                }
                this->left_pointer_ = this->deque_size_;
                this->right_pointer_ = j;
            } if (deque.left_pointer_ >= deque.right_pointer_) {
                for (int i = deque.left_pointer_ + 1; i <= deque.deque_size_; ++i) {
                    this->deque_[j] = deque.deque_[i];
                    j++;
                    if (j > this->deque_size_) {
                        this->left_pointer_ = this->deque_size_;
                        this->right_pointer_ = this->deque_size_;
                        return *this;
                    }
                }

                for (int i = 0; i < deque.right_pointer_; ++i) {
                    this->deque_[j] = deque.deque_[i];
                    j++;
                    if (j > this->deque_size_) {
                        this->left_pointer_ = this->deque_size_;
                        this->right_pointer_ = this->deque_size_;
                        return *this;
                    }
                }
                this->left_pointer_ = this->deque_size_;
                this->right_pointer_ = j;
            }
        } else if (deque.deque_size_ < this->deque_size_) {
            // переписываем что есть
            if (deque.left_pointer_ < deque.right_pointer_) {
                for (int i = deque.left_pointer_ + 1; i < deque.right_pointer_; ++i) {
                    this->deque_[j] = deque.deque_[i];
                    j++;
                }
                this->left_pointer_ = this->deque_size_;
                this->right_pointer_ = j;
            } if (deque.left_pointer_ >= deque.right_pointer_) {
                for (int i = deque.left_pointer_ + 1; i <= deque.deque_size_; ++i) {
                    this->deque_[j] = deque.deque_[i];
                    j++;
                }

                for (int i = 0; i < deque.right_pointer_; ++i) {
                    this->deque_[j] = deque.deque_[i];
                    j++;
                }
                this->left_pointer_ = this->deque_size_;
                this->right_pointer_ = j;
            }

        } else {
            // равно
            for (int i = 0; i < deque_size_; ++i) {
                this->deque_[i] = deque.deque_[i];
            }
            this->left_pointer_ = deque.left_pointer_;
            this->right_pointer_ = deque.right_pointer_;
        }

        return *this;
    };

    friend std::ostream& operator<< (std::ostream &out, RingDeque &deque) {
        if (deque.empty()){
            out << "empty";
        } else if (deque.right_pointer_ > deque.left_pointer_) {
            for (int i = deque.left_pointer_ + 1; i < deque.right_pointer_; ++i) {
                out << deque.deque_[i] << " ";
            }
        } else {
            for (int i = deque.left_pointer_ + 1; i <= deque.deque_size_; ++i) {
                out << deque.deque_[i] << " ";
            }

            for (int i = 0; i < deque.right_pointer_; ++i) {
                out << deque.deque_[i] << " ";
            }
        }
    }
};


#endif //RINGDEQUE_RINGDEQUE_H
