# MINIPORT_PAUSE callback function

## Description

NDIS calls a miniport driver's
*MiniportPause* function to stop the flow of network data through a specified miniport adapter.

**Note** You must declare the function by using the **MINIPORT_PAUSE** type. For more
information, see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

A handle to a context area that the miniport driver allocated in its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
The miniport driver uses this context area to maintain state information for a miniport adapter.

### `PauseParameters` [in]
A pointer to an
[NDIS_MINIPORT_PAUSE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_pause_parameters) structure that defines the pause parameters for the miniport
adapter.

## Return value

*MiniportPause* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | *MiniportPause* successfully stopped the flow of network data through the miniport adapter. |
| **NDIS_STATUS_PENDING** | *MiniportPause* did not complete the pause operation and the operation will be completed asynchronously. The miniport driver must call the [NdisMPauseComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismpausecomplete) function when the operation is complete. |

## Remarks

A driver specifies the
*MiniportPause* entry point when it calls the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function.

NDIS pauses a miniport adapter to stop data flow that could interfere with PnP operations such as
adding or removing a filter driver, or binding or unbinding a protocol driver.

NDIS calls a miniport driver's
*MiniportPause* function to initiate a pause request for the miniport adapter specified at
*MiniportAdapterContext*. The miniport adapter remains in the
*Pausing* state until the pause operation is complete.

For a miniport adapter in the
*Pausing* state, the miniport driver:

* Waits for all calls to the
  [NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists) function to return.
* Waits for NDIS to return the ownership of all
  [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures from
  outstanding receive indications to the miniport driver's
  [MiniportReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_return_net_buffer_lists) function.
* Completes all outstanding send requests and calls the
  [NdisMSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsendnetbufferlistscomplete) function for all the outstanding send requests.
* Rejects all new send requests made to its
  [MiniportSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_send_net_buffer_lists) function immediately by calling
  **NdisMSendNetBufferListsComplete**. It should set the complete status in each NET_BUFFER_LIST to
  NDIS_STATUS_PAUSED.
* Can provide status indications with the
  [NdisMIndicateStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatestatusex) function.
* Should handle OID requests in the
  [MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function.
* Should not stop the miniport adapter completely if stopping the miniport adapter prevents the driver
  from handling requests or providing status indications.
* Should not free the resources the driver allocated during initialization.

NDIS does not initiate other PnP operations for the miniport adapter, such as halt, initialize, power
change, pause, or a restart requests, while the miniport adapter is in the
*Pausing* state. NDIS can initiate these PnP operations after a miniport adapter is in the
*Paused* state.

After a miniport driver completes all outstanding send requests and NDIS returns all received network
data structures (from outstanding receive indications), the driver must complete the pause operation. If
the driver returns NDIS_STATUS_SUCCESS from
*MiniportPause*, the pause operation is complete. If the driver returns NDIS_STATUS_PENDING, the
miniport adapter can remain in the
*Pausing* state and the pause operation is complete after the driver calls the
[NdisMPauseComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismpausecomplete) function. After the
pause operation is complete, the miniport adapter is in the
*Paused* state.

For a miniport adapter in the
*Paused* state, the miniport driver:

* Must reject all send requests made to
  *MiniportSendNetBufferLists* immediately by calling
  **NdisMSendNetBufferListsComplete**. It should set the Status member in each NET_BUFFER_LIST to
  NDIS_STATUS_PAUSED.
* Can handle receive interrupts (see the
  [MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) function) and
  interrupt DPCs (see the
  [MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc) function),
  but should not indicate received network data.
* Can provide status indications with the
  **NdisMIndicateStatusEx** function.
* Should handle OID requests in the
  *MiniportOidRequest* function.
* Should handle requests to change the device power state in the
  [MiniportDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_device_pnp_event_notify) function.
* Can handle calls to
  [NetTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_timer_function) functions.
* Can handle requests to reset the hardware in the
  [MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset) function.

Miniport drivers cannot fail a pause request. Therefore, if a miniport driver requires any resources
to handle a pause request, it should preallocate the resources during initialization.

NDIS calls the
[MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart) function to initiate a
restart request for a miniport adapter that is paused.

NDIS calls
*MiniportPause* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *MiniportPause* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportPause* function that is named "MyPause", use the **MINIPORT_PAUSE** type as shown in this code example:

```
MINIPORT_PAUSE MyPause;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyPause(
    NDIS_HANDLE  MiniportAdapterContext,
    PNDIS_MINIPORT_PAUSE_PARAMETERS  MiniportPauseParameters
    )
  {...}
```

The **MINIPORT_PAUSE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_PAUSE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_device_pnp_event_notify)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr)

[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc)

[MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset)

[MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart)

[MiniportReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_return_net_buffer_lists)

[MiniportSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_send_net_buffer_lists)

[NDIS_MINIPORT_PAUSE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_pause_parameters)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists)

[NdisMIndicateStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatestatusex)

[NdisMPauseComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismpausecomplete)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisMSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsendnetbufferlistscomplete)

[NetTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_timer_function)