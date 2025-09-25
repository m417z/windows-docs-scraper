# IDebugBreakpoint::GetType

## Description

The **GetType** method returns the type of the breakpoint and the type of the processor that a breakpoint is set for.

## Parameters

### `BreakType` [out]

The type of the breakpoint. The type can be one of the following values.

| Value | Description |
| --- | --- |
| DEBUG_BREAKPOINT_CODE | Software breakpoint |
| DEBUG_BREAKPOINT_DATA | Processor breakpoint |

### `ProcType` [out]

The type of the processor that the breakpoint is set for.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

If changes are made to the breakpoint, the processor type might change.

The [GetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getparameters) method also returns the information that is returned in *BreakType* and *ProcType*.

For more information about breakpoint types, see [Breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/breakpoints3).