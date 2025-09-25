# DOT11_EXTSTA_SEND_CONTEXT structure

## Description

> [!Important]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_EXTSTA_SEND_CONTEXT structure defines the Native 802.11 attributes of a packet to be sent
by the miniport driver operating in Extensible Station (ExtSTA) mode. For more information about this
operation mode, see
[Extensible Station Operation
Mode](https://learn.microsoft.com/windows-hardware/drivers/network/extensible-station-operation-mode).

## Members

### `Header`

The type, revision, and size of the DOT11_EXTSTA_SEND_CONTEXT structure. This member is formatted
as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_EXTSTA_SEND_CONTEXT_REVISION_1.

#### Size

This member must be set to
sizeof(DOT11_EXTSTA_SEND_CONTEXT).

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `usExemptionActionType`

The type of encryption exemption for the packet. The following exemption types are defined:

#### DOT11_EXEMPT_NO_EXEMPTION

The packet is not exempt from any cipher operations performed by the 802.11 station.

#### DOT11_EXEMPT_ALWAYS

The packet is exempt from any cipher operations performed by the 802.11 station. The 802.11
station must transmit the packet unencrypted.

#### DOT11_EXEMPT_ON_KEY_MAPPING_KEY_UNAVAILABLE

The packet is exempt from any cipher operations performed by the 802.11 station only if the
station does not have a key-mapping key for the packet's destination media access control (MAC)
address. For more information about key-mapping keys, see
[802.11 Cipher Key Types](https://learn.microsoft.com/windows-hardware/drivers/network/802-11-cipher-key-types).

### `uPhyId`

The identifier (ID) of a PHY type on the 802.11 station. The 802.11 station must use the specified
PHY to transmit the packet.

The value of
**uPhyId** must be one of the following:

* The value of an entry in the list of active PHY types defined by the
  **msDot11ActivePhyList** MIB object. The miniport driver sets this MIB object to the list of PHYs
  that have been activated for use over the current basic service set (BSS) network connection. For more
  information about the
  **msDot11ActivePhyList** MIB object, see
  [OID_DOT11_ACTIVE_PHY_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-active-phy-list).
* The value of DOT11_PHY_ID_ANY, in which case the 802.11 station can use any PHY from the list of
  active PHYs defined by the
  **msDot11ActivePhyList** MIB object.

The miniport driver must fail the send request if the PHY specified by
**uPhyId** is either not supported or has been disabled through a proprietary mechanism implemented by
the independent hardware vendor (IHV). In this situation, the miniport driver sets the
**Status** member of the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure to
NDIS_STATUS_UNSUPPORTED_MEDIA and calls
[NdisMSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsendnetbufferlistscomplete) to complete the send request.

### `uDelayedSleepValue`

The time, in microseconds, before a response to the packet is expected. The
**uDelayedSleepValue** member is only valid when all of the following are true:

* The packet is a media access control (MAC) service data unit (MSDU) packet.
* The 802.11 station is operating in a power save (PS) mode. In this situation, the Extensible
  Station (ExtSTA)
  **msDot11PowerSavingLevel** management information base (MIB) object has any value except
  DOT11_POWER_SAVING_NO_POWER_SAVING. For more information about the
  **msDot11PowerSavingLevel** MIB value, see
  [OID_DOT11_POWER_MGMT_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-power-mgmt-request).

The 802.11 station uses the value of
**uDelayedSleepValue** to optimize network performance while operating in a PS mode. For example,
depending upon the PS mode, the 802.11 station might keep the radio turned on after the transmission of
the packet if
**uDelayedSleepValue** is small. By doing so, the network latency will be reduced for receiving the
response.

### `pvMediaSpecificInfo`

A pointer to a buffer that contains media-specific information. This member should be **NULL** when
the 802.11
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure that this
structure is associated with comes from the native 802.11 framework itself (including any
NET_BUFFER_LIST structures that come from an IHV extension).

Otherwise,
**pvMediaSpecificInfo** points to the out-of-band (OOB) data that is associated with the
**MediaSpecificInformation** entry at the
**NetBufferListInfo** member of the original 802.3 NET_BUFFER_LIST structure.
**pvMediaSpecificInfo** allows the miniport driver to access the media-specific information from an
IHV-specific 802.3 protocol driver.

### `uSendFlags`

A set of flags that define send attributes. Currently, there are no flags defined. This member
should be zero.

## Syntax

```cpp
typedef struct DOT11_EXTSTA_SEND_CONTEXT {
  NDIS_OBJECT_HEADER Header;
  USHORT             usExemptionActionType;
  ULONG              uPhyId;
  ULONG              uDelayedSleepValue;
  PVOID              pvMediaSpecificInfo;
  ULONG              uSendFlags;
} DOT11_EXTSTA_SEND_CONTEXT, *PDOT11_EXTSTA_SEND_CONTEXT;
```

## Remarks

The miniport driver performs a send operation when its
[MiniportSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_send_net_buffer_lists) is called. Each packet passed to the driver through this function is
defined by a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure, which contains
Native 802.11 out-of-band (OOB) data. The OOB data contains media-specific parameters that the 802.11
station uses when transmitting the packet.

The miniport driver accesses the Native 802.11 OOB data through the
[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info) macro with the
following parameters:

* The
  *_NBL* parameter, which is passed the pointer to the
  [NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure used for the
  received 802.11 packet.
* The _
  *id* parameter, which is passed the identifier (ID) value of
  **MediaSpecificInformation**.

For more information about Native 802.11 send operations, see
[Native 802.11 Send
Operations](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-send-operations).

## See also

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[OID_DOT11_ACTIVE_PHY_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-active-phy-list)

[MiniportSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_send_net_buffer_lists)

[OID_DOT11_POWER_MGMT_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-power-mgmt-request)

[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info)

[NdisMSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsendnetbufferlistscomplete)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)