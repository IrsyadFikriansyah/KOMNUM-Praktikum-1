# Praktikum-1-KOMNUM

Anda sudah mengerti algoritma pemrosesan metode Bolzano, dan anda sudah memahami cara kerjanya. Sekarang anda tinggal mengimplementasikan algoritma tersebut menjadi sebuah program komputer metode Bolzano (yang dapat menampilkan proses iteratif numerik, lengkap dengan grafik fungsinya).

#Algoritma 
Langkah-langkah yang harus dilakukan pada metode Bolzano adalah :
1. Hitung fungsi pada interval yang sama dari x hingga terjadi perubahan tanda dari f(xn) dan f(xn+1). Atau dengan kata lain: f(xn) x f(xn+1) < 0;
2. Estimasi pertama untuk akar persamaan dapat diperoleh melalui :  xt = (xn + xn+1) / 2;
3. Lakukan evaluasi untuk menentukan dalam interval mana akar persamaan berada :
	a.  Jika f(xn) x f(xn+1) < 0
		akar persamaan dalam sub-interval pertama, tetapkan xn+1 = xt, dan 
		lanjutkan ke langkah 4;
	b.  Jika f(xn) x f(xn+1) > 0
		akar persamaan dalam sub-interval kedua, tetapkan xn = xt, dan 
		lanjutkan ke langkah 4;
	c.  Jika f(xn) x f(xn+1) = 0
		akar persamaan adalah xt, dan hitungan selesai;
4. Kembali ke langkah 2 untuk menghitung nilai perkiraan akar yang baru;

5. Jika nilai yang didapat pada no. 4 sudah sesuai denga  batasan yang ditentukan, maka proses selesai, dan xt adalah akar yang dicari.

#Implementasi Program C++
![image](https://user-images.githubusercontent.com/22763869/198871666-6703aac3-0532-4af3-a9ff-82ad6a859cef.png)

user input
- nomer persamaan
- batas bawah
- batas atas

![image](https://user-images.githubusercontent.com/22763869/198871590-bd759242-0c67-431d-bac7-49e2445573a3.png)
hasil enyelesaian persamaan

![image](https://user-images.githubusercontent.com/22763869/198871482-ba3ea65d-9a8a-4e0c-a131-7f86044edb0e.png)
ploting grafik
