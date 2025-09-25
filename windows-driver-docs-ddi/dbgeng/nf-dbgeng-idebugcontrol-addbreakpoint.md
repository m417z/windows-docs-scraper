# IDebugControl::AddBreakpoint

## Description

The **AddBreakpoint** method creates a new breakpoint for the current target.

## Parameters

### `Type` [in]

Specifies the breakpoint type of the new breakpoint. This can be either of the following values:

| Value | Description |
| --- | --- |
| DEBUG_BREAKPOINT_CODE | [software breakpoint](https://learn.microsoft.com/windows-hardware/drivers/debugger/s) |
| DEBUG_BREAKPOINT_DATA | [processor breakpoint](https://learn.microsoft.com/windows-hardware/drivers/debugger/p) |

### `DesiredId` [in]

Specifies the desired ID of the new breakpoint. If it is DEBUG_ANY_ID, the engine will pick an unused ID.

### `Bp` [out]

Receives an interface pointer to the new breakpoint.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | The breakpoint couldn't be created with the desired ID or the value of *Type* was not recognized. |

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

If *DesiredId* is not DEBUG_ANY_ID and another breakpoint already uses the ID *DesiredId*, these methods will fail.

Breakpoints are created empty and disabled. See [Using Breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-breakpoints2) for details on configuring and enabling the breakpoint.

The client is saved as the adder of the new breakpoint. See [GetAdder](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugbreakpoint2-getadder).

**Note** Even though [IDebugBreakpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugbreakpoint) extends the COM interface **IUnknown**, the lifetime of the breakpoint is not controlled using the **IUnknown** interface. Instead, the breakpoint is deleted after [RemoveBreakpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-removebreakpoint) is called.

## See also

[Breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/breakpoints3)

[IDebugBreakpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugbreakpoint)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[RemoveBreakpoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-removebreakpoint)

[Using Breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-breakpoints2)