# _NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES structure

## Description

An NDIS miniport driver sets up an **NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES** structure to define the
general miniport driver attributes that are associated with a miniport adapter.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES** structure. Set the
**Type** member of the structure that
**Header** specifies to **NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES**.

To indicate the version of the **NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES** structure, set the
**Revision** member to one of the following values:

#### NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES_REVISION_2

Added the
**PowerManagementCapabilitiesEx** member for NDIS 6.2.

Set the **Size** member to **NDIS_SIZEOF_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES_REVISION_2**.

#### NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES_REVISION_1

Original version for NDIS 6.0 and NDIS 6,1.

Set the
**Size** member to
**NDIS_SIZEOF_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES_REVISION_1**.

### `Flags`

Reserved for NDIS.

### `MediaType`

The
**NdisMedium*Xxx*** type that the miniport adapter supports. For more information, see
[NDIS_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_medium).

### `PhysicalMediumType`

The physical medium type for the miniport adapter. For more information, see
[OID_GEN_PHYSICAL_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-physical-medium)

### `MtuSize`

The maximum transfer unit (MTU) size. For more information, see
[OID_GEN_MAXIMUM_FRAME_SIZE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-maximum-frame-size).

### `MaxXmitLinkSpeed`

The maximum transmit link speed of the adapter in bits per second. For more information, see
[OID_GEN_MAX_LINK_SPEED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-max-link-speed).

### `XmitLinkSpeed`

The current transmit link speed of the adapter in bits per second. For more information, see
[OID_GEN_LINK_SPEED_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-link-speed-ex).

### `MaxRcvLinkSpeed`

The maximum receive link speed of the adapter in bits per second. For more information, see
[OID_GEN_MAX_LINK_SPEED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-max-link-speed).

### `RcvLinkSpeed`

The current receive link speed of the adapter in bits per second. For more information, see
[OID_GEN_LINK_SPEED_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-link-speed-ex).

### `MediaConnectState`

The media connect state for the miniport adapter. For more information, see
[OID_GEN_MEDIA_CONNECT_STATUS_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-connect-status-ex).

### `MediaDuplexState`

The media duplex state for the miniport adapter. For more information, see
[OID_GEN_MEDIA_DUPLEX_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-duplex-state).

### `LookaheadSize`

The lookahead size for the miniport adapter. For more information, see
[OID_GEN_CURRENT_LOOKAHEAD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-current-lookahead).

### `PowerManagementCapabilities`

The Plug and Play (PnP) capabilities of the miniport adapter. For more information about PnP
capabilities, see
[OID_PNP_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-capabilities). If the miniport
adapter is not power management-aware, the miniport driver should set
**PowerManagementCapabilities** to **NULL**. NDIS 6.20 and later drivers must use the
**PowerManagementCapabilitiesEx** member instead.

### `MacOptions`

The MAC options for the miniport adapter. For more information, see
[OID_GEN_MAC_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-mac-options).

### `SupportedPacketFilters`

The packet filter flags for the miniport adapter.

### `MaxMulticastListSize`

The multicast address list size for the miniport adapter. For more information, see
[OID_802_3_MAXIMUM_LIST_SIZE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-802-3-maximum-list-size).

### `MacAddressLength`

The MAC address length, in bytes. The MAC address length is specific to the type of media.

### `PermanentMacAddress`

The permanent MAC address. For example, the
[OID_802_3_PERMANENT_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-802-3-permanent-address) OID
specifies the permanent MAC address for IEEE 802.3 drivers.

### `CurrentMacAddress`

The current MAC address. For example, the
[OID_802_3_CURRENT_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-802-3-current-address) OID
specifies the current MAC address for IEEE 802.3 drivers.

### `RecvScaleCapabilities`

The receive side scaling (RSS) capabilities of the NIC. If the miniport adapter does not support
the RSS feature, set
**RecvScaleCapabilities** to **NULL**. For more information about RSS, see
[OID_GEN_RECEIVE_SCALE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-capabilities).

### `AccessType`

A
[NET_IF_ACCESS_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_access_type) NDIS network interface
access type.

### `DirectionType`

A
[NET_IF_DIRECTION_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_direction_type) NDIS network
interface direction type.

### `ConnectionType`

A
[NET_IF_CONNECTION_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_connection_type) NDIS network
interface connection type.

### `IfType`

The Internet Assigned Numbers Authority (IANA) interface type. For example,
IF_TYPE_ETHERNET_CSMACD (6) is the value for
**IfType** that is assigned to any Ethernet-like interface. For a list if interface types, see
[NDIS Interface Types](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-interface-types).

### `IfConnectorPresent`

A Boolean value that indicates if a connector is present. Set this value to **TRUE** if there is a
physical adapter.

### `SupportedStatistics`

The supported statistics.

**Note** NDIS 6.0 drivers must support all statistics and must report them when the drivers
are queried for
[OID_GEN_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-statistics).

The value is the bitwise OR of the following flags:

#### NDIS_STATISTICS_DIRECTED_FRAMES_RCV_SUPPORTED

The data in the
**ifHCInUcastPkts** member is valid.

#### NDIS_STATISTICS_MULTICAST_FRAMES_RCV_SUPPORTED

The data in the
**ifHCInMulticastPkts** member of
NDIS_STATISTICS_INFO is valid.

#### NDIS_STATISTICS_BROADCAST_FRAMES_RCV_SUPPORTED

The data in the
**ifHCInBroadcastPkts** member of NDIS_STATISTICS_INFO is valid.

#### NDIS_STATISTICS_BYTES_RCV_SUPPORTED

The data in the
**ifHCInOctets** member of NDIS_STATISTICS_INFO is valid.

#### NDIS_STATISTICS_RCV_DISCARDS_SUPPORTED

The data in the
**ifInDiscards** member of NDIS_STATISTICS_INFO is valid.

#### NDIS_STATISTICS_RCV_ERROR_SUPPORTED

The data in the
**ifInErrors** member of NDIS_STATISTICS_INFO is valid.

#### NDIS_STATISTICS_DIRECTED_FRAMES_XMIT_SUPPORTED

The data in the
**ifHCOutUcastPkts** member of NDIS_STATISTICS_INFO is valid.

#### NDIS_STATISTICS_MULTICAST_FRAMES_XMIT_SUPPORTED

The data in the
**ifHCOutMulticastPkts** member of NDIS_STATISTICS_INFO is valid.

#### NDIS_STATISTICS_BROADCAST_FRAMES_XMIT_SUPPORTED

The data in the
**ifHCOutBroadcastPkts** member of NDIS_STATISTICS_INFO is valid.

#### NDIS_STATISTICS_BYTES_XMIT_SUPPORTED

The data in the
**ifHCOutOctets** member of NDIS_STATISTICS_INFO is valid.

#### NDIS_STATISTICS_XMIT_ERROR_SUPPORTED

The data in the
**ifOutErrors** member of NDIS_STATISTICS_INFO is valid.

#### NDIS_STATISTICS_XMIT_DISCARDS_SUPPORTED

The data in the
**ifOutDiscards** member of NDIS_STATISTICS_INFO is valid.

#### NDIS_STATISTICS_DIRECTED_BYTES_RCV_SUPPORTED

The data in the
**ifHCInUcastOctets** member of NDIS_STATISTICS_INFO is valid.

#### NDIS_STATISTICS_MULTICAST_BYTES_RCV_SUPPORTED

The data in the
**ifHCInMulticastOctets** member of NDIS_STATISTICS_INFO is valid.

#### NDIS_STATISTICS_BROADCAST_BYTES_RCV_SUPPORTED

The data in the
**ifHCInBroadcastOctets** member of NDIS_STATISTICS_INFO is valid.

#### NDIS_STATISTICS_DIRECTED_BYTES_XMIT_SUPPORTED

The data in the
**ifHCOutUcastOctets** member of NDIS_STATISTICS_INFO is valid.

#### NDIS_STATISTICS_MULTICAST_BYTES_XMIT_SUPPORTED

The data in the
**ifHCOutMulticastOctets** member of NDIS_STATISTICS_INFO is valid.

#### NDIS_STATISTICS_BROADCAST_BYTES_XMIT_SUPPORTED

The data in the
**ifHCOutBroadcastOctets** member of NDIS_STATISTICS_INFO is valid.

### `SupportedPauseFunctions`

Support for the IEEE 802.3 pause frames as one of the following pause functions:

#### NdisPauseFunctionsUnsupported

Indicates that the adapter or link partner does not support pause frames.

#### NdisPauseFunctionsSendOnly

Indicates that the adapter and link partner only support sending pause frames from the adapter
to the link partner.

#### NdisPauseFunctionsReceiveOnly

Indicates that the adapter and link partner only support sending pause frames from the link
partner to the adapter

#### NdisPauseFunctionsSendAndReceive

Indicates that the adapter and link partner support sending and receiving pause frames in both
transint and receive directions.

#### NdisPauseFunctionsUnknown

Indicates that pause frame negotiation is in progress. The pause frame support that the link
partner provides is unknown.

### `DataBackFillSize`

The required data backfill size, in bytes, of the driver.

### `ContextBackFillSize`

The required context backfill size, in bytes, of the driver.

### `SupportedOidList`

A list of OIDs that the miniport driver supports. For more information, see
[OID_GEN_SUPPORTED_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-supported-list).

### `SupportedOidListLength`

The size, in bytes, of the OID list at
**SupportedOidList** .

### `AutoNegotiationFlags`

The auto-negotiation settings for the miniport adapter. This member is created from a bitwise OR
of the following flags:
#### NDIS_LINK_STATE_XMIT_LINK_SPEED_AUTO_NEGOTIATED

The adapter has auto-negotiated the transmit link speed with the link partner.

#### NDIS_LINK_STATE_RCV_LINK_SPEED_AUTO_NEGOTIATED

The adapter has auto-negotiated the receive link speed with the link partner.

#### NDIS_LINK_STATE_DUPLEX_AUTO_NEGOTIATED

The adapter has auto-negotiated the duplex state with the link partner.

#### NDIS_LINK_STATE_PAUSE_FUNCTIONS_AUTO_NEGOTIATED

The adapter has auto-negotiated the pause functions with the link partner.

### `PowerManagementCapabilitiesEx`

A pointer to an
[NDIS_PM_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_capabilities) structure. This
structure specifies power management capabilities of the miniport adapter. This member is mandatory for
NDIS 6.20 and later drivers.

## Remarks

A miniport driver passes a pointer to an NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES structure in the
*MiniportAttributes* parameter of the
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function. A miniport driver calls
**NdisMSetMiniportAttributes** from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function
during initialization. Miniport drivers should set these attributes after they set the registration
attributes in the
[NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_registration_attributes) structure and before they set any other attributes.
Setting these attribute is mandatory.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_medium)

[NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_registration_attributes)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_PM_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_capabilities)

[NDIS_STATISTICS_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-statistics)

[NET_IF_ACCESS_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_access_type)

[NET_IF_CONNECTION_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_connection_type)

[NET_IF_DIRECTION_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_direction_type)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[OID_802_3_CURRENT_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-802-3-current-address)

[OID_802_3_MAXIMUM_LIST_SIZE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-802-3-maximum-list-size)

[OID_802_3_PERMANENT_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-802-3-permanent-address)

[OID_GEN_CURRENT_LOOKAHEAD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-current-lookahead)

[OID_GEN_LINK_SPEED_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-link-speed-ex)

[OID_GEN_MAC_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-mac-options)

[OID_GEN_MAXIMUM_FRAME_SIZE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-maximum-frame-size)

[OID_GEN_MAX_LINK_SPEED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-max-link-speed)

[OID_GEN_MEDIA_CONNECT_STATUS_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-connect-status-ex)

[OID_GEN_MEDIA_DUPLEX_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-duplex-state)

[OID_GEN_PHYSICAL_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-physical-medium)

[OID_GEN_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-statistics)

[OID_GEN_SUPPORTED_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-supported-list)

[OID_PNP_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-capabilities)