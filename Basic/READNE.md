# DSA Basic-Assignment2
Họ và tên: Nguyễn Đăng Khoa

Lớp: ATTN2024

MSSV: 24520825
## Task
Ở bài này thì đơn giản là xác định vị trí của Alice trên bảng thì lúc này việc trùng đề chỉ đơn giản là lấy vị trí của Alice $+- k$
## Point3D
Bài này thì viết một hàm comprare theo yêu cầu đề bài 
```C++
bool compare(points a, points b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }
    if (a.y != b.y) {
        return a.y > b.y;
    }
    return a.z < b.z;
}
```
## an.512.Trộn 2 mảng	
Dùng 2 con trỏ merge 2 mảng lại với nhau.
## Find MEX	
Ở bài này có thể thấy MEX cho dãy có $n$ phần tử thì đáp án sẽ nằm từ đoạn $[0, n]$ nên nếu $a_i > n$ thì bỏ qua. 
## Point2D (template)	
Bài này tương tự bài Point3D
```C++
bool compare(points a, points b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }
    if (a.y != b.y) {
        return a.y > b.y;
    }
}
```
## VU33_MaxStr	
Gọi $r$ là số dư của xâu s mod 3. Lúc này có 2 trường hợp:
- Xóa 1 số với số dư mod 3 đúng bằng $r $ 
- Xóa 2 số với số dư mod 3 đúng bằng $3 - r$
## VQ44_FLOWERS(template)	
Dùng MergeSort sắp xếp lại mảng xong tạo một vector chứa số đèn khác nhau và tấn số xuất hiện. Phần còn lại làm tương tự bài VQ44_FLOWERS ở assignment1.
```C++
void build_unique(void) {
    if (n == 0) return;
    int col = a[1];
    int cnt = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] == col) {
            ++cnt;
        } else {
            ds.push_back(make_pair(col, cnt));
            col = a[i];
            cnt = 1;
        }
    }
    ds.push_back(make_pair(col, cnt));
}
```
## Kiểm Kê	
Bài này đơn giản là dùng MergeSort sắp xếp xong sau đó so sánh 2 phần tử kề nhau để đếm số phần tử phân biệt.
## MergeSort	
Bài này thuật toán MergeSort 
```C++
void merge(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];

    for (i = left; i <= right; ++i) a[i] = temp[i];

    for (int p = 1; p <= n; ++p) {
        if (p > 1) cout << " ";
        if (p == left) cout << "[ ";
        cout << a[p];
        if (p == right) cout << " ]";
    }
    cout << '\n';
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) >> 1;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}
```
## InsertionSort	
Bài này thuật toán InsertionSort 
```C++
void merge(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];
    for (i = left; i <= right; ++i) a[i] = temp[i];
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) >> 1;
        mergeSort(left, mid);
        for (int k = 1; k <= n; ++k) cout << a[k] << ' '; cout << '\n';
        mergeSort(mid + 1, right);
        for (int k = 1; k <= n; ++k) cout << a[k] << ' '; cout << '\n';

        merge(left, mid, right);
        for (int k = 1; k <= n; ++k) cout << a[k] << ' '; cout << '\n';
    }
}
```
## BubbleSort	
Bài này thuật toán BubbleSort 
```C++
for (int i = 1; i < n; ++i) {
    bool swaped = 0;
    for (int j = 1; j <= n - i; ++j) {
        if (a[j] > a[j + 1]) {
            swap(a[j], a[j + 1]);
            for (int k = 1; k <= n; ++k) cout << a[k] << ' '; cout << '\n';
            swaped = 1;
        }
    }
    if (!swaped) break;
}
```
## SelectionSort	
Bài này thuật toán SelectionSort
```C++
for (int i = 1; i < n; ++i) {
    int minIndex = i;
    for (int j = i + 1; j <= n; ++j) {
        if (a[j] < a[minIndex]) {
            minIndex = j;
        }
    }
    swap(a[i], a[minIndex]);

    if (i != minIndex)
    for (int k = 1; k <= n; ++k) cout << a[k] << ' '; cout << '\n';
}
```