# IDebugControl2::GetRadix

## Description

The **GetRadix** method returns the default radix (number base) used by the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) when it evaluates and displays MASM expressions, and when it displays symbol information.

## Parameters

### `Radix` [out]

Receives the default radix.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about the default radix, see [Using Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-input-and-output).

## See also

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetRadix](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setradix)

[n (Set Number Base)](https://learn.microsoft.com/windows-hardware/drivers/debugger/n--set-number-base-)