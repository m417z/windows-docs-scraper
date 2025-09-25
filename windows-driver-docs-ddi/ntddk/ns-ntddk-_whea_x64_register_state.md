## Description

The **WHEA_X64_REGISTER_STATE** structure describes the state of an x64 processor's registers.

## Members

### `Rax`

The accumulator register.

### `Rbx`

The base register.

### `Rcx`

The count register.

### `Rdx`

The data register.

### `Rsi`

The source index register.

### `Rdi`

The destination index register.

### `Rbp`

The base pointer register.

### `Rsp`

The stack pointer register.

### `R8`

The general purpose register R8.

### `R9`

The general purpose register R9.

### `R10`

The general purpose register R10.

### `R11`

The general purpose register R11.

### `R12`

The general purpose register R12.

### `R13`

The general purpose register R13.

### `R14`

The general purpose register R14.

### `R15`

The general purpose register R15.

### `Cs`

The code segment register.

### `Ds`

The data segment register.

### `Ss`

The stack segment register.

### `Es`

The extra segment register.

### `Fs`

The general purpose segment register FS.

### `Gs`

The general purpose segment register GS.

### `Reserved`

Reserved for system use.

### `Rflags`

The flags register.

### `Eip`

The instruction pointer register.

### `Cr0`

The control register 0.

### `Cr1`

The control register 1.

### `Cr2`

The control register 2.

### `Cr3`

The control register 3.

### `Cr4`

The control register 4.

### `Cr8`

The control register 8.

### `Gdtr`

A **WHEA128A** structure that contains the state of the global descriptor table register. The **WHEA128A** structure describes a 128-bit value and is defined as follows:

```cpp
typedef struct _WHEA128A {
  ULONGLONG  Low;
  LONGLONG  High;
} WHEA128A, *PWHEA128A;
```

#### Low

The low order 64 bits of the 128-bit value.

#### High

The high order 64 bits of the 128-bit value.

### `Idtr`

A **WHEA128A** structure that contains the state of the interrupt descriptor table register. For a description of the **WHEA128A** structure, see the description for the **Gdtr** member.

### `Ldtr`

The local descriptor table register.

### `Tr`

The task register.

## Remarks

If the **RegisterContextType** member of a [**WHEA_XPF_CONTEXT_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_context_info) structure is set to XPF_CONTEXT_INFO_64BITCONTEXT, the **RegisterData** member of that structure contains a **WHEA_X64_REGISTER_STATE** structure.

## See also

[**WHEA_XPF_CONTEXT_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_context_info)