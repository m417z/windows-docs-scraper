# IDebugControl4::OutputWide

## Description

The **OutputWide** method formats a string and send the result to [output callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-input-and-output) that have been registered with the engine's clients.

## Parameters

### `Mask` [in]

Specifies the output-type bit field. See [DEBUG_OUTPUT_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-output-xxx) for possible values.

### `Format` [in]

Specifies the format string, as in **printf**. In general, conversion characters work exactly as in C. For the floating-point conversion characters the 64-bit argument is interpreted as a 32-bit floating-point number unless the **l** modifier is used.

The **%p** conversion character is supported, but it represents a pointer in a target's address space. It cannot have any modifiers and it uses the debugger's internal address formatting. The following additional conversion characters are supported.

| Character | Argument type | Argument | Text printed |
| --- | --- | --- | --- |
| **%p** | ULONG64 | Pointer in an address space | The value of the pointer. |
| **%N** | DWORD_PTR (32 or 64 bits, depending on the host's architecture) | Pointer in the host's virtual address space | The value of the pointer. (This is equivalent to the standard C **%p** character.) |
| **%I** | ULONG64 | Any 64-bit value | The specified value. If this is greater than 0xFFFFFFFF, it is printed as a 64-bit value. Otherwise, it is printed as a 32-bit value. |
| **%ma** | ULONG64 | Address of a NULL-terminated ASCII string in the process's virtual address space | The specified string. |
| **%mu** | ULONG64 | Address of a NULL-terminated Unicode string in the process's virtual address space | The specified string. |
| **%msa** | ULONG64 | Address of an ANSI_STRING structure in the process's virtual address space | The specified string. |
| **%msu** | ULONG64 | Address of a UNICODE_STRING structure in the process's virtual address space | The specified string. |
| **%y** | ULONG64 | Address in the process's virtual address space of an item with symbol information | String that contains the name of the specified symbol (and displacement, if any). |
| **%ly** | ULONG64 | Address in the process's virtual address space of an item with symbol information | String that contains the name of the specified symbol (and displacement, if any), as well as any available source line information. |

### `...`

Specifies additional parameters that contain values to be inserted into the output during formatting.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

When generating very large output strings, it is possible to reach the limits of the debugger engine or of the operating system. For example, some versions of the debugger engine have a 16K character limit for a single output. If you find that very large output is getting truncated, you might need to split your output into multiple requests.

## See also

[.printf](https://learn.microsoft.com/windows-hardware/drivers/debugger/-printf)

[ControlledOutput](https://learn.microsoft.com/previous-versions/ff539248(v=vs.85))

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)

[OutputVaList](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-outputvalist)

[dprintf](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_output_routine)