# PROTOCOL_NET_PNP_EVENT callback function

## Description

NDIS calls the
*ProtocolNetPnPEvent* function to indicate a network Plug and Play event, an NDIS
PnP event, or a power management event to a protocol driver.

**Note** You must declare the function by using the **PROTOCOL_NET_PNP_EVENT** type. For more
information, see the following Examples section.

## Parameters

### `ProtocolBindingContext` [in]

The handle to a protocol-driver-allocated context area in which this driver maintains per-binding
run-time state information. The protocol driver supplied this handle when it called the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function. A
**NetEvent***Xxx* event that is indicated with a **NULL***ProtocolBindingContext* applies to all bindings.
**NetEventBindList** and
**NetEventBindsComplete** are always indicated with a **NULL***ProtocolBindingContext*.
**NetEventReconfigure** can be indicated with a specified
*ProtocolBindingContext* or with a **NULL***ProtocolBindingContext*.

### `NetPnPEventNotification` [in]

A pointer to a
[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification) structure which describes the Plug and Play event or Power Management
event that NDIS is indicating to the protocol driver.

## Return value

*ProtocolNetPnPEvent* can return any of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The protocol driver successfully handled the indicated network Plug and Play event, NDIS PnP event, or power management event. The meaning of this status code depends on the **NetEvent** code in the buffered [NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification) structure at *NetPnPEvent*:<br><br>**NetEventSetPower**<br><br>The protocol driver has performed any driver-specific actions that are required to prepare for the device's transition to the requested device power state.<br><br>**NetEventQueryPower**<br><br>The underlying adapter can transition to the requested device power state.<br><br>**NetEventQueryRemoveDevice**<br><br>The underlying adapter can be removed.<br><br>**NetEventCancelRemoveDevice**<br><br>The protocol driver has performed any driver-specific actions that are required to prepare for the canceled removal of the underlying adapter.<br><br>**NetEventReconfigure**<br><br>The protocol driver has accepted the changed configuration.<br><br>**NetEventBindList**<br><br>The protocol driver has the new bind list and has performed related processing.<br><br>**NetEventBindsComplete**<br><br>The protocol driver has acknowledged the indication from NDIS that the protocol driver is bound to all available underlying adapters.<br><br>**NetEventPnPCapabilities**<br><br>The protocol driver has acknowledged that it has received the current wake-up capabilities of the underlying adapter that is associated with the specified binding.<br><br>**NetEventPause**<br><br>The specified protocol binding has entered the *Pausing* state. The binding will enter the *Paused* state after NDIS has completed all of the outstanding send requests for the binding. For more information about pause operations, see [Pausing a Binding](https://learn.microsoft.com/windows-hardware/drivers/network/pausing-a-binding).<br><br>**NetEventRestart**<br><br>The specified protocol binding has entered the *Restarting* state. After the protocol driver is ready to resume send and receive operations for the binding, the binding enters the *Running* state.<br><br>**NetEventPortActivation**<br><br>The protocol driver has acknowledged the activation of a port that is associated with the specified binding. For more information about port activation, see [Activating an NDIS Port](https://learn.microsoft.com/windows-hardware/drivers/network/activating-an-ndis-port).<br><br>**NetEventPortDeactivation**<br><br>The protocol driver has acknowledged the activation of a port that is associated with the specified binding. |
| **NDIS_STATUS_PENDING** | The protocol driver will return its response to the indicated event asynchronously with a call to the [NdisCompleteNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscompletenetpnpevent) function. |
| **NDIS_STATUS_RESOURCES** | The protocol driver could not obtain the necessary system resources to satisfy the indicated Plug and Play or Power Management event. |
| **NDIS_STATUS_NOT_SUPPORTED** | NDIS 6.0 and later protocol drivers must not return this status. An NDIS 5.*x* protocol driver that does not support Plug and Play can return this status in response to a **NetEventSetPower** to indicate that NDIS should unbind it from the underlying adapter. |
| **NDIS_STATUS_FAILURE** | The protocol driver failed the indicated event for reasons other than those stated in the preceding list. |

A protocol driver can fail the
**NetEventQueryRemoveDevice**
and
**NetEventPortActivation** events.

If a protocol driver fails the
**NetEventPortActivation** event, it should not use any associated ports in
subsequent operations.

A protocol driver should always succeed the
**NetEventRestart**, **NetEventIMReEnableDevice**,
**NetEventCancelRemoveDevice**,
**NetEventReconfigure**,
**NetEventBindList**,
**NetEventBindsComplete**,
**NetEventPause**, **NetEventPortDeactivation**, and
**NetEventPnPCapabilities** events by returning NDIS_STATUS_SUCCESS.

## Remarks

The
*ProtocolNetPnPEvent* function is required in protocol drivers to support Plug
and Play and Power Management. NDIS calls
*ProtocolNetPnPEvent* to notify a protocol driver that a network Plug and Play
event, an NDIS PnP event, or Power Management event has occurred.

The
[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification) structure that is passed to
*ProtocolNetPnPEvent* describes the event.
*ProtocolNetPnPEvent* interprets two basic pieces of information in the
NET_PNP_EVENT_NOTIFICATION structure:

* A code in the
  **NetEvent** member that identifies the type of Plug and Play or Power
  Management event.
* Event-specific information. For example, with a
  **NetEventSetPower** event the
  **Buffer** member contains the device power state to which the device is
  transitioning.

The protocol driver should save the
*NetPnPEvent* pointer. This pointer is a required input parameter to the
[NdisCompleteNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscompletenetpnpevent) function,
which the protocol driver must subsequently call if
*ProtocolNetPnPEvent* returns NDIS_STATUS_PENDING.

A protocol driver should always succeed a
**NetEventQueryPower** event. After establishing an active connection, a
protocol driver can call the
[PoRegisterSystemState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poregistersystemstate) function to
register a continuously busy state. As long as the state registration is in effect, the power manager
does not attempt to put the system to sleep. After the connection becomes inactive, the protocol driver
cancels the state registration by calling the
[PoUnregisterSystemState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-pounregistersystemstate) function. A
protocol driver should never try to prevent the system from transitioning to the sleeping state by
failing a
**NetEventQueryPower** event. Note that a
**NetEventQueryPower** event is always followed by a
**NetEventSetPower** event. A
**NetEventSetPower** event that specifies the underlying device's current power
state in effect cancels the
**NetEventQueryPower** event.

If a protocol driver cannot release a device (for example, because the device is in use) it must fail
a
**NetEventQueryRemoveDevice** event by returning NDIS_STATUS_FAILURE.

A protocol driver should always succeed a
**NetEventCancelRemoveDevice**, a
**NetEventReconfigure**,
**NetEventBindList, NetEventBindsComplete**,
**NetEventPnPCapabilities**,
**NetEventPause**, or
**NetEventPortDeactivation** by returning NDIS_STATUS_SUCCESS.

When handling a
**NetEventReconfigure** or a
**NetEventBindList**, a protocol driver should validate the data associated
with the event. For more information about such data, see
[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification).

NDIS calls
*ProtocolNetPnPEvent* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *ProtocolNetPnPEvent* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolNetPnPEvent* function that is named "MyNetPnPEvent", use the **PROTOCOL_NET_PNP_EVENT** type as shown in this code example:

```
PROTOCOL_NET_PNP_EVENT MyNetPnPEvent;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyNetPnPEvent(
    NDIS_HANDLE  ProtocolBindingContext,
    PNET_PNP_EVENT_NOTIFICATION  NetPnPEvent
    )
  {...}
```

The **PROTOCOL_NET_PNP_EVENT** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_NET_PNP_EVENT** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification)

[NdisCompleteNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscompletenetpnpevent)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[PoRegisterSystemState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poregistersystemstate)

[PoUnregisterSystemState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-pounregistersystemstate)