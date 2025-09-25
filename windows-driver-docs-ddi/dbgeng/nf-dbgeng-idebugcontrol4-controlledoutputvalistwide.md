# IDebugControl4::ControlledOutputVaListWide

## Description

The **ControlledOutputVaListWide** method formats a string and sends the result to [output callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-input-and-output) that were registered with some of the engine's clients.

## Parameters

### `OutputControl` [in]

Specifies an output control that determines which client's output callbacks will receive the output. For possible values, see [DEBUG_OUTCTL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outctl-xxx). For more information about output, see [Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/input-and-output).

### `Mask` [in]

Specifies the output-type bit field. See [DEBUG_OUTPUT_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-output-xxx) for possible values.

### `Format` [in]

Specifies the format string, as in **printf**. Typically, conversion characters work exactly as they do in C. For the floating-point conversion characters, the 64-bit argument is interpreted as a 32-bit floating-point number unless the **l** modifier is used.

The **%p** conversion character is supported, but it represents a pointer in a target's address space. It might not have any modifiers, and it uses the debugger's internal address formatting. The following additional conversion characters are supported.

| Character | Argument type | Argument | Text printed |
| --- | --- | --- | --- |
| **%p** | ULONG64 | Pointer in an address space. | The value of the pointer. |
| **%N** | DWORD_PTR (32 or 64 bits, depending on the host's architecture) | Pointer in the host's virtual address space. | The value of the pointer. (This is equivalent to the standard C **%p** character.) |
| **%I** | ULONG64 | Any 64-bit value. | The specified value. If this is greater than 0xFFFFFFFF, it is printed as a 64-bit value; otherwise, it is printed as a 32-bit value. |
| **%ma** | ULONG64 | Address of a NULL-terminated ASCII string in the process's virtual address space. | The specified string. |
| **%mu** | ULONG64 | Address of a NULL-terminated Unicode string in the process's virtual address space. | The specified string. |
| **%msa** | ULONG64 | Address of an ANSI_STRING structure in the process's virtual address space. | The specified string. |
| **%msu** | ULONG64 | Address of a UNICODE_STRING structure in the process's virtual address space. | The specified string. |
| **%y** | ULONG64 | Address in the process's virtual address space of an item with symbol information. | String that contains the name of the specified symbol (and displacement, if any). |
| **%ly** | ULONG64 | Address in the process's virtual address space of an item with symbol information. | String that contains the name of the specified symbol (and displacement, if any), as well as any available source line information. |

The %Y format specifier can be used to support the Debugger Markup Language (DML). For more information, see [Customizing Debugger Output Using DML](https://learn.microsoft.com/windows-hardware/drivers/debugger/customizing-debugger-output-using-dml).

The following table summarizes the use of the %Y format specifier.

|  |  |  |  |
| --- | --- | --- | --- |
| Character | Argument type | Argument | Text printed |
| **%Y{t}** | String | Text | Quoted string. Will convert text to DML if the output format (first arg) is DML. |
| **%Y{T}** | String | Text | Quoted string. Will always convert text to DML regardless of the output format. |
| **%Y{s}** | String | Text | Unquoted string. Will convert text to DML if the output format (first arg) is DML. |
| **%Y{S}** | String | Text | Unquoted string. Will always convert text to DML regardless of the output format. |
| **%Y{as}** | ULONG64 | Debugger formatted pointer | Adds either an empty string or 9 characters of spacing for padding the high 32-bit portion of debugger formatted pointer fields. The extra space outputs 9 spaces which includes the upper 8 zeros plus the ` character. |
| **%Y{ps}** | ULONG64 | Debugger formatted pointer | Adds either an empty string or 8 characters of spacing for padding the high 32-bit portion of debugger formatted pointer fields. |
| **%Y{l}** | ULONG64 | Debugger formatted pointer | Address as source line information. |

This code snippet illustrates the use of the %Y format specifier.

```cpp
HRESULT CALLBACK testout(_In_ PDEBUG_CLIENT pClient, _In_ PCWSTR /*pwszArgs*/)
{
    HRESULT hr = S_OK;

    ComPtr<IDebugControl4> spControl;
    IfFailedReturn(pClient->QueryInterface(IID_PPV_ARGS(&spControl)));

    spControl->ControlledOutputWide(DEBUG_OUTCTL_DML, DEBUG_OUTPUT_NORMAL, L"DML/NORMAL Y{t}: %Y{t}\n", L"Hello <World>");
    spControl->ControlledOutputWide(DEBUG_OUTCTL_DML, DEBUG_OUTPUT_NORMAL, L"DML/NORMAL Y{T}: %Y{T}\n", L"Hello <World>");
    spControl->ControlledOutputWide(DEBUG_OUTCTL_DML, DEBUG_OUTPUT_NORMAL, L"DML/NORMAL Y{s}: %Y{s}\n", L"Hello <World>");
    spControl->ControlledOutputWide(DEBUG_OUTCTL_DML, DEBUG_OUTPUT_NORMAL, L"DML/NORMAL Y{S}: %Y{S}\n", L"Hello <World>");

    spControl->ControlledOutputWide(0, DEBUG_OUTPUT_NORMAL, L"TEXT/NORMAL Y{t}: %Y{t}\n", L"Hello <World>");
    spControl->ControlledOutputWide(0, DEBUG_OUTPUT_NORMAL, L"TEXT/NORMAL Y{T}: %Y{T}\n", L"Hello <World>");
    spControl->ControlledOutputWide(0, DEBUG_OUTPUT_NORMAL, L"TEXT/NORMAL Y{s}: %Y{s}\n", L"Hello <World>");
    spControl->ControlledOutputWide(0, DEBUG_OUTPUT_NORMAL, L"TEXT/NORMAL Y{S}: %Y{S}\n", L"Hello <World>");

    spControl->ControlledOutputWide(DEBUG_OUTCTL_DML, DEBUG_OUTPUT_NORMAL, L"DML/NORMAL Y{a}: %Y{a}\n", (ULONG64)0x00007ffa7da163c0);
    spControl->ControlledOutputWide(DEBUG_OUTCTL_DML, DEBUG_OUTPUT_NORMAL, L"DML/NORMAL Y{as} 64bit   : '%Y{as}'\n", (ULONG64)0x00007ffa7da163c0);
    spControl->ControlledOutputWide(DEBUG_OUTCTL_DML, DEBUG_OUTPUT_NORMAL, L"DML/NORMAL Y{as} 32value : '%Y{as}'\n", (ULONG64)0x1);

    spControl->ControlledOutputWide(DEBUG_OUTCTL_DML, DEBUG_OUTPUT_NORMAL, L"DML/NORMAL Y{ps} 64bit   : '%Y{ps}'\n", (ULONG64)0x00007ffa7da163c0);
    spControl->ControlledOutputWide(DEBUG_OUTCTL_DML, DEBUG_OUTPUT_NORMAL, L"DML/NORMAL Y{ps} 32value : '%Y{ps}'\n", (ULONG64)0x1);

    spControl->ControlledOutputWide(DEBUG_OUTCTL_DML, DEBUG_OUTPUT_NORMAL, L"DML/NORMAL Y{l}: %Y{l}\n", (ULONG64)0x00007ffa7da163c0);

    return hr;

}

```

This sample code would generate the following output.

```cpp
0:004> !testout
DML/NORMAL Y{t}: "Hello <World>"
DML/NORMAL Y{T}: "Hello <World>"
DML/NORMAL Y{s}: Hello <World>
DML/NORMAL Y{S}: Hello <World>
TEXT/NORMAL Y{t}: "Hello <World>"
TEXT/NORMAL Y{T}: &quot;Hello <World>&quot;
TEXT/NORMAL Y{s}: Hello <World>
TEXT/NORMAL Y{S}: Hello <World>
DML/NORMAL Y{a}: 00007ffa`7da163c0
DML/NORMAL Y{as} 64bit   : '         '
DML/NORMAL Y{as} 32value : '         '
DML/NORMAL Y{ps} 64bit   : '        '
DML/NORMAL Y{ps} 32value : '        '
DML/NORMAL Y{l}: [d:\th\minkernel\kernelbase\debug.c @ 443]

```

### `Args` [in]

Specifies additional parameters that represent values to be inserted into the output during formatting. *Args* must be initialized using **va_start**. This method does not call **va_end**.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

When generating very large output strings, it is possible to reach the limits of the debugger engine or of the operating system. For example, some versions of the debugger engine have a 16K character limit for a single output. If you find that very large output is getting truncated, you might need to split your output into multiple requests.

The macros **va_list**, **va_start**, and **va_end** are defined in Stdarg.h.

## See also

[ControlledOutput](https://learn.microsoft.com/previous-versions/ff539248(v=vs.85))

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)

[OutputVaList](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-outputvalist)

[dprintf](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_output_routine)