# NdisMNetPnPEvent function

## Description

NDIS miniport drivers (and intermediate drivers that are registered as miniport drivers) call the
**NdisMNetPnPEvent** function to originate a network Plug and Play event, an NDIS PnP event,
or Power Management event or propagate it to overlying drivers.

## Parameters

### `MiniportAdapterHandle` [in]

An NDIS handle which NDIS provided at the
*MiniportAdapterHandle* parameter of the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
This handle identifies the miniport adapter that is affected by the event. If the caller is an
intermediate driver, this is the handle of the virtual miniport.

### `NetPnPEventNotification`

A pointer to a
[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification) structure, which describes the network Plug and Play event, NDIS PnP
event, or Power Management event.

> [!IMPORTANT]
> If the **VPortId** field of **NetPnpEventNotification** is set to a value different from NDIS_DEFAULT_VPORT_ID, then the **Flags** member must be set to NET_EVENT_FLAGS_VPORT_ID_VALID for **VPortId** to take effect.

## Return value

**NdisMNetPnPEvent** can return the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The overlying drivers successfully processed the Plug and Play or Power Management event. |
| **NDIS_STATUS_RESOURCES** | The overlying drivers could not obtain the necessary system resources to satisfy the indicated Plug and Play or Power Management event. |
| **NDIS_STATUS_INVALID_PARAMETER** | NDIS failed the call because some of the input parameters are invalid. |
| **NDIS_STATUS_NOT_SUPPORTED** | NDIS 6.0 and later protocol drivers must not return this status. An NDIS 5.*x* protocol driver that does not support Plug and Play can return this status in response to a **NetEventSetPower** to indicate that NDIS should unbind it from the underlying adapter. |
| **NDIS_STATUS_INVALID_PORT** | NDIS failed the request because an invalid NDIS port was specified in a **NetEventPortActivation** or **NetEventPortDeactivation** PnP event. |
| **NDIS_STATUS_INVALID_PORT_STATE** | NDIS failed the request because an NDIS port was in an invalid port state. The ports are specified in a **NetEventPortActivation** or **NetEventPortDeactivation** PnP event. |
| **NDIS_STATUS_FAILURE** | The overlying drivers' attempts to process the propagated Plug and Play or Power Management event failed. |

The return value is significant only when the propagated event is a
**NetEventQueryPower** or
**NetEventQueryRemoveDevice** event. For all other propagated events, the return value is always
NDIS_STATUS_SUCCESS.

If the event is
**NetEventPortActivation** and the call fails, the caller should not use the associated ports in
receive indications or status indications.

## Remarks

Any miniport driver can call
**NdisMNetPnPEvent** to generate
**NetEventPortActivation** and
**NetEventPortDeactivation** events. Only intermediate drivers can make other event notifications.

**Note** To prevent deadlocks, an NDIS driver must do the following:

* Its [MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function must not call
  **NdisMNetPnPEvent**.
* If its [MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function returns NDIS_STATUS_PENDING for an OID request, the NDIS driver must not call
  **NdisMNetPnPEvent** until after it has completed the OID request by calling [NdisMOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismoidrequestcomplete).

To propagate notification of a network Plug and Play event, an NDIS PnP event, or Power Management
event to overlying drivers, an NDIS intermediate driver calls
**NdisMNetPnPEvent** in the context of the driver's
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function.

If the propagated event is a
**NetEventQueryPower** or a
**NetEventQueryRemoveDevice**, the intermediate driver must check the NDIS_STATUS value that is
returned by
**NdisMNetPnPEvent**. If the returned status is NDIS_STATUS_SUCCESS, the intermediate driver should
handle the event and then return NDIS_STATUS_SUCCESS from its
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function. If the returned status is not NDIS_STATUS_SUCCESS, the intermediate
driver should return the reported status from its
*ProtocolNetPnPEvent* function without further processing.

How the intermediate driver processes a
**NetEventSetPower** received by its
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function depends on the specified device power state. If the specified device
power state is
**NdisDeviceStateD0**, the intermediate driver should handle the event and then call
**NdisMNetPnPEvent**. For any other specified device power state, the intermediate driver should first
call
**NdisMNetPnPEvent** and then handle the event.

An intermediate driver should call
**NdisMNetPnPEvent** to propagate a
**NetEventReconfigure** or
**NetEventBindList** only if the
**NetEventReconfigure** or
**NetEventBindList** is indicated on a non-**NULL**
*ProtocolBindingContext*. If a
**NetEventReconfigure** or
**NetEventBindList** is indicated on a **NULL**
*ProtocolBindingContext*, the intermediate driver should not call
**NdisMNetPnPEvent** to propagate the event.

If an intermediate driver handles a
**NetEventReconfigure** or a
**NetEventBindList**, it should validate any data associated with the event.

An intermediate driver should not propagate the
**NetEventBindsComplete**,
**NetEventPause**,
**NetEventRestart**,
**NetEventPortActivation**, or
**NetEventPortDeactivation** events by calling
**NdisMNetPnPEvent**.

An NDIS intermediate driver can generate its own NDIS port events for virtual miniports as
appropriate for the
**NetEventPortActivation** or
**NetEventPortDeactivation** events that it receives at its
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function.

For all other propagated events, the intermediate driver's
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function should propagate the status value that is returned by
**NdisMNetPnPEvent**.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request)

[NET_PNP_EVENT_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_pnp_event_notification)

[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event)