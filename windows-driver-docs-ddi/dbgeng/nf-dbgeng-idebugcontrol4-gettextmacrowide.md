# IDebugControl4::GetTextMacroWide

## Description

The **GetTextMacroWide** method returns the value of a fixed-name alias.

## Parameters

### `Slot` [in]

Specifies the number of the fixed-name alias. *Slot* can take the values 0, 1, ..., 9, that represent the fixed-name aliases **$u0**, **$u1**, ..., **$u9**.

### `Buffer` [out, optional]

Receives the value of the alias specified by *Slot*. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size, in characters, of the *Buffer* buffer.

### `MacroSize` [out, optional]

Receives the size, in characters, of the value of the alias.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Before executing commands or evaluating expressions, the debugger engine will replace the alias specified by *Slot* with the value of the alias (returned to the *Buffer* buffer).

For an overview of aliases used by the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction), see [Using Aliases](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-aliases). For more information about using aliases with the debugger engine API, see [Interacting with the Engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/interacting-with-the-engine).

## See also

[GetNumberTextReplacements](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getnumbertextreplacements)

[GetTextReplacement](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-gettextreplacement)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)

[SetTextMacro](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-settextmacro)

[r (Registers)](https://learn.microsoft.com/windows-hardware/drivers/debugger/r--registers-)