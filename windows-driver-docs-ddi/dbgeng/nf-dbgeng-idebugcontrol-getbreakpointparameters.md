# IDebugControl::GetBreakpointParameters

## Description

The **GetBreakpointParameters** method returns the parameters of one or more [breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/breakpoints3).

## Parameters

### `Count` [in]

Specifies the number of breakpoints whose parameters are being requested.

### `Ids` [in, optional]

Specifies an array containing the IDs of the breakpoints whose parameters are being requested. The number of items in this array must be equal to the value specified in *Count*. If *Ids* is **NULL**, *Start* is used instead.

### `Start` [in]

Specifies the beginning index of the breakpoints whose parameters are being requested. The parameters for breakpoints with indices *Start* through *Start* plus *Count* minus one will be returned. *Start* is used only if *Ids* is **NULL**.

### `Params` [out]

Receives the parameters for the specified breakpoints. The size of this array is equal to the value of *Count*. For details on the structure returned, see [DEBUG_BREAKPOINT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_breakpoint_parameters).

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the parameters for some of the breakpoints were not returned. The parameters that were not returned have their **Id** field set to DEBUG_ANY_ID. |

## Remarks

Some of the parameters might not be returned. This happens if either a breakpoint could not be found or a breakpoint is private (see [GetFlags](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getflags)).

## See also

[GetBreakpointById](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getbreakpointbyid)

[GetBreakpointByIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getbreakpointbyindex)

[GetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getparameters)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)