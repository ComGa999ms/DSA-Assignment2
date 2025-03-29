# DSA Advance-Assignment2
Họ và tên: Nguyễn Đăng Khoa

Lớp: ATTN2024

MSSV: 24520825
## MaxMinSum
Bài này không quan tâm đến vị trí nên chúng ta sẽ sort lại các món quà và ta sẽ giải bài toán bằng cách chia ra 2 phần $\sum max - \sum min$.

Khi sort lại thì tại vị trí i:
- Số lần nhận $a_i$ làm $max$ là $C(i - 1, k - 1)$ chọn $k - 1$ phần tử trước $i$.
- Số lần nhận $a_i$ làm $min$ là $C(n - i, k - 1)$ chọn $k - 1$ phần tử sau $i$.
```C++
for (int i = 1; i <= n; ++i) {
    int l = i - 1, r = n - i;

    if (l >= k - 1) {
        res = (res + a[i] * C(l, k - 1)) % mod;
    }

    if (r >= k - 1) {
        res = (res - a[i] * C(r, k - 1)) % mod;
    }
}
```
## 	khangtd.Login1
Bài này đơn giản là dùng 
```map <string, string>``` xong check xem nó có trong map hay chưa.
## 	khangtd.Login2
Tương tự bài trên chỉ khác là lần này dùng ```map <string, vector <string>>```
## khangtd.DetectVirus
Bài này do xâu $S, T$ có độ dài khá nhỏ $|S|, |T| \leq 1000$ nên brute là được.
## khangtd.DetectVirus2
Khác với bài trên ở bài này $|S|, |T| \leq 10^6$ nên chúng ta phải dùng [Hash](https://wiki.vnoi.info/algo/string/hash).
## Linear Search 4
Ở bài toán này chúng ta chỉ cần quan tâm:
- $s1$: số môn học có ít nhất 1 người giỏi
- $s2$: số môn học có ít nhất 2 người giỏi

Lúc này sẽ chia được 2 đội thỏa mãn khi và chỉ khi:
- $s1 \leq 2k$  
- $k \leq s1 + s2$ 
## Vượt mức Pickleball v2 (time limit: 0.5s)
Dùng mảng ```cnt``` duy trì tần xuất giá trị xuất hiện trong đoạn có độ dài là $d$. 

Còn cách lấy trung vị thì ở đây do $a_i \leq 200$ nên để lấy trung vị đơn giản là duyệt hết các giá trị đó và đáp án là giá trị nhỏ thứ $x$. 

```C++
int get(int x) {
    int total = 0;
    for (int i = 0; i <= 200; ++i) {
        total += cnt[i];
        if (total >= x) return i;
    }
    return -1;
}
```
## Bốn ông điên	
Bài này đề bảo là sao cho mảng có trật tự tức có nghĩa là tăng dần hoặc giảm dần đều được.

Bài này thì tham lam, ban đầu chúng ta sẽ sort và lưu lại các vị trí đúng của mảng vào mảng ```TruePos``` sau đó thì chỉ cần swap cho đến khi mảng đã được sắp xếp.
```C++
for (int i = 1; i <= n; ++i) {
    while (TruePos[b[i]] != i) {
        ++res;
        swap(b[i], b[TruePos[b[i]]]);
    }
}
```
## Huấn luyện chuột	
Đếm số dãy không giảm độ dài $N$. Từ các số từ $1$ đến $N$ sao cho mỗi dãy là duy nhất.

Dễ dàng thấy đây là một bài toán chia kẹo euler như sau, ta có:
- $x_1 + x_2 + x_3 + .... + x_n = N$
- $0 \leq x_i \leq N$ (mỗi số $i$ có tối đa $N$ số).

Thì đáp án của bài toán sẽ là nghiệm không âm của phương trình trên 
$$
\binom{N + N - 1}{N} = \binom{2N - 1}{N}
$$
Nhưng ở đây vấn đề là đề cho $a_i \leq 10^{10}$ nên chúng ta phải dùng định lí [Lucas](https://wiki.vnoi.info/translate/he/Lucas-theorem) để tính.
```C++
// Biểu diễn số N dưới dạng cơ số MOD
vector<int> getRepresentation(int N) {
    vector<int> res;
    while (N > 0) {
        res.push_back(N % MOD);
        N /= MOD;
    }
    return res;
}

int res = 1;
vector <int> ni = getRepresentation(2 * x - 1);
vector <int> ki = getRepresentation(x);

for (int i = 0; i < (int)ki.size(); ++i) res = (res * C(ni[i], ki[i])) % MOD;
cout << res;
```
