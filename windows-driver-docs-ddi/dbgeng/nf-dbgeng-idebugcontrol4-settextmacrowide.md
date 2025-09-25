# IDebugControl4::SetTextMacroWide

## Description

The **SetTextMacroWide** method sets the value of a fixed-name alias.

## Parameters

### `Slot` [in]

Specifies the number of the fixed-name alias. *Slot* can take the values 0, 1, ..., 9, that represent the fixed-name aliases **$u0**, **$u1**, ..., **$u9**.

### `Macro` [in]

Specifies the new value of the alias specified by *Slot*. The [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) makes a copy of this string.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Before executing commands or evaluating expressions, the debugger engine will replace the alias specified by *Slot* with the value of the alias (specified by *Macro*).

For an overview of aliases used by the debugger engine, see [Using Aliases](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-aliases). For more information about using aliases with the debugger engine API, see [Interacting with the Engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/interacting-with-the-engine).

## See also

[GetTextMacro](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-gettextmacro)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)

[RemoveTextReplacements](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-removetextreplacements)

[SetTextReplacement](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-settextreplacement)

[r (Registers)](https://learn.microsoft.com/windows-hardware/drivers/debugger/r--registers-)