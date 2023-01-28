#include <iostream>
#include <vector>
#include <map>

class SummaryRanges {
public:
    std::vector<std::vector<int>> *intervals;
    std::map<int, std::vector<int>*> hash;

    SummaryRanges() {
        intervals = new std::vector<std::vector<int>>;
    }
    
    void addNum(int value) {
        if(inHash(value) == 0) {
            // LRHS both in hash
            if(inHash(value-1) == 1 && inHash(value+1) == 1) {
                // merge
                hash[value-1]->pop_back();
                hash[value-1]->push_back(hash[value+1]->back());
                delete hash[value+1];
                for(int i = value; i <= hash[value-1]->back(); i++) {
                    hash[i] = hash[value-1];
                }
            }
            // LHS in hash
            else if(inHash(value-1) == 1) {
                // Become RHS
                hash[value-1]->pop_back();
                hash[value-1]->push_back(value);
                hash[value] = hash[value-1];
            }
            else if(inHash(value+1) == 1) {
                // Become LHS
                (*(hash[value+1]))[0] = value;
                hash[value] = hash[value+1];
            }
            else {
                // Add interval with self as LHS and RHS
                hash[value] = new std::vector<int>;
                hash[value]->push_back(value);
                hash[value]->push_back(value);
            }
        }
    }

    int inHash(int value) {
        // Return 0 if not exist
        // Return 1 if exist
        if(hash.find(value) == hash.end()) {
            return 0;
        }
        else {
            return 1;
        }
    }
    
    std::vector<std::vector<int>> getIntervals() {
        intervals->clear();
        for(auto i = hash.begin(); i != hash.end(); i++) {
            intervals->push_back(*(hash[i->first]));
            // Skips over rest of interval
            std::advance(i, i->second->back() - i->second->front());
        }
        return *intervals;
    }
};

int main() {
    SummaryRanges* obj = new SummaryRanges();
    obj->addNum(1);
    std::vector<std::vector<int>> param_2 = obj->getIntervals();


    return 0;
}