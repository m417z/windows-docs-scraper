# IDebugControl3::GetInterrupt

## Description

The **GetInterrupt** method checks whether a user interrupt was issued.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful and an interrupt has been requested. |
| **S_FALSE** | The method was successful and an interrupt was not requested. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

If a user interrupt was issued, it is cleared when this method is called.

Examples of user interrupts include pressing Ctrl+C or pressing the **Stop** button in a debugger. Calling [SetInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setinterrupt) also causes a user interrupt.

**Note** It is recommended that debugger extensions call **GetInterrupt** while undertaking long tasks.

This method can be called at any time and from any thread.

## See also

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setinterrupt)