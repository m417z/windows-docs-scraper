# _NDIS_BIND_PARAMETERS structure

## Description

NDIS initializes an **NDIS_BIND_PARAMETERS** structure with information that defines the characteristics
of a binding and passes it to a protocol driver.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_BIND_PARAMETERS** structure. NDIS sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_BIND_PARAMETERS.

To indicate the version of the NDIS_BIND_PARAMETERS structure, NDIS sets the
**Revision** member to one of the following values:

#### NDIS_BIND_PARAMETERS_REVISION_4

Added various members for NDIS 6.30.

NDIS sets the
**Size** member to NDIS_SIZEOF_BIND_PARAMETERS_REVISION_4.

#### NDIS_BIND_PARAMETERS_REVISION_3

Added the
**ReceiveFilterCapabilities**,
**PowerManagementCapabilitiesEx**, and
**NicSwitchCapabilities** members for NDIS 6.20.

NDIS sets the
**Size** member to NDIS_SIZEOF_BIND_PARAMETERS_REVISION_3.

#### NDIS_BIND_PARAMETERS_REVISION_2

Added the
**HDSplitCurrentConfig** member for NDIS 6.1.

NDIS sets the
**Size** member to NDIS_SIZEOF_BIND_PARAMETERS_REVISION_2.

#### NDIS_BIND_PARAMETERS_REVISION_1

Original version for NDIS 6.0.

NDIS sets the
**Size** member to NDIS_SIZEOF_BIND_PARAMETERS_REVISION_1.

### `ProtocolSection`

A pointer to a Unicode string that contains a registry path. The path starts from the protocol
driver's service key and continues down the registry hierarchy to the miniport adapter name (for
example,
**Tcpip\Parameters\Adapters\\**\<*miniport adapter name*\>). The miniport adapter name is the name of the
bottom-most miniport adapter in the driver stack. If there is a MUX intermediate driver in the stack,
the bottom-most miniport adapter is a virtual miniport. Otherwise, the bottom-most miniport adapter is a
miniport adapter for a physical device.

The protocol driver can use this registry path to read configuration parameters that are specific to
the binding between the driver and the underlying miniport adapter.

### `AdapterName`

A pointer to a Unicode string that contains the name of the underlying miniport adapter to which
*ProtocolBindAdapterEx* should bind.

### `PhysicalDeviceObject`

The physical device object for the underlying miniport adapter.

### `MediaType`

The
**NdisMedium***Xxx* type that the underlying miniport adapter supports. For more information
about
**NdisMedium***Xxx* types, see
[NDIS_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_medium).

### `MtuSize`

The maximum transfer unit (MTU) size. For more information, see
[OID_GEN_MAXIMUM_FRAME_SIZE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-maximum-frame-size).

### `MaxXmitLinkSpeed`

The maximum transmit link speed of the underlying adapter in bits per second. For more
information, see
[OID_GEN_MAX_LINK_SPEED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-max-link-speed).

### `XmitLinkSpeed`

The current transmit link speed of the underlying adapter in bits per second. For more
information, see
[OID_GEN_LINK_SPEED_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-link-speed-ex).

### `MaxRcvLinkSpeed`

The maximum receive link speed of the underlying adapter in bits per second. For more information,
see
[OID_GEN_MAX_LINK_SPEED](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-max-link-speed).

### `RcvLinkSpeed`

The current receive link speed of the underlying adapter in bits per second. For more information,
see
[OID_GEN_LINK_SPEED_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-link-speed-ex).

### `MediaConnectState`

The media connect state for the underlying miniport adapter. For more information, see
[OID_GEN_MEDIA_CONNECT_STATUS_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-connect-status-ex).

### `MediaDuplexState`

The media duplex state for the underlying miniport adapter. For more information, see
[OID_GEN_MEDIA_DUPLEX_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-duplex-state).

### `LookaheadSize`

The lookahead size for the underlying miniport adapter. For more information, see
[OID_GEN_CURRENT_LOOKAHEAD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-current-lookahead).

### `PowerManagementCapabilities`

The Plug and Play capabilities of the underlying miniport adapter. For more information, see
[OID_PNP_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-capabilities). NDIS 6.20 and
later drivers must use the
**PowerManagementCapabilitiesEx** member instead.

### `SupportedPacketFilters`

A set of flags that identify the types of network packets that the underlying miniport adapter can filter.

### `MaxMulticastListSize`

The multicast address list size for the underlying miniport adapter. For more information, see
[OID_802_3_MAXIMUM_LIST_SIZE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-802-3-maximum-list-size).

### `MacAddressLength`

The MAC address length, in bytes. The MAC address length is specific to the type of media.

### `CurrentMacAddress`

The current MAC address. For example, the
[OID_802_3_CURRENT_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-802-3-current-address) OID
specifies the current MAC address for IEEE 802.3 drivers.

### `PhysicalMediumType`

The physical medium type for the miniport adapter. For more information, see
[OID_GEN_PHYSICAL_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-physical-medium).

### `RcvScaleCapabilities`

The [receive side scaling (RSS)](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-receive-side-scaling2) capabilities of the NIC. For more information, see
[OID_GEN_RECEIVE_SCALE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-capabilities).

### `BoundIfNetluid`

The NDIS
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) value, that is also the network interface
name (
*ifName* in RFC 2863), of the highest level interface that is stacked on the
miniport adapter. That is, if there are virtual miniports or filter modules that are installed over the
miniport adapter, this is the NET_LUID value of the highest level virtual miniport or filter
module.

### `BoundIfIndex`

The NDIS network interface index of the highest level interface that is stacked on the miniport
adapter. That is, if there are virtual miniports or filter modules that are installed over the miniport
adapter, this is the ifIndex of the highest level virtual miniport or filter module.

### `LowestIfNetluid`

The NDIS
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) value, that is also the network interface
name (
*ifName* in RFC 2863), of the lowest level interface on a binding. That is, the
NDIS network interface of the miniport adapter at the bottom of a filter stack.

### `LowestIfIndex`

The NDIS network interface index of lowest level interface on a binding. That is, the NDIS network
interface of the miniport adapter at the bottom of a filter stack.

### `AccessType`

A
[NET_IF_ACCESS_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_access_type) NDIS network interface
access type.

### `DirectionType`

A
[NET_IF_DIRECTION_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_direction_type) NDIS network
interface direction type.

### `ConnectionType`

The NDIS network interface connection type. Use **NET_IF_CONNECTION_DEDICATED** for a typical Ethernet
adapter. The following values are valid:

#### NET_IF_CONNECTION_DEDICATED

Specifies the dedicated connection type. The connection comes up automatically when media sense
is **TRUE**. For example, an Ethernet connection is dedicated.

#### NET_IF_CONNECTION_PASSIVE

Specifies the passive connection type. The other end must bring up the connection to the local
station. For example, the RAS interface is passive.

#### NET_IF_CONNECTION_DEMAND

Specifies the demand-dial connection type. A demand-dial connection comes up in response to a
local action--for example, sending a packet.

### `IfType`

The Internet Assigned Numbers Authority (IANA) interface type. For example,
IF_TYPE_ETHERNET_CSMACD (6) is the value for
**IfType** that is assigned to any Ethernet-like interface. For a list if
interface types, see
[NDIS Interface Types](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-interface-types).

### `IfConnectorPresent`

A Boolean value that indicates if a connector is present. NDIS sets this value to **TRUE** if there is
a physical adapter.

### `ActivePorts`

To be determined.

### `DataBackFillSize`

The required data backfill size, in bytes, of the underlying driver stack.

### `ContextBackFillSize`

The required context backfill size, in bytes, of the underlying driver stack.

### `MacOptions`

The MAC options for the miniport adapter. For more information, see
[OID_GEN_MAC_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-mac-options).

### `CompartmentId`

The compartment to which the underlying interface belongs or one of the following values:

#### NET_IF_COMPARTMENT_ID_UNSPECIFIED

Specifies that the compartment identifier is not used or specified.

#### NET_IF_COMPARTMENT_ID_PRIMARY

Specifies the default compartment identifier. Third party interface providers must always
specify NET_IF_COMPARTMENT_ID_PRIMARY. All other values are reserved for Microsoft internal
use.

### `DefaultOffloadConfiguration`

A pointer to an
[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload) structure. This structure
specifies the capabilities for a task-offload-capable miniport adapter. For more information, see
[OID_TCP_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-offload-current-config).

### `TcpConnectionOffloadCapabilities`

A pointer to an
[NDIS_TCP_CONNECTION_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_tcp_connection_offload) structure that indicates the current offload capabilities that are
provided by the underlying miniport adapter.

### `BoundAdapterName`

A pointer to a Unicode string that contains the name of the highest-level miniport adapter that is
stacked on the underlying miniport adapter. That is, if there are filter intermediate driver virtual
miniports that are installed over the miniport adapter, this member is the name of the highest-level
filter intermediate driver virtual miniport.

### `HDSplitCurrentConfig`

A pointer to an
[NDIS_HD_SPLIT_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_hd_split_current_config) structure. This structure specifies the current header-data split
configuration of the underlying miniport adapter. This value can be **NULL** if the miniport adapter does
not support header-data split.

### `ReceiveFilterCapabilities`

A pointer to an
[NDIS_RECEIVE_FILTER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_capabilities) structure. This structure specifies the generic filtering
capabilities that are currently enabled on the underlying miniport adapter. This value can be **NULL** if the miniport adapter does not
support receive filtering.

### `PowerManagementCapabilitiesEx`

A pointer to an
[NDIS_PM_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_capabilities) structure. This
structure specifies power management capabilities of the miniport adapter. This member is mandatory for
NDIS 6.20 and later drivers.

### `NicSwitchCapabilities`

A pointer to an
[NDIS_NIC_SWITCH_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_capabilities) structure. This structure specifies the NIC switch capabilities of
the underlying miniport adapter. This value can be **NULL** if the miniport adapter does not support NIC
switch features.

### `NDKEnabled`

NDIS sets this value to **TRUE** if the network direct kernel provider interface (NDKPI) is currently enabled on the underlying miniport adapter.

### `NDKCapabilities`

A pointer to an [NDIS_NDK_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_capabilities) structure. This structure specifies the NDKPI capabilities that are currently enabled on the underlying miniport adapter. This value can be **NULL** if the miniport adapter does not support NDKPI.

### `SriovCapabilities`

A pointer to an [NDIS_SRIOV_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_sriov_capabilities) structure. This structure specifies the single root I/O virtualization (SR-IOV) capabilities that are currently enabled on the underlying miniport adapter. This value can be **NULL** if the miniport adapter does not support SR-IOV features.

### `NicSwitchArray`

A pointer to an [NDIS_NIC_SWITCH_INFO_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_info_array) structure. This array enumerates the NIC switches that have been created on the miniport adapter. NIC switches can only be created if SR-IOV is supported and enabled on the adapter.

**Note** Starting with Windows Server 2012, Windows supports only the default NIC switch on the miniport adapter. Therefore, this array can contain only one element.

## Remarks

NDIS passes a pointer to an NDIS_BIND_PARAMETERS structure in the
*BindParameters* parameter of the
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function.

## See also

[NDIS_HD_SPLIT_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_hd_split_current_config)

[NDIS_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_medium)

[NDIS_NIC_SWITCH_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_capabilities)

[NDIS_NIC_SWITCH_INFO_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_info_array)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload)

[NDIS_PM_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pm_capabilities)

[NDIS_RECEIVE_FILTER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_capabilities)

[NDIS_SRIOV_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_sriov_capabilities)

[NDIS_TCP_CONNECTION_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_tcp_connection_offload)

[NET_IF_ACCESS_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_access_type)

[NET_IF_DIRECTION_TYPE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_direction_type)

[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh)

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

[OID_GEN_RECEIVE_SCALE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-capabilities)

[OID_PNP_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-capabilities)

[OID_TCP_OFFLOAD_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-tcp-offload-current-config)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)