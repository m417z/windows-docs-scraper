# _WHEA_X86_REGISTER_STATE structure

## Description

The WHEA_X86_REGISTER_STATE structure describes the state of an x86 processor's registers.

## Members

### `Eax`

The accumulator register.

### `Ebx`

The base register.

### `Ecx`

The count register.

### `Edx`

The data register.

### `Esi`

The source index register.

### `Edi`

The destination index register.

### `Ebp`

The base pointer register.

### `Esp`

The stack pointer register.

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

### `Eflags`

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

### `Gdtr`

The global descriptor table register.

### `Idtr`

The interrupt descriptor table register.

### `Ldtr`

The local descriptor table register.

### `Tr`

The task register.

## Remarks

If the **RegisterContextType** member of a [WHEA_XPF_CONTEXT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_context_info) structure is set to XPF_CONTEXT_INFO_32BITCONTEXT, the **RegisterData** member of that structure contains a WHEA_X86_REGISTER_STATE structure.

## See also

[WHEA_XPF_CONTEXT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_context_info)