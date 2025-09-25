# _NET_PNP_EVENT structure (netpnp.h)

## Description

The **NET_PNP_EVENT** structure describes a network Plug and Play (PnP) event, an NDIS PnP event, or a
power management event.

## Members

### `NetEvent`

An event code that describes the event as one of the following:

#### NetEventSetPower

Indicates that the power manager has sent a Set Power request, which specifies a transition to a
system power state. NDIS translates this state to an appropriate device power state for the
device.

For more information, see the Remarks section.

#### NetEventQueryPower

Indicates that the power manager has sent a Query Power request, which requests a transition to
a system power state. NDIS translates this state to an appropriate device power state for the
device.

For more information, see the Remarks section.

#### NetEventQueryRemoveDevice

Indicates that the PnP Manager has sent a Query Remove Device request. The PnP Manager sends
this request to query whether a device can be removed without disrupting operations.

#### NetEventCancelRemoveDevice

Indicates that the PnP Manager has sent a Cancel Remove Device request. The PnP Manager sends
this request to cancel the removal of a device after the PnP Manager sends a Query Remove Device request.

#### NetEventReconfigure

Indicates that the configuration has changed for a network component. For example, if a user,
through the Network and Dial-up Connections folder, changes the IP address for TCP/IP, NDIS indicates
the
**NetEventReconfigure** event to the TCP/IP protocol. Also, an intermediate driver typically uses
this event as a trigger to call the
[NdisIMInitializeDeviceInstanceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisiminitializedeviceinstanceex) function and start its virtual miniports. For more information
about
**NetEventReconfigure**, see
NetEventIMReEnableDevice.

#### NetEventBindList

Indicates to a protocol driver that its bind list processing order has been reconfigured. This
list indicates a relative order that applies to bindings when processing, for example, a user request
that might be routed to one of several bindings. The buffer that is passed with this event contains a
list of device names that are formatted as null-terminated Unicode strings. The format of each device
name is identical to the
**AdapterName** member that is passed to a call to the
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function.

#### NetEventBindsComplete

Indicates that a protocol driver has bound to all the NICs that it can bind to. NDIS will not
indicate any more NICs to the protocol unless a PnP NIC is plugged into the system.

#### NetEventPnPCapabilities

Indicates that the user enabled or disabled the wake-up capabilities of the underlying adapter.
(The binding is specified by the
*ProtocolBindingContext* parameter that is passed to the
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function.)

#### NetEventPause

Indicates that the specified protocol binding should enter the
Pausing state. The binding will enter the
Paused state after NDIS has completed all the outstanding send requests for the
binding.

#### NetEventRestart

Indicates that the specified protocol binding has entered the
Restarting state. After the protocol driver is ready to resume send and receive operations for
the binding, the binding enters the
Running state.

#### NetEventPortActivation

Indicates the activation of a list of ports that are associated with the specified
binding.

#### NetEventPortDeactivation

Indicates the deactivation of a list of ports that are associated with the specified
binding.

#### NetEventIMReEnableDevice

Indicates that the configuration has changed for a virtual miniport of an NDIS 6.0 or later
intermediate driver.
**NetEventIMReEnableDevice** is similar to the
**NetEventReconfigure** event except that the intermediate driver receives this event for a single
virtual miniport and the
**NetEventReconfigure** event applies to all the intermediate driver's virtual miniports. For
example, an intermediate driver receives the
**NetEventIMReEnableDevice** event when a user disables and then enables a single virtual miniport
from the Device Manager or another source. For examples of intermediate driver power management, see the
[NDIS MUX Intermediate Driver and Notify Object](https://go.microsoft.com/fwlink/p/?LinkId=617916) driver sample available in the [Windows driver samples](https://go.microsoft.com/fwlink/p/?LinkId=616507) repository on GitHub.

#### NetEventNDKEnable

Indicates that Network Direct Kernel (NDK) is currently enabled.

#### NetEventNDKDisable

Indicates that NDK is currently disabled.

#### NetEventFilterPreDetach

Indicates that a filter is about to be detached, so that the filter can perform any necessary cleanup that isn't possible in the [FilterDetach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_detach) handler (because the OID and indication paths are closed at that time).

#### NetEventBindFailed

Indicates that a binding event failure has occurred.

#### NetEventSwitchActivate

Indicates that the Hyper-V Extensible Switch has completed activation, and switch extensions can now safely query for further switch configuration. The indication is only used in the Hyper-V Extensible Switch stack, issued by the extension miniport. See [Querying the Hyper-V Extensible Switch Configuration](https://learn.microsoft.com/windows-hardware/drivers/network/querying-the-hyper-v-extensible-switch-configuration) and [NDIS_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_parameters) for more details.

#### NetEventInhibitBindsAbove

A synchronous event that prevents other filters and protocols from binding to the miniport adapter. Any filters or protocols that were previously bound will be unbound before the event completes. The usage rules are below.

* Avoid leaving the miniport adapter in the inhibit state, for longer than 1000 milliseconds.
* This event can only be issued after [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) begins and must not be issued after [MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) returns.
* This event can only be issued when the miniport adapter is in a D0 state.
* Because this event is blocking, it should not be issued by any context that would cause a deadlock.
* Locks must not be held while issuing this event.
* This event must be issued at PASSIVE_LEVEL.

This event is available starting with NDIS version 6.50
and must be used with V2 or later version of **NET_PNP_EVENT**. This event can optionally be issued by a miniport driver. Protocols and filters cannot receive this event or issue it.

#### NetEventAllowBindsAbove

An asynchronous event that reverses the effects of NetEventInhibitBindsAbove. The usage rules are below.

* This event can only be issued after [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) begins and must not be issued after [MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) returns.
* This event can only be issued when the miniport adapter is in a D0 state.
* Locks must not be held while issuing this event.
* This event must be issued at PASSIVE_LEVEL.

This event is available starting with NDIS version 6.50 and must be used with V2 or later version of **NET_PNP_EVENT**. This event can optionally be issued by a miniport driver. Protocols and filters cannot receive this event or issue it.

#### NetEventRequirePause

A synchronous event that indicates the protocols and filters including the miniport adapter must be paused. The protocols and filters and the miniport adapter are guaranteed to be paused when the [NdisMNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismnetpnpevent) routine returns. The usage rules are below.

* Avoid delaying between NetEventAllowStart and NetEventRequirePause events for longer than 1000 milliseconds to prevent delay in user applications.
* This event can only be issued after [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) begins and must not be issued after [MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) returns.
* There is no guarantee that NDIS will call [MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause) after this event is issued. In particular, if your miniport adapter is already paused, NDIS won't introduce an extra start-pause loop. This means that the amount of times *MiniportPause* called is not greater than, less than, or equal to the amount this event is issued.
* Because this event is blocking, it should not be issued by any context that would cause a deadlock.
* Locks must not be held while issuing this event.

This event is available starting with NDIS version 6.50 and must be used with V2 or later version of **NET_PNP_EVENT**. This event can optionally be issued by a miniport driver. Protocols and filters cannot receive this event or issue it.

#### NetEventAllowStart

An asynchronous event that indicates the protocols and filters including the miniport adapter does not need to be paused. The usage rules are below. There is no guaranteed pause state for any driver in the protocols and filters after the [NdisMNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismnetpnpevent) routine returns.

* This event can only be issued after [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) begins and must not be issued after [MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) returns.
* Because this event is blocking, it should not be issued by any context that would cause a deadlock.
* Locks must not be held while issuing this event.

This event is available starting with NDIS version 6.50 and must be used with V2 or later version of **NET_PNP_EVENT**. This event can optionally be issued by a miniport driver. Protocols and filters cannot receive this event or issue it.

### `Buffer`

The address of a buffer that contains information that is specific to the event indicated in the
**NetEvent** member. For each type of event, the buffer contains the following information:

#### NetEventSetPower

The buffer contains the device power state to which the device is transitioning.

When NDIS calls a protocol driver's
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function,
the device state is NDIS_DEVICE_POWER_STATE, which can be one of the following values:

##### NdisDeviceStateUnspecified

The network device does not support power management.

##### NdisDeviceStateD0

The fully powered state, in which the device delivers full functionality and
performance.

##### NdisDeviceStateD1

A low-power state, in which transmit requests from the host are not honored by the device,
data received by the device is not transferred to host memory, and no interrupts can occur. Some
device context may be lost. Depending on the capabilities of the NIC and its miniport driver, the
device might be able to generate a wake-up signal.

##### NdisDeviceStateD2

A low-power state that is similar to
**NdisDeviceStateD1**, except that more power and less context are typically saved and more time
is required to transition to the fully powered state.

##### NdisDeviceStateD3

The off state, in which power has been fully removed from the device.

For protocol drivers,
**NdisDeviceStateD0** means that the NIC is fully powered and is available for normal operations.
Any other device state means that the device is not fully powered and is not available for sending and
receiving network data.

#### NetEventQueryPower

The buffer contains the device power state that is requested for the device. The device state is
NDIS_DEVICE_POWER_STATE (which is described in the
**NetEventSetPower** value description).

#### NetEventQueryRemoveDevice

The buffer contents are **NULL**.

#### NetEventCancelRemoveDevice

The buffer contents are **NULL**.

#### NetEventReconfigure

The buffer can contain protocol-specific data. The protocol driver is responsible for validating
this data.

#### NetEventBindList

The buffer contains a revised binding list for the network component that the
[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification) structure is being passed to. The bind list, which is a series of
null-terminated Unicode strings, has a REG_MULTI_SZ format. Each of the strings is an adapter name.
TDI clients that are bound to a protocol use this bind list to reorder their bindings. The protocol
driver is responsible for validating this list.

#### NetEventBindsComplete

The buffer contents are **NULL**.

#### NetEventPnPCapabilities

The buffer is a ULONG that contains a bitmask. When the NDIS_DEVICE_WAKE_UP_ENABLE flag is set
in the bitmask, the wake-up capabilities of the NIC are enabled. Otherwise, the NIC's wake-up
capabilities are disabled. (The binding is specified by the
*ProtocolBindingContext* parameter that is passed to
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event).) When set
to zero, this flag indicates that the NIC's wake-up capabilities are disabled.

#### NetEventPause

The buffer contains an
[NDIS_PROTOCOL_PAUSE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_pause_parameters) structure.

#### NetEventRestart

The buffer might contain NULL or an
[NDIS_PROTOCOL_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_restart_parameters) structure. NDIS provides a pointer to an
[NDIS_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_attributes) structure
in the
**RestartAttributes** member of the NDIS_PROTOCOL_RESTART_PARAMETERS structure.

**Note** If the buffer is NULL, the restart attributes have not changed since the previous restart.

#### NetEventPortActivation

The buffer contains the first entry in a list of
[NDIS_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port) structures that identify the ports
that NDIS will activate. You can use the
**Next** member of the NDIS_PORT structure to get the next structure in the list.

#### NetEventPortDeactivation

The buffer contains an array of port numbers, of type NDIS_PORT_NUMBER (defined as ULONG), that
identify the NDIS ports that NDIS will deactivate. To calculate the number of elements in the array,
divide the value of the
**BufferLength** member, which is in the **NET_PNP_EVENT** structure that is specified in the
**NetPnPEvent** member of
[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification),
by
sizeof(NDIS_PORT_NUMBER).

#### NetEventIMReEnableDevice

The buffer contains a pointer to a variable of type NDIS_STRING that contains a null-terminated
Unicode string that names the device object of a virtual miniport for the device that is being
enabled. The string is a full path name—for example,
\Device\\*DeviceName*.

#### NetEventNDKEnable

The **Buffer** member is **NULL**.

#### NetEventNDKDisable

The **Buffer** member is **NULL**.

#### NetEventFilterPreDetach

The **Buffer** member is **NULL**.

#### NetEventBindFailed

The buffer contains an [NDIS_BIND_FAILED_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_failed_notification) structure.

#### NetEventSwitchActivate

The buffer contents are NULL.

#### NetEventAllowBindsAbove

The buffer contents are NULL.

#### NetEventInhibitBindsAbove

The buffer contents are NULL.

#### NetEventAllowStart

The buffer contents are NULL.

#### NetEventRequirePause

The buffer contents are NULL.

### `BufferLength`

The number of bytes of event-specific information at
**Buffer**.

### `NdisReserved`

An area reserved for used by NDIS.

### `TransportReserved`

An area reserved for used by the transport driver.

### `TdiReserved`

An area reserved for used by TDI.

### `TdiClientReserved`

An area reserved for used by a TDI client.

##### - Buffer.NetEventAllowBindsAbove

The buffer contents are NULL.

##### - Buffer.NetEventAllowStart

The buffer contents are NULL.

##### - Buffer.NetEventBindFailed

The buffer contains an [NDIS_BIND_FAILED_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_failed_notification) structure.

##### - Buffer.NetEventBindList

The buffer contains a revised binding list for the network component that the
[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification) structure is being passed to. The bind list, which is a series of
null-terminated Unicode strings, has a REG_MULTI_SZ format. Each of the strings is an adapter name.
TDI clients that are bound to a protocol use this bind list to reorder their bindings. The protocol
driver is responsible for validating this list.

##### - Buffer.NetEventBindsComplete

The buffer contents are **NULL**.

##### - Buffer.NetEventCancelRemoveDevice

The buffer contents are **NULL**.

##### - Buffer.NetEventFilterPreDetach

The **Buffer** member is **NULL**.

##### - Buffer.NetEventIMReEnableDevice

The buffer contains a pointer to a variable of type NDIS_STRING that contains a null-terminated
Unicode string that names the device object of a virtual miniport for the device that is being
enabled. The string is a full path name—for example,
\Device\\*DeviceName*.

##### - Buffer.NetEventInhibitBindsAbove

The buffer contents are NULL.

##### - Buffer.NetEventNDKDisable

The **Buffer** member is **NULL**.

##### - Buffer.NetEventNDKEnable

The **Buffer** member is **NULL**.

##### - Buffer.NetEventPause

The buffer contains an
[NDIS_PROTOCOL_PAUSE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_pause_parameters) structure.

##### - Buffer.NetEventPnPCapabilities

The buffer is a ULONG that contains a bitmask. When the NDIS_DEVICE_WAKE_UP_ENABLE flag is set
in the bitmask, the wake-up capabilities of the NIC are enabled. Otherwise, the NIC's wake-up
capabilities are disabled. (The binding is specified by the
*ProtocolBindingContext* parameter that is passed to
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event).) When set
to zero, this flag indicates that the NIC's wake-up capabilities are disabled.

##### - Buffer.NetEventPortActivation

The buffer contains the first entry in a list of
[NDIS_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port) structures that identify the ports
that NDIS will activate. You can use the
**Next** member of the NDIS_PORT structure to get the next structure in the list.

##### - Buffer.NetEventPortDeactivation

The buffer contains an array of port numbers, of type NDIS_PORT_NUMBER (defined as ULONG), that
identify the NDIS ports that NDIS will deactivate. To calculate the number of elements in the array,
divide the value of the
**BufferLength** member, which is in the **NET_PNP_EVENT** structure that is specified in the
**NetPnPEvent** member of
[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification),
by
sizeof(NDIS_PORT_NUMBER).

##### - Buffer.NetEventQueryPower

The buffer contains the device power state that is requested for the device. The device state is
NDIS_DEVICE_POWER_STATE (which is described in the
**NetEventSetPower** value description).

##### - Buffer.NetEventQueryRemoveDevice

The buffer contents are **NULL**.

##### - Buffer.NetEventReconfigure

The buffer can contain protocol-specific data. The protocol driver is responsible for validating
this data.

##### - Buffer.NetEventRequirePause

The buffer contents are NULL.

##### - Buffer.NetEventRestart

The buffer might contain NULL or an
[NDIS_PROTOCOL_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_restart_parameters) structure. NDIS provides a pointer to an
[NDIS_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_attributes) structure
in the
**RestartAttributes** member of the NDIS_PROTOCOL_RESTART_PARAMETERS structure.

**Note** If the buffer is NULL, the restart attributes have not changed since the previous restart.

##### - Buffer.NetEventSetPower

The buffer contains the device power state to which the device is transitioning.

When NDIS calls a protocol driver's
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function,
the device state is NDIS_DEVICE_POWER_STATE, which can be one of the following values:

##### NetEventSetPower.NdisDeviceStateUnspecified

The network device does not support power management.

##### NetEventSetPower.NdisDeviceStateD0

The fully powered state, in which the device delivers full functionality and
performance.

##### NetEventSetPower.NdisDeviceStateD1

A low-power state, in which transmit requests from the host are not honored by the device,
data received by the device is not transferred to host memory, and no interrupts can occur. Some
device context may be lost. Depending on the capabilities of the NIC and its miniport driver, the
device might be able to generate a wake-up signal.

##### NetEventSetPower.NdisDeviceStateD2

A low-power state that is similar to
**NdisDeviceStateD1**, except that more power and less context are typically saved and more time
is required to transition to the fully powered state.

##### NetEventSetPower.NdisDeviceStateD3

The off state, in which power has been fully removed from the device.

For protocol drivers,
**NdisDeviceStateD0** means that the NIC is fully powered and is available for normal operations.
Any other device state means that the device is not fully powered and is not available for sending and
receiving network data.

##### - Buffer.NetEventSwitchActivate

The buffer contents are NULL.

##### - NetEvent.NetEventAllowBindsAbove

An asynchronous event that reverses the effects of NetEventInhibitBindsAbove. The usage rules are below.

* This event can only be issued after [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) begins and must not be issued after [MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) returns.
* This event can only be issued when the miniport adapter is in a D0 state.
* Locks must not be held while issuing this event.
* This event must be issued at PASSIVE_LEVEL.

This event is available starting with NDIS version 6.50 and must be used with V2 or later version of **NET_PNP_EVENT**. This event can optionally be issued by a miniport driver. Protocols and filters cannot receive this event or issue it.

##### - NetEvent.NetEventAllowStart

An asynchronous event that indicates the protocols and filters including the miniport adapter does not need to be paused. The usage rules are below. There is no guaranteed pause state for any driver in the protocols and filters after the [NdisMNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismnetpnpevent) routine returns.

* This event can only be issued after [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) begins and must not be issued after [MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) returns.
* Because this event is blocking, it should not be issued by any context that would cause a deadlock.
* Locks must not be held while issuing this event.

This event is available starting with NDIS version 6.50 and must be used with V2 or later version of **NET_PNP_EVENT**. This event can optionally be issued by a miniport driver. Protocols and filters cannot receive this event or issue it.

##### - NetEvent.NetEventBindFailed

Indicates that a binding event failure has occurred.

##### - NetEvent.NetEventBindList

Indicates to a protocol driver that its bind list processing order has been reconfigured. This
list indicates a relative order that applies to bindings when processing, for example, a user request
that might be routed to one of several bindings. The buffer that is passed with this event contains a
list of device names that are formatted as null-terminated Unicode strings. The format of each device
name is identical to the
**AdapterName** member that is passed to a call to the
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function.

##### - NetEvent.NetEventBindsComplete

Indicates that a protocol driver has bound to all the NICs that it can bind to. NDIS will not
indicate any more NICs to the protocol unless a PnP NIC is plugged into the system.

##### - NetEvent.NetEventCancelRemoveDevice

Indicates that the PnP Manager has sent a Cancel Remove Device request. The PnP Manager sends
this request to cancel the removal of a device after the PnP Manager sends a Query Remove Device request.

##### - NetEvent.NetEventFilterPreDetach

Indicates that a filter is about to be detached, so that the filter can perform any necessary cleanup that isn't possible in the [FilterDetach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_detach) handler (because the OID and indication paths are closed at that time).

##### - NetEvent.NetEventIMReEnableDevice

Indicates that the configuration has changed for a virtual miniport of an NDIS 6.0 or later
intermediate driver.
**NetEventIMReEnableDevice** is similar to the
**NetEventReconfigure** event except that the intermediate driver receives this event for a single
virtual miniport and the
**NetEventReconfigure** event applies to all the intermediate driver's virtual miniports. For
example, an intermediate driver receives the
**NetEventIMReEnableDevice** event when a user disables and then enables a single virtual miniport
from the Device Manager or another source. For examples of intermediate driver power management, see the
[NDIS MUX Intermediate Driver and Notify Object](https://go.microsoft.com/fwlink/p/?LinkId=617916) driver sample available in the [Windows driver samples](https://go.microsoft.com/fwlink/p/?LinkId=616507) repository on GitHub.

##### - NetEvent.NetEventInhibitBindsAbove

A synchronous event that prevents other filters and protocols from binding to the miniport adapter. Any filters or protocols that were previously bound will be unbound before the event completes. The usage rules are below.

* Avoid leaving the miniport adapter in the inhibit state, for longer than 1000 milliseconds.
* This event can only be issued after [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) begins and must not be issued after [MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) returns.
* This event can only be issued when the miniport adapter is in a D0 state.
* Because this event is blocking, it should not be issued by any context that would cause a deadlock.
* Locks must not be held while issuing this event.
* This event must be issued at PASSIVE_LEVEL.

This event is available starting with NDIS version 6.50
and must be used with V2 or later version of **NET_PNP_EVENT**. This event can optionally be issued by a miniport driver. Protocols and filters cannot receive this event or issue it.

##### - NetEvent.NetEventNDKDisable

Indicates that NDK is currently disabled.

##### - NetEvent.NetEventNDKEnable

Indicates that Network Direct Kernel (NDK) is currently enabled.

##### - NetEvent.NetEventPause

Indicates that the specified protocol binding should enter the
Pausing state. The binding will enter the
Paused state after NDIS has completed all the outstanding send requests for the
binding.

##### - NetEvent.NetEventPnPCapabilities

Indicates that the user enabled or disabled the wake-up capabilities of the underlying adapter.
(The binding is specified by the
*ProtocolBindingContext* parameter that is passed to the
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function.)

##### - NetEvent.NetEventPortActivation

Indicates the activation of a list of ports that are associated with the specified
binding.

##### - NetEvent.NetEventPortDeactivation

Indicates the deactivation of a list of ports that are associated with the specified
binding.

##### - NetEvent.NetEventQueryPower

Indicates that the power manager has sent a Query Power request, which requests a transition to
a system power state. NDIS translates this state to an appropriate device power state for the
device.

For more information, see the Remarks section.

##### - NetEvent.NetEventQueryRemoveDevice

Indicates that the PnP Manager has sent a Query Remove Device request. The PnP Manager sends
this request to query whether a device can be removed without disrupting operations.

##### - NetEvent.NetEventReconfigure

Indicates that the configuration has changed for a network component. For example, if a user,
through the Network and Dial-up Connections folder, changes the IP address for TCP/IP, NDIS indicates
the
**NetEventReconfigure** event to the TCP/IP protocol. Also, an intermediate driver typically uses
this event as a trigger to call the
[NdisIMInitializeDeviceInstanceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisiminitializedeviceinstanceex) function and start its virtual miniports. For more information
about
**NetEventReconfigure**, see
NetEventIMReEnableDevice.

##### - NetEvent.NetEventRequirePause

A synchronous event that indicates the protocols and filters including the miniport adapter must be paused. The protocols and filters and the miniport adapter are guaranteed to be paused when the [NdisMNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismnetpnpevent) routine returns. The usage rules are below.

* Avoid delaying between NetEventAllowStart and NetEventRequirePause events for longer than 1000 milliseconds to prevent delay in user applications.
* This event can only be issued after [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) begins and must not be issued after [MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) returns.
* There is no guarantee that NDIS will call [MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause) after this event is issued. In particular, if your miniport adapter is already paused, NDIS won't introduce an extra start-pause loop. This means that the amount of times *MiniportPause* called is not greater than, less than, or equal to the amount this event is issued.
* Because this event is blocking, it should not be issued by any context that would cause a deadlock.
* Locks must not be held while issuing this event.

This event is available starting with NDIS version 6.50 and must be used with V2 or later version of **NET_PNP_EVENT**. This event can optionally be issued by a miniport driver. Protocols and filters cannot receive this event or issue it.

##### - NetEvent.NetEventRestart

Indicates that the specified protocol binding has entered the
Restarting state. After the protocol driver is ready to resume send and receive operations for
the binding, the binding enters the
Running state.

##### - NetEvent.NetEventSetPower

Indicates that the power manager has sent a Set Power request, which specifies a transition to a
system power state. NDIS translates this state to an appropriate device power state for the
device.

For more information, see the Remarks section.

##### - NetEvent.NetEventSwitchActivate

Indicates that the Hyper-V Extensible Switch has completed activation, and switch extensions can now safely query for further switch configuration. The indication is only used in the Hyper-V Extensible Switch stack, issued by the extension miniport. See [Querying the Hyper-V Extensible Switch Configuration](https://learn.microsoft.com/windows-hardware/drivers/network/querying-the-hyper-v-extensible-switch-configuration) and [NDIS_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_parameters) for more details.

## Remarks

In NDIS 6.0 and later versions, when the operating system issues a system PnP event or a power
management event to a target device object that represents a miniport adapter, NDIS translates the event
into a
[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification) structure. The
**NetPnPEvent** member of the **NET_PNP_EVENT_NOTIFICATION** structure is a **NET_PNP_EVENT** structure.

NDIS passes a pointer to the **NET_PNP_EVENT** structure to each protocol driver that is bound to the
miniport adapter by calling the protocol driver's
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function. The
protocol driver should save this pointer, because the pointer is an input parameter to the
[NdisCompleteNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscompletenetpnpevent) function,
which the driver calls to complete the call to
*ProtocolNetPnPEvent* asynchronously.

NDIS passes a pointer to the **NET_PNP_EVENT** structure to each filter driver that is bound to the
miniport adapter by calling the filter driver's
[FilterNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_net_pnp_event) function. The
filter driver does not have to save this pointer because the driver must complete the call to
*FilterNetPnPEvent* synchronously.

Starting with NDIS 6.30, the protocol or filter driver must follow these guidelines when NDIS calls the [ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) or [FilterNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_net_pnp_event) functions:

* If the **NetEvent** member of the **NET_PNP_EVENT** structure is set to **NetEventSetPower**, the driver must stop generating new I/O requests. Also, the driver must not wait for the completion of any pending I/O requests.

  After the protocol or filter driver returns from [ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) or [FilterNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_net_pnp_event), NDIS will not pause and restart these drivers during power-state transitions if the following conditions are true:

  + The underlying miniport driver sets the **NDIS_MINIPORT_ATTRIBUTES_NO_PAUSE_ON_SUSPEND** flag in the [NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_registration_attributes) structure. The driver passes a pointer to this structure in its call to the [NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function.
  + All filter drivers that are attached to the miniport driver support NDIS 6.30 or later versions of NDIS.
  + All protocol drivers that are bound to the miniport driver support NDIS 6.30 or later versions of NDIS.
* If the **NetEvent** member of the **NET_PNP_EVENT** structure is set to **NetEventSetPower** or **NetEventQueryPower**, the driver must not wait for the completion of any pending I/O requests.

The
**NetEvent** member in the **NET_PNP_EVENT** structure identifies the type of Plug and Play or power
management event. The
**Buffer** contains information that is specific to the type of event.

## See also

[FilterNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_net_pnp_event)

[NDIS_BIND_FAILED_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_bind_failed_notification)

[NDIS_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port)

[NDIS_PROTOCOL_PAUSE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_pause_parameters)

[NDIS_PROTOCOL_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_protocol_restart_parameters)

[NDIS_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_attributes)

[NDIS_SWITCH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_parameters)

[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification)

[NdisCompleteNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscompletenetpnpevent)

[NdisIMInitializeDeviceInstanceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisiminitializedeviceinstanceex)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event)

[Querying the Hyper-V Extensible Switch Configuration](https://learn.microsoft.com/windows-hardware/drivers/network/querying-the-hyper-v-extensible-switch-configuration)