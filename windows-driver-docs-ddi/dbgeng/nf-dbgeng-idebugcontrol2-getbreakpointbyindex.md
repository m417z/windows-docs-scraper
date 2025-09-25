# IDebugControl2::GetBreakpointByIndex

## Description

The **GetBreakpointByIndex** method returns the breakpoint located at the specified index.

## Parameters

### `Index` [in]

Specifies the zero-based index of the breakpoint to return. This is specific to the current process. The value of *Index* should be between zero and the total number of breakpoints minus one. The total number of breakpoints can be determined by calling [GetNumberBreakpoints](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getnumberbreakpoints).

### `Bp` [out]

Receives the returned breakpoint.

## Return value

This method can also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | No breakpoint was found with the given index, or the breakpoint with the given index is private. |

## Remarks

The index and returned breakpoint are specific to the current process. The same index will return a different breakpoint if the current process is changed.

## See also

[GetNumberBreakpoints](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getnumberbreakpoints)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)