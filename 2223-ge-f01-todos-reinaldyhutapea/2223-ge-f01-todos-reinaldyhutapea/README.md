[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/mbbk4I8Z)
# F01 Todos

Pada ujian kali ini anda bersama pair akan diminta untuk mengembangkan sebuah solusi sederhana untuk memanajemen aktivitas seseorang dalam satu hari. **Todos**.

Sebuah aktivitas terdiri atas empat buah atribut, yakni `id`, `waktu`, `nama aktivitas`, dan `status`.
+ `id` menunjukkan urutan unik dengan nilai *ascending* dimulai dari `1`.
+ `waktu` menunjukkan waktu pelaksanaan dalam format 24 jam, `HH:mm`. Misal `13:30`.
+ `nama aktivitas` merupakan nama dari kegiatan.
+ `status` merepresentasikan status dari aktivitas. By default, status dari sebuah aktivitas adalah `none`. Kemudian, dapat diubah menjadi `done` atau `canceled`.

Saat ini telah disediakan *initial data* yang berisi beberapa *activities* pada `./storage/todo-repository.txt`. Berikut adalan konten dari berkas.

```bash
1|08:30|Group Project|canceled
2|10:00|Class: Fantastic Pempros|done
3|13:30|Group Project|none

```

Agar diperhatikan bahwa sebuah *activity* disimpan dalam satu baris teks yang menyertakan keempat *attributes* dengan `|` sebagai *separator*.

**NOTE**:

Solusi anda diharapkan untuk terus-menerus membaca baris-baris perintah masukkan melalui `STDIN`. Solusi akan menghentikan eksekusi apabila diberi perintah `---`. Panjang satu baris masukkan dijamin tidak lebih dari 100 karakter.

Di sepanjang pengembangan solusi, anda diharapkan untuk menuliskan *structs*, *enums*, maupun *functions* pada berkas-berkas berikut:
1. `./libs/repository.h` dan `./libs/repository.c` untuk yang relevan dengan *stream operations*.
2. `./libs/todo.h` dan `./libs/todo.c` untuk yang relevan dengan *activity-related operations*.

Selain `main()` *function*, anda tidak diizinkan untuk menulis fungsi apapun pada `f01_01.c`, `f01_02.c`, maupun `f01_03.c`.

Untuk setiap eksekusi, selalu gunakan *initial data*. Untuk me-*reset* konten dari `./storage/todo-repository.txt`, gunakan perintah berikut.

```bash
git restore ./storage/todo-repository.txt

```

## Task 1. Loading Initial Data (`f01_01.c`, 40pts)

Tugas pertama anda adalah mengembangkan sebuah fitur untuk me-*load* *initial data* pada saat solusi dieksekusi. Setelah itu, kembangkan sebuah fitur untuk menampilkan seluruh *activities*. Untuk setiap *activity* ditampilkan dalam sebaris keluaran. Fitur ini dieksekusi apabila diperoleh perintah `todo-print-all`. Perhatikan contoh keluaran berikut.

```bash
1|08:30|Group Project|canceled
2|10:00|Class: Fantastic Pempros|done
3|13:30|Group Project|none

```

## Task 2. Adding New Activity (`f01_02.c`, 40pts)

Meneruskan **Task 1**, anda diminta untuk mengembangkan fitur yang memampukan solusi untuk menambahkan sebuah `activity`. Perintah yang digunakan adalah `todo-add` dan diikuti dengan `waktu` pelaksanaan, dan `nama aktivitas`. Perintah tersebut ditulis dalam satu baris dan diseparasi dengan `#`. Solusi akan secara otomatis menambahkan `id` dengan urutan sekuens berikutnya dan `status` dengan `none`.

Sebagai contoh, dengan menggunakan *initial data* pada *repository*, diberikan masukkan sebagai berikut.

```bash
todo-add#15:00#Class: Pempros lab
todo-add#17:10#SI v. IF semi match
todo-print-all
---

```

Solusi akan memberikan keluaran sebagai berikut. Perhatikan nilai dari `id` dan `status`.

```bash
1|08:30|Group Project|canceled
2|10:00|Class: Fantastic Pempros|done
3|13:30|Group Project|none
4|15:00|Class: Pempros lab|none
5|17:10|SI v. IF semi match|none

```

Berikutnya, kembangkan sebuah fitur yang akan secara otomatis menyimpan data aktivitas kembali ke dalam *repository*. Perhatikan format yang digunakan. Fitur ini juga digunakan pada **Task 3**.

## Task 3. Update Status (`f01_03.c`, 20pts)

Setelah menyelesaikan **Task 2**, anda diminta untuk mengembangkan sebuah fitur untuk mengubah nilai dari `status`. Perlu diingat, *initial value* dari `status` adalah `none`. Oleh sebab itu, hanya aktivitas dengan nilai tersebut yang boleh diubah. Opsi perubahan `status` adalah menjadi `done` atau `canceled`. Untuk mengubah status, perintah yang digunakan adalah `todo-status` dan diikuti dengan `id` dari aktivitas yang akan diubah `status`-nya, serta nilai `status` yang baru. Perintah tersebut ditulis dalam satu baris dan diseparasi dengan `#`.

Sebagai contoh, dengan menggunakan *initial data* pada *repository*, diberikan masukkan sebagai berikut.

```bash
todo-add#15:00#Class: Pempros lab
todo-status#3#done
todo-add#17:10#SI v. IF semi match
todo-print-all
---

```

Solusi akan memberikan keluaran sebagai berikut.

```bash
1|08:30|Group Project|canceled
2|10:00|Class: Fantastic Pempros|done
3|13:30|Group Project|done
4|15:00|Class: Pempros lab|none
5|17:10|SI v. IF semi match|none

```

## Reporting
Presentasikan pekerjaan anda dalam sebuah video. Pada presentasi:
1. Jabarkan solusi anda dengan rinci.
2. Berikan rationale dari setiap implementasi yang anda hasilkan.
3. Jabarkan alir eksekusi dari solusi anda.
4. Demonstrasikan pekerjaan anda.
5. Tunjukkan hasil yang anda peroleh dari GitHub Classroom.
6. Sebutkan kendala yang dihadapi dalam pengerjaan ujian.

Note: Semakin tajam argumen dan penjabaran anda semakin mudah penilaian dilakukan.

Kriteria Video Presentasi:
+ 1080p/30fps, min. 10 menit.
+ Fullscreen (taskbar terlihat).
+ Suara jernih dan dapat dengan jelas terdengar.
+ Posting kedua video anda di YouTube, di-set "Not For Kids" dengan visibility Unlisted.

## Submissions:

1. `f01_01.c`;
2. `f01_02.c`;
3. `f01_03.c`;
4. `./libs/repository.h`;
5. `./libs/repository.c`;
6. `./libs/todo.h`;
7. `./libs/todo.c`;
8. `changelog.txt`.

## How to submit?
Please see https://youtu.be/g0BQ195-aWo
