# MINIPORT_RESET callback function

## Description

> [!WARNING]
> The *MiniportResetEx* and [*MiniportCheckForHangEx*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_check_for_hang) callback functions are discouraged for all NDIS 6.83 and later drivers. For more information, see [Check-for-Hang and Reset operations in NDIS 6.83 and later](https://learn.microsoft.com/windows-hardware/drivers/network/miniport-adapter-check-for-hang-and-reset-operations#check-for-hang-and-reset-operations-in-ndis-683-and-later).

NDIS calls an NDIS miniport driver's
*MiniportResetEx* function to initiate a reset of a network interface card (NIC). For more information, see [Miniport Adapter Check-for-Hang and Reset Operations](https://learn.microsoft.com/windows-hardware/drivers/network/miniport-adapter-check-for-hang-and-reset-operations) and [Miniport Driver Hardware Reset](https://learn.microsoft.com/windows-hardware/drivers/network/hardware-reset).

**Note** An NDIS miniport driver may declare this function by using the **MINIPORT_RESET** type.

## Parameters

### `MiniportAdapterContext` [in]

A handle to a context area that the miniport driver allocated in its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
The miniport driver uses this context area to maintain state information for a miniport adapter.

### `AddressingReset` [out]

A pointer to a Boolean variable. The miniport driver sets this variable to **TRUE** if NDIS should call the
[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function to
restore addressing and other configuration settings to the current values. For more information, see
[Hardware Reset](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff546572(v=vs.85)).

## Return value

*MiniportResetEx* can return one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | [MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset) successfully reset the miniport adapter to an operational state. |
| **NDIS_STATUS_PENDING** | The driver will complete the reset operation asynchronously by calling the [NdisMResetComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismresetcomplete) function when the operation is done. |
| **NDIS_STATUS_RESET_IN_PROGRESS** | [MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset) determined that the miniport adapter was currently being reset, so this call is superfluous. |
| **NDIS_STATUS_SOFT_ERRORS** | *MiniportResetEx* successfully reset the miniport adapter but a recoverable error occurred during the operation. *MiniportResetEx* should have called the [NdisWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteerrorlogentry) function with more information about the error. |
| **NDIS_STATUS_HARD_ERRORS** | *MiniportResetEx* tried to reset the miniport adapter but an unrecoverable error occurred during the operation. *MiniportResetEx* should have called **NdisWriteErrorLogEntry** with more information about the error. |

## Remarks

A driver specifies the
*MiniportResetEx* entry point when it calls the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function.

*MiniportResetEx* is not required for intermediate drivers.

*MiniportResetEx* can reset the parameters of the miniport adapter. If a reset causes a change in the
miniport adapter's station address, the miniport driver automatically restores the prior value of the
station address after the reset is complete. Any multicast or functional addressing masks, reset by the
hardware, do not have to be reset in this function.

If a reset operation changes other information, such as multicast or functional addressing
information,
*MiniportResetEx* must set the variable at
*AddressingReset* to **TRUE** before it returns. This causes NDIS to call the
[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function to
restore the information. NDIS also restores the Wake on the LAN (WoL) pattern list by calling
[OID_PNP_ADD_WAKE_UP_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-add-wake-up-pattern). The
driver should free the WoL pattern list from its adapter context because the hardware list is already
reset.

NDIS will not abort any pending OID requests or send requests. If the driver can safely complete
pending OID or send requests after a reset, the driver can hold pending OID or send requests until after
the reset operation is complete. Otherwise, the driver should complete the pending OID or send requests
by calling the
[NdisMOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismoidrequestcomplete) or
[NdisMSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsendnetbufferlistscomplete) functions respectively before
*MiniportResetEx* returns.

**Note** Starting with NDIS 6.30, the miniport driver must not hold pending OID or send requests until after
the reset operation is complete. Instead, the driver must complete these pending requests
by calling the
[NdisMOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismoidrequestcomplete) or
[NdisMSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsendnetbufferlistscomplete) functions respectively before
the reset operation is complete. If the driver completes the reset operation asynchronously, it must complete pending OID and send requests before the driver calls [NdisMResetComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismresetcomplete).

A miniport driver should not call the
[NdisMIndicateStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatestatusex) function to
signal the start and finish of each reset operation. NDIS notifies bound protocol drivers when a reset
begins and ends.

If
*MiniportResetEx* must wait for state changes in the miniport adapter during reset operations, it can
call the
[NdisStallExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisstallexecution) function. However, a
*MiniportResetEx* function must not call
**NdisStallExecution** with a time interval larger than 50 microseconds. If the driver must wait longer
than 50 microseconds (or if would poll), it should set a timer instead and return
NDIS_STATUS_PENDING.

If
*MiniportResetEx* returns NDIS_STATUS_PENDING, the driver must complete the reset by calling the
[NdisMResetComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismresetcomplete) function.

If a miniport adapter is in the
**MediaConnectStateConnected** state and its state changes because of a reset, including a change to
the
**MediaConnectStateUnknown** state, the miniport driver must report the state change with an
[NDIS_STATUS_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-link-state) status
indication. The miniport driver must also indicate a
**MediaConnectStateConnected** status indication when the link is reestablished after the reset.

*MiniportResetEx* can be preempted by an interrupt.

NDIS calls the
[MiniportCheckForHangEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_check_for_hang) function
periodically to determine whether it should call
*MiniportResetEx*. The default time-out for calling
*MiniportCheckForHangEx* is 2 seconds. If this default is too short, a miniport driver can set a larger **CheckForHangTimeInSeconds** value when calling the
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function during initialization. For more information, see [Miniport Adapter Check-for-Hang and Reset Operations](https://learn.microsoft.com/windows-hardware/drivers/network/miniport-adapter-check-for-hang-and-reset-operations).

NDIS cannot determine whether a NIC has stopped responding for receive operations. To handle this kind
of failure, the
*MiniportCheckForHangEx* function can monitor receive operations and, if necessary, return **TRUE** to
force a reset. A miniport can also request a reset by calling [NdisMResetMiniport](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismresetminiport).

NDIS calls
*MiniportResetEx* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *MiniportResetEx* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportResetEx* function that is named "MyResetEx", use the **MINIPORT_RESET** type as shown in this code example:

```
MINIPORT_RESET MyResetEx;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyResetEx(
    NDIS_HANDLE  MiniportAdapterContext,
    PBOOLEAN  AddressingReset
    )
  {...}
```

The **MINIPORT_RESET** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_RESET** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[Miniport Adapter Check-for-Hang and Reset Operations](https://learn.microsoft.com/windows-hardware/drivers/network/miniport-adapter-check-for-hang-and-reset-operations)

[Miniport Driver Hardware Reset](https://learn.microsoft.com/windows-hardware/drivers/network/hardware-reset)

[MiniportCheckForHangEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_check_for_hang)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request)

[NDIS_STATUS_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-link-state)

[NdisMIndicateStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatestatusex)

[NdisMOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismoidrequestcomplete)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisMResetComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismresetcomplete)

[NdisMResetMiniport](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismresetminiport)

[NdisMSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsendnetbufferlistscomplete)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[NdisStallExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisstallexecution)

[NdisWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteerrorlogentry)