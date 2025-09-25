# IDebugControl2::GetBreakpointById

## Description

The **GetBreakpointById** method returns the breakpoint with the specified breakpoint ID.

## Parameters

### `Id` [in]

Specifies the breakpoint ID of the breakpoint to return.

### `Bp` [out]

Receives the breakpoint.

## Return value

This method can also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | No breakpoint was found with the given ID, or the breakpoint with the specified ID does not belong to the current process, or the breakpoint with the given ID is private (see [GetFlags](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getflags)). |

## Remarks

If the specified breakpoint does not belong to the current process, the method will fail.

## See also

[IDebugBreakpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugbreakpoint)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)