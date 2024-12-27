---
title: 'Compilation: What is it? How it works?'
updated: 2024-12-27 18:33:14Z
created: 2024-12-25 18:48:50Z
latitude: 15.84969530
longitude: 74.49767410
altitude: 0.0000
---

# Compilation: What is it? How it works?

## 01\. Editor: Source file

It is the code you write. It contains the logic, comments, macros, file-inclusions (Ex: &lt;stdio.h&gt;), conditional builds, etc. Following is an example:

<img src="../_resources/source-code.png" alt="source-code.png" width="608" height="481" class="jop-noMdConv">

&nbsp;            <img src="../_resources/Source.png" alt="Source.png" width="97" height="137" class="jop-noMdConv">
## 02\. Pre-Processor

1.  It is invoked by the compiler(Ex: GCC) you are using to build the code.
2.  Output of pre-processor file:
    1.  Removes comments “//” or “/\*\* \*\*/”.
    2.  macro expansion and “#”
    3.  Header file inclusion: the entire content of the header is copied, replacing "#", basically contains function declarations and macros.
3.  Conditional compilation & diagnostics: “#error” inside conditions, resulting in fatal error.
4.  Uses “line-markers” to convey information. (See figures for better clarity.)

<img src="../_resources/pre-processor-code.png" alt="pre-processor-code.png" width="917" height="617" class="jop-noMdConv">

&nbsp;            <img src="../_resources/pre-processor-op.png" alt="pre-processor-op.png" width="97" height="137" class="jop-noMdConv">
## 03\. Parsing: Checks structural mistakes.

Responsible for eliminating white-space and erroneous characters, checks if it is adhering to programming language’s grammar. AN AST (Abstract Syntax Tree) is output of this phase, additionally, it performs flow, type and label checks. If an error is found, the linemarkers help in showing the error-line.

&nbsp;            <img src="../_resources/pre-processor-op.png" alt="pre-processor-op.png" width="97" height="137" class="jop-noMdConv">
## 04\. Compiler: Generates assembly code

High-level code is converted to processor-level mnemonics, i.e., assembly code. Assembly code is always machine-specific; the compiler takes note of the type of machine it is being used during installation. If you decide to have an assembly code of a different machine type, then you set flags accordingly for the compiler to know what to build for.

<img src="../_resources/Assembly-code.png" alt="Assembly-code.png" width="528" height="499" class="jop-noMdConv">

&nbsp;            <img src="../_resources/Machine-code-op.png" alt="Machine-code-op.png" width="97" height="137" class="jop-noMdConv">
## 05\. Assembler: Generates Machine-code

Responsible for eliminating white-space and erroneous characters, checks if it is adhering to programming language’s grammar. An AST (Abstract Syntax Tree) is output of this phase, additionally, it performs flow, type and label checks. If an error is found, the linemarkers help in showing the error-line.

<img src="../_resources/machine-code.png" alt="machine-code.png" width="1285" height="125" class="jop-noMdConv">

&nbsp;            <img src="../_resources/Object.png" alt="Object.png" width="97" height="137" class="jop-noMdConv">
## 06\. Linker: links all files

Creates executable or binaries that you can run. Linker links (as name says) all the individual “*.obj” or “*.o” that were created during build process and made into one final, self-contained executable.

<img src="../_resources/Executable.png" alt="Executable.png" width="212" height="141" class="jop-noMdConv">