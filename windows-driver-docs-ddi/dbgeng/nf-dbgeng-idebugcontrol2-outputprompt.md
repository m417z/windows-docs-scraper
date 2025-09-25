# IDebugControl2::OutputPrompt

## Description

The **OutputPrompt** method formats and sends a user prompt to the [output callback objects](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-callback-objects).

## Parameters

### `OutputControl` [in]

Specifies an output control that determines which of the client's output callbacks will receive the output. For possible values, see [DEBUG_OUTCTL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outctl-xxx).

### `Format` [in, optional]

Specifies the format string, as in **printf**. Typically, conversion characters work exactly as they do in C. For the floating-point conversion characters, the 64-bit argument is interpreted as a 32-bit floating-point number unless the **l** modifier is used.

The **%p** conversion character is supported, but it represents a pointer in a target's address space. It might not have any modifiers and it uses the debugger's internal address formatting. The following additional conversion characters are supported.

| Character | Argument type | Argument | Text printed |
| --- | --- | --- | --- |
| **%p** | ULONG64 | Pointer in an address space. | The value of the pointer. |
| **%N** | DWORD_PTR (32 or 64 bits, depending on the host's architecture) | Pointer in the host's virtual address space. | The value of the pointer. (This is equivalent to the standard C **%p** character.) |
| **%I** | ULONG64 | Any 64-bit value. | The specified value. If this is greater than 0xFFFFFFFF, it is printed as a 64-bit value; otherwise, it is printed as a 32-bit value. |
| **%ma** | ULONG64 | Address of a NULL-terminated ASCII string in the process' virtual address space. | The specified string. |
| **%mu** | ULONG64 | Address of a NULL-terminated Unicode string in the process's virtual address space. | The specified string. |
| **%msa** | ULONG64 | Address of an ANSI_STRING structure in the process's virtual address space. | The specified string. |
| **%msu** | ULONG64 | Address of a UNICODE_STRING structure in the process's virtual address space. | The specified string. |
| **%y** | ULONG64 | Address in the process's virtual address space of an item with symbol information. | String that contains the name of the specified symbol (and displacement, if any). |
| **%ly** | ULONG64 | Address in the process's virtual address space of an item with symbol information. | String that contains the name of the specified symbol (and displacement, if any), as well as any available source line information. |

If *Format* is **NULL**, only the standard prompt text is sent to the output callbacks.

### `...`

Specifies additional parameters that represent values to be inserted into the output during formatting.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

**OutputPrompt** and **OutputPromptWide** can be used to prompt the user for input.

The standard prompt will be sent to the output callbacks before the formatted text described by *Format*. The contents of the standard prompt is returned by the method [GetPromptText](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getprompttext).

The prompt text is sent to the output callbacks with the [DEBUG_OUTPUT_PROMPT](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-output-xxx) output mask set.

For more information about prompting the user, see [Using Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-input-and-output).

## See also

[ControlledOutput](https://learn.microsoft.com/previous-versions/ff539248(v=vs.85))

[DEBUG_OUTPUT_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-output-xxx)

[GetPromptText](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getprompttext)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[OutputPromptVaList](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-outputpromptvalist)