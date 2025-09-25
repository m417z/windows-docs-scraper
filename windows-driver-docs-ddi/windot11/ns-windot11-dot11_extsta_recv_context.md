# DOT11_EXTSTA_RECV_CONTEXT structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_EXTSTA_RECV_CONTEXT structure defines the Native 802.11 attributes of a received packet by the 802.11 station and indicated by the miniport driver operating in either Extensible Station (ExtSTA) or Network Monitor (NetMon) modes. For more information about these operation modes, see [Native 802.11 Operation Modes](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-operation-modes).

## Members

### `Header`

The type, revision, and size of the DOT11_EXTSTA_RECV_CONTEXT structure. This member is formatted
as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_EXTSTA_RECV_CONTEXT_REVISION_1.

#### Size

This member must be set to `sizeof(DOT11_EXTSTA_RECV_CONTEXT)`.

For more information about these members, see [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uReceiveFlags`

The attributes of the received packet data specified through a bitmask.

If the miniport driver is operating in ExtSTA mode, the driver must always set **uReceiveFlags** to zero.

The following flag values are valid for the miniport driver if is operating in NetMon mode.

#### DOT11_RECV_FLAG_RAW_PACKET

If this bit is set, the packet contains the data as it was originally received by the 802.11 station. For more information about raw packets, see [Indicating Raw 802.11 Packets](https://learn.microsoft.com/windows-hardware/drivers/network/indicating-raw-802-11-packets).

#### DOT11_RECV_FLAG_RAW_PACKET_FCS_FAILURE

If this bit is set, the raw packet data was received with frame check sequence (FCS) failures.

**Note** The miniport driver must set DOT11_RECV_FLAG_RAW_PACKET when setting
DOT11_RECV_FLAG_RAW_PACKET_FCS_FAILURE.

#### DOT11_RECV_FLAG_RAW_PACKET_TIMESTAMP

If this bit is set, the NIC sets the timestamp information in the
**ullTimestamp** member.

### `uPhyId`

The identifier (ID) of the PHY on which the 802.11 station received the packet.

### `uChCenterFrequency`

The channel center frequency, in units of megahertz (MHz), of the frequency band on which the
802.11 station received the packet.

### `usNumberOfMPDUsReceived`

The number of media access control (MAC) protocol data unit (MPDU) fragments received and
reassembled by the 802.11 station for the packet. The value of
**usNumberOfMPDUsReceived** must be from one through the value of DOT11_MAX_NUM_OF_FRAGMENTS.

### `lRSSI`

The received signal strength indication (RSSI) value for the last received MPDU fragment of the
802.11 packet. The RSSI value is in units of decibels referenced to 1.0 milliwatts (dBm).

### `ucDataRate`

The data rate at which the 802.11 station received the packet. The value of
**ucDataRate** is the value of the
**ucDataRateIndex** member of the data rate from the 802.11 station's data rate mapping table. For
more information about the data rate mapping table, see
[OID_DOT11_DATA_RATE_MAPPING_TABLE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-data-rate-mapping-table).

### `uSizeMediaSpecificInfo`

The size, in bytes, of the media specific information at the
**pvMediaSpecificInfo** member.
**uSizeMediaSpecificInfo** supports copying of the media-specific information and passing it to an IHV
extension.

**Note** This member is currently reserved for future use and must contain
zero.

### `pvMediaSpecificInfo`

A pointer to a buffer that contains media-specific information. The miniport driver can set this
member if the miniport driver passes media-specific OOB data to an IHV-specific 802.3 protocol driver.

The native 802.11 framework copies this pointer to the
**MediaSpecificInformation** entry at the
**NetBufferListInfo** member of the 802.3
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures in NDIS receive
indications.

**Note** IHV extensions are currently unable to receive the
**MediaSpecificInformation**.

### `ullTimestamp`

An 802.11 timing synchronization function (TSF) timer value, in microseconds, that specifies the
time when the packet was received. This member is provided to support
[indicating raw 802.11 packets](https://learn.microsoft.com/windows-hardware/drivers/network/indicating-raw-802-11-packets).

If a NIC does not support
**ullTimestamp**, it must not set the DOT11_RECV_FLAG_RAW_PACKET_TIMESTAMP flag in the
**uReceiveFlags** member.

## Syntax

```cpp
typedef struct DOT11_EXTSTA_RECV_CONTEXT {
  NDIS_OBJECT_HEADER Header;
  ULONG              uReceiveFlags;
  ULONG              uPhyId;
  ULONG              uChCenterFrequency;
  USHORT             usNumberOfMPDUsReceived;
  LONG               lRSSI;
  UCHAR              ucDataRate;
  ULONG              uSizeMediaSpecificInfo;
  PVOID              pvMediaSpecificInfo;
  ULONGLONG          ullTimestamp;
} DOT11_EXTSTA_RECV_CONTEXT, *PDOT11_EXTSTA_RECV_CONTEXT;
```

## Remarks

When performing a Native 802.11 receive operation, the miniport driver must format each received
802.11 packet as a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure, with the packet
data formatted as a
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure and linked to the
NET_BUFFER_LIST structure. Each NET_BUFFER_LIST structure must include out-of-band (OOB) data. The OOB
data specifies the attributes of the received packet that are specific to the wireless LAN (WLAN)
media.

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

If the miniport driver sets DOT11_RECV_FLAG_RAW_PACKET in the
**uReceiveFlags** member, the driver must follow these guidelines when preparing the
DOT11_EXTSTA_RECV_CONTEXT structure:

* Set the value of
  **usNumberOfMPDUsReceived** to one.
* Set the value of
  **lRSSI** to the RSSI value for the raw packet itself.
* Set the value of
  **ucDataRate** to the
  **ucDataRateIndex** value for the raw packet itself.
* Set the value of
  **ucRSSI** to the normalized RSSI value for the raw packet itself.

For more information about raw packets, see
[Indicating Raw 802.11
Packets](https://learn.microsoft.com/windows-hardware/drivers/network/indicating-raw-802-11-packets).

For more information about Native 802.11 receive operations, see
[Native 802.11 Receive
Operations](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-receive-operations).

## See also

[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/net-buffer-list-info)

[OID_DOT11_DATA_RATE_MAPPING_TABLE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-data-rate-mapping-table)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)