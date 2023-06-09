# M01 Hidden Message

Pada ```T04``` yang lalu anda diminta untuk mengembangkan solusi *boxed string* yang mengkonversi sebuah *string* menjadi beberapa *strings* dengan panjang (```l```) tertentu. Nilai ```l``` diberikan dalam bentuk *command line argumen*t yang di-*supply* pada saat solusi dieksekusi. Pada tugas ini anda akan menggunakan *codebase* yang telah anda hasilkan dari ```T04``` .

![Boxed String](/image/m01-01.jpg)

## Task 1: Hide Message (m01_01.c, 60 points)

Berdasarkan hasil yang sudah diperoleh pada **T04**, kembangkan suatu langkah untuk menghasilkan sebuah pesan tersembunyi (*hidden message*). *Hidden message* dimaksudkan untuk mengobfuskasi pesan sedemikian rupa sehingga pesan asli (*original message*) tidak dapat dipahami oleh pihak yang tidak berkepentingan.

*Hidden message*, dengan menggunakan contoh pada gambar di atas, dibentuk dengan menyusun karakter-karakter dari strings mulai dari kiri-atas hingga kanan-bawah. Alir penyusunan dimulai dari kolom pertama, atas ke bawah, kemudian dilanjutkan ke kolom kedua, atas ke bawah, demikian seterusnya. Dengan metode demikian, maka akan dihasilkan *hidden message* sebagai berikut.

```bash
Jmaoabwkkua.an # gg#S o#ebl#

```
 
Perhatikan contoh input utuh berikut ini (```l``` = ```9```).

```bash
Jaka Sembung bawa golok.

```

Akan menghasilkan luaran sebagai berikut.

```bash
Jaka Semb
ung bawa
golok.###
Juganokgla o bkSa.ew#ma#b #

```

## Reporting

Presentasikan pekerjaan anda dalam sebuah video. Pada presentasi:
1. Definisikan tipe data yang cocok dan representatif untuk setiap properti.
2. Berikan dasar pemikiran anda mengenai usulan tipe data tersebut.
3. Jabarkan solusi anda.

**Note**: Semakin tajam argumen dan penjabaran anda semakin mudah penilaian dilakukan.

**Kriteria video presentasi**:
+ 1080p/30fps, min. 10 menit.
+ Suara jernih dan dapat dengan jelas terdengar.
+ Posting video anda di YouTube, di-set "Not For Kids" dengan visibility Unlisted.

## Submissions:

1. m01_01.c
2. changelog.txt

## How to submit?
Please see https://youtu.be/g0BQ195-aWo
