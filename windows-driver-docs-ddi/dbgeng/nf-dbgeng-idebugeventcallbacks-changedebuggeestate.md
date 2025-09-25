# IDebugEventCallbacks::ChangeDebuggeeState

## Description

The **ChangeDebuggeeState** callback method is called by the engine when it makes or detects changes to the target.

## Parameters

### `Flags` [in]

Specifies the type of changes made to the target. *Flags* may take one of the following values:

| Value | Description |
| --- | --- |
| DEBUG_CDS_ALL | A general change in the target has occurred. For example, the target has been executing, or the engine has just attached to the target. |
| DEBUG_CDS_REGISTERS | The processor registers for the target have changed. |
| DEBUG_CDS_DATA | The target's data space has changed. |
| DEBUG_CDS_REFRESH | Inform the GUI clients to refresh debugger windows. |

### `Argument` [in]

Provides additional information about the change in the target. The interpretation of the value of *Argument* depends on the value of *Flags*:

DEBUG_CDS_ALL

The value of *Argument* is zero.

DEBUG_CDS_REGISTERS

If a single register has changed, the value of *Argument* is the index of that register. Otherwise, the value of *Argument* is DEBUG_ANY_ID.

DEBUG_CDS_DATA

The value of *Argument* specifies which data space was changed. The following table contains the possible values of *Argument*.

| Value | Description |
| --- | --- |
| DEBUG_DATA_SPACE_VIRTUAL | The target's virtual memory has changed. |
| DEBUG_DATA_SPACE_PHYSICAL | The target's physical memory has changed. |
| DEBUG_DATA_SPACE_CONTROL | The target's control memory has changed. |
| DEBUG_DATA_SPACE_IO | The target's I/O ports have received input or output. |
| DEBUG_DATA_SPACE_MSR | The target's Model-Specific Registers (MSRs) have changed. |
| DEBUG_DATA_SPACE_BUS_DATA | The target's bus memory has changed. |

DEBUG_CDS_REFRESH

The following table contains the possible values of *Argument*.

| Value |
| --- |
| DEBUG_CDS_REFRESH_EVALUATE |
| DEBUG_CDS_REFRESH_EXECUTE |
| DEBUG_CDS_REFRESH_EXECUTECOMMANDFILE |
| DEBUG_CDS_REFRESH_ADDBREAKPOINT |
| DEBUG_CDS_REFRESH_REMOVEBREAKPOINT |
| DEBUG_CDS_REFRESH_WRITEVIRTUAL |
| DEBUG_CDS_REFRESH_WRITEVIRTUALUNCACHED |
| DEBUG_CDS_REFRESH_WRITEPHYSICAL |
| DEBUG_CDS_REFRESH_WRITEPHYSICAL2 |
| DEBUG_CDS_REFRESH_SETVALUE |
| DEBUG_CDS_REFRESH_SETVALUE2 |
| DEBUG_CDS_REFRESH_SETSCOPE |
| DEBUG_CDS_REFRESH_SETSCOPEFRAMEBYINDEX |
| DEBUG_CDS_REFRESH_SETSCOPEFROMJITDEBUGINFO |
| DEBUG_CDS_REFRESH_SETSCOPEFROMSTOREDEVENT |
| DEBUG_CDS_REFRESH_INLINESTEP |
| DEBUG_CDS_REFRESH_INLINESTEP_PSEUDO |

## Return value

The return value is ignored by the engine unless it indicates a remote procedure call error; in this case the client, with which this **IDebugEventCallbacks** object is registered, is disabled.

## Remarks

The engine calls **ChangeDebuggeeState** only if the DEBUG_EVENT_CHANGE_DEBUGGEE_STATE flag is set in the mask returned by [IDebugEventCallbacks::GetInterestMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-getinterestmask).

For more information about handling events, see [Monitoring Events](https://learn.microsoft.com/windows-hardware/drivers/debugger/monitoring-events). For information about managing the target's memory, including registers and data spaces, see [Memory Access](https://learn.microsoft.com/windows-hardware/drivers/debugger/memory-access). For information about the target's virtual and physical memory, see [Virtual and Physical Memory](https://learn.microsoft.com/windows-hardware/drivers/debugger/virtual-and-physical-memory). For information about the target's control memory, I/O ports, MSR, and bus memory, see [Other Data Spaces](https://learn.microsoft.com/windows-hardware/drivers/debugger/other-data-spaces).