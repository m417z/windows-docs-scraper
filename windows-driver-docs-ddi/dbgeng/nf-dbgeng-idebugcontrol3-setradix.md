# IDebugControl3::SetRadix

## Description

The **SetRadix** method sets the default radix (number base) used by the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) when it evaluates and displays MASM expressions, and when it displays symbol information.

## Parameters

### `Radix` [in]

Specifies the new default radix. The following table contains the possible values for the radix.

| Value | Description |
| --- | --- |
| 8 | Octal |
| 10 | Decimal |
| 16 | Hexadecimal |

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

When the radix is changed, the engine notifies the event callbacks by passing the DEBUG_CES_RADIX flag to the [IDebugEventCallbacks::ChangeEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-changeenginestate) callback method.

For more information about the default radix, see [Using Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-input-and-output).

## See also

[GetRadix](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getradix)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[n (Set Number Base)](https://learn.microsoft.com/windows-hardware/drivers/debugger/n--set-number-base-)