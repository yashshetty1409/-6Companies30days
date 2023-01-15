class StockPrice {
    unordered_map<int,int> prices;
    multiset<int> ms;
    int maxTimestamp = -1;
public:
    StockPrice() { }
    
    void update(int timestamp, int price) {
        if (prices.find(timestamp) != prices.end()) {
            ms.erase(ms.find(prices[timestamp]));
        }
        prices[timestamp] = price;
        ms.insert(price);
        
        maxTimestamp = max(maxTimestamp, timestamp);
    }
    
    int current() {
        return prices[maxTimestamp];
    }
    
    int maximum() {
        return *ms.rbegin();
    }
    
    int minimum() {
        return *ms.begin();
    }
};