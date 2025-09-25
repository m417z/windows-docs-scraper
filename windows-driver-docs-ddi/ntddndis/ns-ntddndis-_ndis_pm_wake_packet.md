# _NDIS_PM_WAKE_PACKET structure

## Description

The **NDIS_PM_WAKE_PACKET** structure describes a network packet (known as a *wake packet*) that caused the network adapter to generate a wake-up event.

## Members

### `Header`

The type, revision, and size of the **NDIS_PM_WAKE_PACKET** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_DEFAULT. To specify the version of the **NDIS_PM_WAKE_PACKET** structure, the driver must set the **Revision** member of **Header** to the following value:

#### NDIS_SIZEOF_PM_WAKE_PACKET_REVISION_1

Original version for NDIS 6.30 and later.

Set the **Size** member to NDIS_SIZEOF_PM_WAKE_PACKET_REVISION_1.

### `Flags`

A **ULONG** value that contains a bitwise **OR** of flags. This member is reserved for NDIS.

### `PatternId`

A **ULONG** value that specifies the identifier of the wake-on-LAN (WOL) pattern that matches the wake packet. This identifier is specified by the **PatternId** member of the [NDIS_PM_WOL_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_wol_pattern) structure that is passed to the driver during an OID set request of [OID_PM_ADD_WOL_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pm-add-wol-pattern).

### `PatternFriendlyName`

An [NDIS_PM_COUNTED_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_counted_string) value that contains the friendly description of the wake pattern that is specified by the **PatternId** member.
This value is specified by the **FriendlyName** member of the [NDIS_PM_WOL_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_wol_pattern) structure that is passed to the driver during an OID request of [OID_PM_ADD_WOL_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pm-add-wol-pattern).

**Note** The miniport driver does not need to initialize this member. NDIS sets the **PatternFriendlyName** member to the correct value before it passes the **NDIS_PM_WAKE_PACKET** structure to overlying drivers.

### `OriginalPacketSize`

A **ULONG** value that specifies the original length, in units of bytes, of the wake packet.

### `SavedPacketSize`

A **ULONG** value that specifies the length, in units of bytes, of the wake packet data that follows this structure.

**Note** The value of this member should at least `min(wake packet size, 128)` bytes.

### `SavedPacketOffset`

A **ULONG** value that specifies the offset, in units of bytes, to the wake packet data that follows this structure. The offset is measured from the start of the **NDIS_PM_WAKE_PACKET** structure to the beginning of a buffer that contains the wake packet.

**Note** The offset to the saved wake packet must be aligned on a 64-bit boundary.

## Remarks

The **NDIS_PM_WAKE_PACKET** structure is used in the [NDIS_STATUS_PM_WAKE_REASON](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-pm-wake-reason) status indication. For more information about how to issue this status indication, see [Issuing NDIS Wake Reason Status Indications](https://learn.microsoft.com/windows-hardware/drivers/network/issuing-ndis-wake-reason-indications).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_PM_COUNTED_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_counted_string)

[NDIS_PM_WOL_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_wol_pattern)

[NDIS_STATUS_PM_WAKE_REASON](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-pm-wake-reason)

[OID_PM_ADD_WOL_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pm-add-wol-pattern)