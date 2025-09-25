# IDebugControl5::GetBreakpointByGuid

## Description

The GetBreakpointByGuid method returns the breakpoint with the specified breakpoint GUID.

## Parameters

### `Guid` [in]

Specifies the breakpoint GUID of the breakpoint to return.

### `Bp` [out]

Receives the breakpoint.

## Return value

This method can also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | No breakpoint was found with the given GUID, or the breakpoint with the specified GUID does not belong to the current process, or the breakpoint with the given GUID is private (see [GetFlags](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getflags)). |

## See also

[Controlling Breakpoint Flags and Parameters](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-breakpoint-flags-and-parameters)

[IDebugControl5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol5)