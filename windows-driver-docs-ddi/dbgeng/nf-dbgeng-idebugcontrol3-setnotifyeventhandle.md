# IDebugControl3::SetNotifyEventHandle

## Description

The **SetNotifyEventHandle** method sets the event that will be signaled after the next [exception](https://learn.microsoft.com/windows-hardware/drivers/) in a target.

## Parameters

### `Handle` [in]

Specifies the handle of the event to signal. If *Handle* is **NULL**, no event will be signaled.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

After setting the event to signal, and after the next exception occurs in a target, when the engine resumes execution in the target, the event will be signaled.

The event will only be signaled once. After it has been signaled, **GetNotifyEventHandle** will return **NULL**, unless this method is called to set another event to signal.

## See also

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetNotifyEventHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setnotifyeventhandle)