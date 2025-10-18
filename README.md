# Dự án Mã hóa RC4

Dự án này bao gồm code C++ để minh họa thuật toán mã hóa dòng RC4.

## Cấu trúc file

* `rc4_library.h`: Thư viện (header) chứa logic thuật toán RC4.
* `encrypt_app.cpp`: Chương trình chính để mã hóa.
* `decrypt_app.cpp`: Chương trình chính để giải mã.
* `.gitignore`: Chỉ định Git bỏ qua các file thực thi.

## Yêu cầu

Một trình biên dịch C++ (ví dụ: g++ trong MinGW, hoặc trình biên dịch của Visual Studio).

## Hướng dẫn chạy chương trình

Mở Command Prompt (cmd) hoặc PowerShell tại thư mục gốc của dự án.

### 1. Biên dịch và chạy Chương trình Mã hóa

**Biên dịch (với MinGW/g++):**
```bash
g++ encrypt_app.cpp -o encrypt_app.exe -std=c++11
```

**Chạy:**
```bash
.\encrypt_app.exe
```

**Output mong đợi:**
```
--- CHUONG TRINH MA HOA RC4 ---
Plaintext: Hanoi University of Science and Technology
Key:       mysecretkey

Ciphertext (Hex): 
d1 9c 53 1c 1b 11 d8 48 2c 18 b5 13 48 37 3c 1a 9f 4f 33 2b 43 0f 98 14 36 b1 c4 15 5c 08 3f 22 21 02 c7 54 62 2e 41 84 

Ciphertext (Raw bytes de copy):
"\xd1\x9c\x53\x1c\x1b\x11\xd8\x48\x2c\x18\xb5\x13\x48\x37\x3c\x1a\x9f\x4f\x33\x2b\x43\x0f\x98\x14\x36\xb1\xc4\x15\x5c\x08\x3f\x22\x21\x02\xc7\x54\x62\x2e\x41\x84"
```

### 2. Biên dịch và chạy Chương trình Giải mã

1.  **Quan trọng:** Copy chuỗi raw byte (`"\x..."`) từ output của `encrypt_app.exe`.
2.  Mở file `decrypt_app.cpp` và dán chuỗi này vào biến `ciphertext`. (Code cung cấp ở trên đã làm sẵn việc này).

**Biên dịch (với MinGW/g++):**
```bash
g++ decrypt_app.cpp -o decrypt_app.exe -std=c++11
```

**Chạy:**
```bash
.\decrypt_app.exe
```

**Output mong đợi:**
```
--- CHUONG TRINH GIAI MA RC4 ---
Key:            mysecretkey

Decrypted Text: Hanoi University of Science and Technology

SUCCESS: Giai ma thanh cong!
```

---

## Bộ Test Vector

Dùng để kiểm tra xem `rc4_library.h` có được triển khai chính xác hay không.

**Test Vector 1 (RFC 6229)**
* **Key:** `Key`
* **Plaintext:** `Plaintext`
* **Ciphertext (Hex):** `bb f3 16 e8 d9 40 af 0a d3`

**Test Vector 2 (RFC 6229)**
* **Key:** `Wiki`
* **Plaintext:** `pedia`
* **Ciphertext (Hex):** `10 21 bf 04 20`

**Test Vector 3 (Dự án này)**
* **Key:** `mysecretkey`
* **Plaintext:** `Hanoi University of Science and Technology`
* **Ciphertext (Hex):** `d1 9c 53 1c 1b 11 d8 48 2c 18 b5 13 48 37 3c 1a 9f 4f 33 2b 43 0f 98 14 36 b1 c4 15 5c 08 3f 22 21 02 c7 54 62 2e 41 84`
