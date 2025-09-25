# _NET_PNP_EVENT_NOTIFICATION structure

## Description

The NET_PNP_EVENT_NOTIFICATION structure describes a network Plug and Play (PnP) event, an NDIS PnP
event, or a power management event.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NET_PNP_EVENT_NOTIFICATION structure. NDIS sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NET_PNP_EVENT_NOTIFICATION_REVISION_1, and the
**Size** member to NDIS_SIZEOF_NET_PNP_EVENT_NOTIFICATION_REVISION_1.

### `PortNumber`

The source port of the event notification. If the status indication is not specific to a port,
**PortNumber** is zero.

### `NetPnPEvent`

A
[NET_PNP_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpnp/ns-netpnp-_net_pnp_event) structure that describes the
event.

### `Flags`

Flags for this event notification.

> [!IMPORTANT]
> For miniport drivers calling [**NdisMNetPnPEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismnetpnpevent), if **VPortId** is set to a value different from NDIS_DEFAULT_VPORT_ID then **Flags** must be set to NET_EVENT_FLAGS_VPORT_ID_VALID for **VPortId** to take effect.
>
> Other values for **Flags** are reserved for NDIS.

### `SwitchId`

An **NDIS_NIC_SWITCH_ID** value that specifies a switch identifier. The switch identifier is an integer between zero and the number of switches that the network adapter supports. An **NDIS_DEFAULT_SWITCH_ID** value indicates the default network adapter switch.

### `VPortId`

An **NDIS_NIC_SWITCH_VPORT_ID** value that uniquely identifies the virtual port (VPort) on the network adapter.

A value of **NDIS_DEFAULT_VPORT_ID** specifies the default VPort on the switch. The default VPort is always attached to the PCI Express (PCIe) Physical Function (PF) of the network adapter.

> [!NOTE]
> A nondefault VPort with the specified **VPortId** value must have previously been created through an OID method request of [OID_NIC_SWITCH_CREATE_VPORT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-create-vport).

## Remarks

When the operating system issues a system PnP event or a power management event to a target device
object that represents an adapter, NDIS translates the event into a NET_PNP_EVENT_NOTIFICATION
structure.

The
**NetPnPEvent** member is a
[NET_PNP_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpnp/ns-netpnp-_net_pnp_event) structure. The
**NetEvent** member of this NET_PNP_EVENT structure specifies an event code that identifies the network
PnP event, NDIS PnP event, or power management event.

The
**Buffer** member, which is in the NET_PNP_EVENT structure that is specified in the
**NetPnPEvent** member of NET_PNP_EVENT_NOTIFICATION, specifies the address of a buffer that contains
information that is specific to the event that is indicated by the
**NetEvent** member.

NDIS also issues PnP event notifications for NDIS PnP events such as
**NetEventPause**,
**NetEventRestart**,
**NetEventPortActivation**, and
**NetEventPortDeactivation**.

NDIS passes a pointer to a NET_PNP_EVENT_NOTIFICATION structure to the
[FilterNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_net_pnp_event) function of
overlying filter drivers and to the
[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event) function of
overlying protocol drivers.

## See also

[FilterNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_net_pnp_event)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NET_PNP_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpnp/ns-netpnp-_net_pnp_event)

[ProtocolNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_net_pnp_event)