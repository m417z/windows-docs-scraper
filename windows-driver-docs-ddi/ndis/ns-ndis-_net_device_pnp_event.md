# _NET_DEVICE_PNP_EVENT structure

## Description

The **NET_DEVICE_PNP_EVENT** structure defines device plug and play (PnP) events for miniport
adapters.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NET_DEVICE_PNP_EVENT** structure. NDIS sets the
**Type** member of the structure that
**Header** specifies to **NDIS_OBJECT_TYPE_DEFAULT**, the
**Revision** member to **NET_DEVICE_PNP_EVENT_REVISION_1**, and the
**Size** member to **NDIS_SIZEOF_NET_DEVICE_PNP_EVENT_REVISION_1**.

### `PortNumber`

The source port of the PnP event notification. If the status indication is not specific to a port,
**PortNumber** is zero.

### `DevicePnPEvent`

An event code that describes the PnP event as one of the following:

#### NdisDevicePnPEventSurpriseRemoved

The network interface card (NIC) has been unexpectedly removed from the
computer. For more information, see [Handling the Surprise Removal of a NIC](https://learn.microsoft.com/windows-hardware/drivers/network/handling-the-surprise-removal-of-a-nic).

#### NdisDevicePnPEventPowerProfileChanged

The power profile of the host system has changed.

### `InformationBuffer`

A pointer to a buffer. If NDIS sets the
**DevicePnPEvent** member to
**NdisDevicePnPEventPowerProfileChanged**, this buffer will contain a ULONG that NDIS sets to one of
the following values:

#### NdisPowerProfileBattery

The host system is running on battery power.

#### NdisPowerProfileAcOnline

The host system is running on AC power.

If NDIS sets
**DevicePnPEvent** to
**NdisDevicePnPEventSurpriseRemoved**,
**InformationBuffer** is **NULL**.

### `InformationBufferLength`

The length, in bytes, of the buffer in the
**InformationBuffer** member.

### `NdisReserved`

Reserved for NDIS.

## Remarks

To provide a device PnP event notification, NDIS passes a pointer to a **NET_DEVICE_PNP_EVENT** structure
to the
[MiniportDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_device_pnp_event_notify) or
[FilterDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_device_pnp_event_notify) function.

## See also

[FilterDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_device_pnp_event_notify)

[MiniportDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_device_pnp_event_notify)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)