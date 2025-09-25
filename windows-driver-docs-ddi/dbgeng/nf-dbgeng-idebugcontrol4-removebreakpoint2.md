# IDebugControl4::RemoveBreakpoint2

## Description

The **RemoveBreakpoint2** method removes a breakpoint.

## Parameters

### `Bp` [in]

Specifies an interface pointer to breakpoint to remove.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

After **RemoveBreakpoint** and **RemoveBreakpoint2** are called, the breakpoint object specified in the *Bp* parameter must not be used again.

**Note** Even though [IDebugBreakpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugbreakpoint) extends the COM interface **IUnknown**, the lifetime of the breakpoint is not controlled using the **IUnknown** interface. Instead, the breakpoint is deleted after **RemoveBreakpoint** and **RemoveBreakpoint2** are called.

For more details, see [Using Breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-breakpoints2).

## See also

[AddBreakpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-addbreakpoint)

[IDebugBreakpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugbreakpoint)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)