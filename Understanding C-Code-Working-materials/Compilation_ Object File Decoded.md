---
title: 'Compilation: Object File Decoded'
updated: 2024-12-27 19:06:29Z
created: 2024-12-27 18:35:07Z
latitude: 15.84969530
longitude: 74.49767410
altitude: 0.0000
---

# Compilation: Object File Decoded

<img src="../_resources/Decode-1.png" alt="Decode-1.png" width="1318" height="639" class="jop-noMdConv">
<img src="../_resources/Decode-2.png" alt="Decode-2.png" width="1318" height="639" class="jop-noMdConv">
<img src="../_resources/Decode-3.png" alt="Decode-3.png" width="1318" height="639" class="jop-noMdConv">
<img src="../_resources/Decode-4.png" alt="Decode-4.png" width="1318" height="639" class="jop-noMdConv">

1.  “.bss” doesn’t consume space in flash, but “.data” does.
2.  “.bss” section size is recorded and is allocated in stack, recording of size is done by linker. <- we will learn about it, further.
3.  “static int Num1 = 5;” will be part of “.data” but “int Num1 = 5;” will be part of “.bss”. WHY? Static will be seen as global data - making “.data” section worthy, for, latter will be taken in “.bss” and considered when main() is called - making it “stack” worthy.

Note: A value in “.rdata” cannot be modified, if you try, it will segmentation fault.

<img src="../_resources/Decode-5.png" alt="Decode-5.png" width="1318" height="639" class="jop-noMdConv">
<img src="../_resources/Decode-6.png" alt="Decode-6.png" width="1318" height="639" class="jop-noMdConv">

