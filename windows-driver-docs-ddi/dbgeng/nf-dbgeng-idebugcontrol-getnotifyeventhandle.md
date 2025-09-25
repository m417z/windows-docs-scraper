# IDebugControl::GetNotifyEventHandle

## Description

The **GetNotifyEventHandle** method receives the handle of the event that will be signaled after the next [exception](https://learn.microsoft.com/windows-hardware/drivers/) in a target.

## Parameters

### `Handle` [out]

Receives the handle of the event that will be signaled. If *Handle* is **NULL**, no event will be signaled.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

If an event to be signaled was set and an exception occurs in a target, when the engine resumes execution in the target again, the event will be signaled.

The event will only be signaled once. After it has been signaled, this method will return **NULL** to *Handle*, unless [SetNotifyEventHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setnotifyeventhandle) is called to set another event to signal.

## See also

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetNotifyEventHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setnotifyeventhandle)