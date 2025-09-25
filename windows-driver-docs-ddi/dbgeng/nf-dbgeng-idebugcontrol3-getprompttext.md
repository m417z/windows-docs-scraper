# IDebugControl3::GetPromptText

## Description

The **GetPromptText** method returns the standard prompt text that will be prepended to the formatted output specified in the [OutputPrompt](https://learn.microsoft.com/previous-versions/ff553227(v=vs.85)) and [OutputPromptVaList](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-outputpromptvalist) methods.

## Parameters

### `Buffer` [out, optional]

Receives the prompt text. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size, in characters, of the *Buffer* buffer.

### `TextSize` [out, optional]

Receives the size, in characters, of the prompt text. If *TextSize* is **NULL**, this information is not returned.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the prompt text was too large to fit into the *Buffer* buffer and the text was truncated. |

## Remarks

For more information about prompting the user, see [Using Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-input-and-output).

## See also

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[OutputPrompt](https://learn.microsoft.com/previous-versions/ff553227(v=vs.85))

[OutputPromptVaList](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-outputpromptvalist)