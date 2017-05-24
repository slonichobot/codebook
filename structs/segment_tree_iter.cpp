
/// WORK IN PROGRESS!!!

// Segment tree
// - efficient and succinct
// - values are stored on positions <n, 2n)
// - ! Works only for commutative (a+b = b+a) operations

template<class T, int N>
struct SegmentTree {
    SegmentTree(int n): n(n) {
        for (int i = n - 1; i > 0; --i) t[i] = mrg(t[i<<1], t[i<<1|1]);
    }
    void modify(int p, int value) {  // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
    }
    int query(int l, int r) {  // aggregate on interval [l, r)
        T res = initial;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = mrg(res, t[l++]);
            if (r&1) res = mrg(res, t[--r]);
        }
        return res;
    }
    T * array() { return t+n; }
    int n;
    T t[2 * N];
    T initial = INF;
    function<T(T,T)> mrg = [](T a,T b){return max(a,b);};
};

struct IntervalTree {
    
}

int main(void) {
    ios_base::sync_with_stdio(false);

    return 0;
}
