[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/-ZDa4Sqk)
# T11 File Operation

Pada tugas terstruktur kali ini anda akan melakukan operasi berkas. Terdapat dua fitur yang saling berelasi. Perlu diperhatikan bahwa fitur-fitur pendahulu harus tetap tersedia dan dapat digunakan.

## Task 1. Loading Initial Data (t11_01.c, 40pts)

Pada tugas-tugas sebelumnya, simulator membaca data dari pengguna secara interaktif. Pada saat dijalankan, simulator tidak memeiliki initial data, kosong, dan diisi seiring interaksi dengan penggunanya. Pada tugas kali ini anda diminta untuk mengembangkan suatu solusi yang akan me-load initial data ke dalam simulator. Dengan demikian, simulator akan memiliki initial data, tidak kosong.

**NOTE**:
1. Data bersumber dari berkas yang disimpan dalam direktori ```storage```.
2. Anda tidak diizinkan untuk mengubah dan menyertakan berkas pada direktori storage ke central repository (GitHub). 

Saat ini telah disediakan lima initial data pada:
1. ```./storage/dorm-repository.txt``` untuk data asrama (```dorm```); dan
2. ```./storage/student-repository.txt``` untuk data mahasiswa (```student```).

Kemudian, diberi masukan berikut.

```bash
dorm-print-all-detail
student-print-all-detail
---

```

Simulator kemudian akan memberi keluaran berikut.

```bash
Antiokia|5|male|0
Mamre|5|male|0
Silo|5|male|0
Mahanaim|5|male|0
Nazaret|5|male|0
12S22001|Winfrey Nainggolan|2022|male|unassigned
12S22002|Jeremy Nainggolan|2022|male|unassigned
12S22009|Dolok Butarbutar|2022|male|unassigned
12S22010|Reinaldy Hutapea|2022|male|unassigned
12S22014|Kezia Hutagaol|2022|female|unassigned

```

## Task 2. Storing Data (t11_02.c, 60pts)

Setelah simulator berakhir eksekusinya, data di dalamnya turut hilang karena sifat **volatility** dari data yang tersimpan di **main memory** di mana simulator berada. Tugas anda adalah menyimpan kembali seluruh data asrama (```dorm```) dan mahasiswa (```student```) ke dalam berkas yang relevan. Perlu diingat bahwa tugas ini didasarkan pada ```Task 1```.

Perhatikan contoh berikut dengan menggunakan initial data yang dijabarkan pada ```Task 1```.

```bash
student-add#12S22015#Angelina Nadeak#2022#female
student-add#12S22024#Pimpin Loi#2022#male
student-add#12S22025#Bronson Siallagan#2022#male
student-add#12S22026#Ruben Sianipar#2022#male
student-add#12S22027#Ferry Panjaitan#2022#male
student-print-all
dorm-add#Antiokia#20#male
dorm-add#Mamre#20#male
dorm-add#Silo#20#male
dorm-add#Mahanaim#20#male
dorm-add#Nazaret#20#male
dorm-add#Pniel#20#female
dorm-add#Kapernaum#20#male
dorm-print-all
student-print-all-detail
dorm-print-all-detail
---

```

Maka simulator akan meberi keluaran berikut.

```bash
12S22001|Winfrey Nainggolan|2022|male
12S22002|Jeremy Nainggolan|2022|male
12S22009|Dolok Butarbutar|2022|male
12S22010|Reinaldy Hutapea|2022|male
12S22014|Kezia Hutagaol|2022|female
12S22015|Angelina Nadeak|2022|female
12S22024|Pimpin Loi|2022|male
12S22025|Bronson Siallagan|2022|male
12S22026|Ruben Sianipar|2022|male
12S22027|Ferry Panjaitan|2022|male
Antiokia|5|male
Mamre|5|male
Silo|5|male
Mahanaim|5|male
Nazaret|5|male
Antiokia|20|male
Mamre|20|male
Silo|20|male
Mahanaim|20|male
Nazaret|20|male
Pniel|20|female
Kapernaum|20|male
12S22001|Winfrey Nainggolan|2022|male|unassigned
12S22002|Jeremy Nainggolan|2022|male|unassigned
12S22009|Dolok Butarbutar|2022|male|unassigned
12S22010|Reinaldy Hutapea|2022|male|unassigned
12S22014|Kezia Hutagaol|2022|female|unassigned
12S22015|Angelina Nadeak|2022|female|unassigned
12S22024|Pimpin Loi|2022|male|unassigned
12S22025|Bronson Siallagan|2022|male|unassigned
12S22026|Ruben Sianipar|2022|male|unassigned
12S22027|Ferry Panjaitan|2022|male|unassigned
Antiokia|5|male|0
Mamre|5|male|0
Silo|5|male|0
Mahanaim|5|male|0
Nazaret|5|male|0
Antiokia|20|male|0
Mamre|20|male|0
Silo|20|male|0
Mahanaim|20|male|0
Nazaret|20|male|0
Pniel|20|female|0
Kapernaum|20|male|0

```

Selain itu, simulator juga akan menulis seluruh data yang ia miliki ke dalam berkas. Berikut adalah contoh berkas ```./storage/student-repository.txt```. Perlu diperhatikan, hal yang serupa juga dilakukan terhadap data asrama (```dorm```).

```bash
12S22001|Winfrey Nainggolan|2022|male
12S22002|Jeremy Nainggolan|2022|male
12S22009|Dolok Butarbutar|2022|male
12S22010|Reinaldy Hutapea|2022|male
12S22014|Kezia Hutagaol|2022|female
12S22015|Angelina Nadeak|2022|female
12S22024|Pimpin Loi|2022|male
12S22025|Bronson Siallagan|2022|male
12S22026|Ruben Sianipar|2022|male
12S22027|Ferry Panjaitan|2022|male

```

Sebelum anda menjalankan program, selalu eksekusi kedua baris berikut untuk me-reset kedua repositories.

```bash
git restore .\storage\student-repository.txt
git restore .\storage\dorm-repository.txt
```

**Note**

1. Tuliskan semua fungsionalitas terkait operasi berkas pada ```repository.h``` dan ```repository.c```. Anda diizinkan untuk melakukan modifikasi pada source code 
2. Anda diperbolehkan untuk mengubah dan menambahkan fungsi yang relevan tentu saja pada library yang sesuai. Meski demikian, anda **tidak** diperbolehkan mengubah struct maupun enum!
3. Hardcoded output akan mendiskualitifkasi nilai tugas.

## Reporting
Presentasikan pekerjaan anda dalam sebuah video. Pada presentasi:
1. Jabarkan solusi anda dengan rinci.
2. Berikan rationale dari setiap implementasi yang anda hasilkan.
3. Jabarkan alir eksekusi dari solusi anda.
4. Demonstrasikan pekerjaan anda.
5. Tunjukkan hasil yang anda peroleh dari GitHub Classroom.
6. Sebutkan kendala yang dihadapi dalam pengerjaan tugas kali ini.

Note: Semakin tajam argumen dan penjabaran anda semakin mudah penilaian dilakukan.

Kriteria Video Presentasi:
+ 1080p/30fps, min. 10 menit.
+ Fullscreen (taskbar terlihat).
+ Suara jernih dan dapat dengan jelas terdengar.
+ Posting kedua video anda di YouTube, di-set "Not For Kids" dengan visibility Unlisted.

## Submissions:

1. t11_01.c
2. t11_02.c
3. changelog.txt

## How to submit?
Please see https://youtu.be/g0BQ195-aWo
