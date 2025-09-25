# PWINDBG_OUTPUT_ROUTINE callback function

## Description

The callback function implements the functionality to print a formatted string to the Debugger Command window.

The wdbgexts.h header declares a macro, **dprintf** that prints the formatted string. It works like the C-language routine **printf**.

## Parameters

### `lpFormat` [in]

Specifies the format string, as in **printf**. In general, conversion characters work exactly as in C. For the floating-point conversion characters the 64-bit argument is interpreted as a 32-bit floating-point number unless the **l** modifier is used.

The **%p** conversion character is supported, but it represents a pointer in the target's virtual address space. It may not have any modifiers and it uses the debugger's internal address formatting. The following additional conversion characters are supported:

| Character | Argument Type | Argument | Text printed |
| --- | --- | --- | --- |
| **%p** | ULONG64 | Pointer in the target's virtual address space | The value of the pointer. |
| **%N** | DWORD_PTR (32 or 64 bits, depending on the host's architecture) | Pointer in the host's virtual address space | The value of the pointer. (This is equivalent to the standard C **%p** character.) |
| **%I** | ULONG64 | Any 64-bit value | The specified value. If this is greater than 0xFFFFFFFF it is printed as a 64-bit address, otherwise it is printed as a 32-bit address. |
| **%ma** | ULONG64 | Address of a NULL-terminated ASCII string in the target's virtual address space | The specified string. |
| **%mu** | ULONG64 | Address of a NULL-terminated Unicode string in the target's virtual address space | The specified string. |
| **%msa** | ULONG64 | Address of an ANSI_STRING structure in the target's virtual address space | The specified string. |
| **%msu** | ULONG64 | Address of a UNICODE_STRING structure in the target's virtual address space | The specified string. |
| **%y** | ULONG64 | Address of a debugger symbol in the target's virtual address space | String containing the name of the specified symbol (and displacement, if any). |
| **%ly** | ULONG64 | Address of a debugger symbol in the target's virtual address space | String containing the name of the specified symbol (and displacement, if any), as well as any available source line information. |

### `unnamedParam2` [in]

**[arguments]** - Specifies arguments for the format string, as in **printf**. The number of arguments specified should match the number of conversion characters in *FormatString*. Each argument is an expression that will be evaluated by the default expression evaluator (MASM or C++). For details, see [Numerical Expression Syntax](https://learn.microsoft.com/windows-hardware/drivers/debugger/numerical-expression-syntax).

## Remarks

When generating very large output strings, it is possible the limits of the debugger engine or operating system may be reached. For example, some versions of the debugger engine have a 16K character limit for a single piece of output. If you find that very large output is getting truncated, you may need to split your output into multiple requests.