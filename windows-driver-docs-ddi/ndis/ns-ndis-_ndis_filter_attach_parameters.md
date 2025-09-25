# _NDIS_FILTER_ATTACH_PARAMETERS structure

## Description

The **NDIS_FILTER_ATTACH_PARAMETERS** structure defines the initialization parameters for the filter
module.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_FILTER_ATTACH_PARAMETERS** structure. NDIS sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_FILTER_ATTACH_PARAMETERS.

To indicate the version of the **NDIS_FILTER_ATTACH_PARAMETERS** structure, NDIS sets the
**Revision** member to one of the following values:

#### NDIS_FILTER_ATTACH__PARAMETERS_REVISION_4

Added various members for NDIS 6.30.

NDIS sets the
**Size** member to NDIS_SIZEOF_FILTER_ATTACH_PARAMETERS_REVISION_4.

#### NDIS_FILTER_ATTACH_PARAMETERS_REVISION_3

Added the
**ReceiveFilterCapabilities**,
**MiniportPhysicalDeviceObject**, and
**NicSwitchCapabilities** members for NDIS 6.20.

NDIS sets the
**Size** member to NDIS_SIZEOF_FILTER_ATTACH_PARAMETERS_REVISION_3.

#### NDIS_FILTER_ATTACH_PARAMETERS_REVISION_2

Added the
**HDSplitCurrentConfig** member for NDIS 6.1.

NDIS sets the
**Size** member to NDIS_SIZEOF_FILTER_ATTACH_PARAMETERS_REVISION_2.

#### NDIS_FILTER_ATTACH_PARAMETERS_REVISION_1

Original version for NDIS 6.0.

NDIS sets the
**Size** member to NDIS_SIZEOF_FILTER_ATTACH_PARAMETERS_REVISION_1.

### `IfIndex`

The NDIS interface index of the filter module that NDIS is attaching to the driver stack.

### `NetLuid`

The NDIS network interface
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) value for the filter module that NDIS is
attaching to the driver stack. The NET_LUID is equivalent to the interface name (*ifName* in RFC 2863
*)*.

### `FilterModuleGuidName`

The GUID name of the filter module that NDIS is attaching.

### `BaseMiniportIfIndex`

The NDIS network interface index of the base miniport adapter. That is, if there are virtual
miniports or filter modules that are installed over a physical miniport adapter, the value of this
member is the interface index of the physical miniport adapter or a virtual miniport of the highest-level MUX intermediate driver.

### `BaseMiniportInstanceName`

A pointer to an NDIS_STRING type value that contains a counted Unicode string. This string
specifies the friendly name of the interface for the base miniport adapter. For Windows 2000 and later
versions, NDIS defines the NDIS_STRING type as a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) type.

### `BaseMiniportName`

The name of the base miniport adapter.

### `MediaConnectState`

The
[NET_IF_MEDIA_CONNECT_STATE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_media_connect_state) connection state type.

### `MediaDuplexState`

The media duplex state for the underlying miniport adapter. For more information, see
[OID_GEN_MEDIA_DUPLEX_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-duplex-state).

### `XmitLinkSpeed`

The current transmit link speed of the underlying miniport adapter in bits per second. For more
information, see
[OID_GEN_LINK_SPEED_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-link-speed-ex).

### `RcvLinkSpeed`

The current receive link speed of the underlying miniport adapter in bits per second. For more
information, see
[OID_GEN_LINK_SPEED_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-link-speed-ex).

### `MiniportMediaType`

The
**NdisMedium***Xxx* type that the base underlying miniport adapter supports. For more
information, see
[NDIS_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_medium).

### `MiniportPhysicalMediaType`

The physical medium type for the base underlying miniport adapter. For more information, see
[OID_GEN_PHYSICAL_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-physical-medium).

### `MiniportMediaSpecificAttributes`

A pointer to an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure that
identifies a structure that contains miniport media-specific attributes, or **NULL** if there are no such
attributes. The
**Type** member of the NDIS_OBJECT_HEADER structure identifies the type of the
attributes structure. For example, if the underlying miniport adapter's media type is
**NdisMediumNative802_11**, then the
**Type** member should be
NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES, and the
**MiniportMediaSpecificAttributes** member points to an
[NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff565926(v=vs.85)) structure.

### `DefaultOffloadConfiguration`

A pointer to an
[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload) structure which defines task
offload attributes. The filter driver should review these attributes to obtain the task offload
capabilities of the underlying drivers. The filter driver should modify these attributes, if necessary,
to reflect any changes in the task offload support that it requires.

### `MacAddressLength`

The MAC address length, in bytes. The MAC address length is specific to the type of media.

### `CurrentMacAddress`

The current MAC address. For example, the
[OID_802_3_CURRENT_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-802-3-current-address) OID
specifies the current MAC address for IEEE 802.3 drivers.

### `BaseMiniportNetLuid`

The NDIS network interface
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) of the base miniport adapter. That is, if
there are virtual miniports or filter modules that are installed over a physical miniport adapter, the
value of this member is the NET_LUID of the physical miniport adapter or a virtual miniport of the
highest-level MUX intermediate driver.

### `LowerIfIndex`

The NDIS network interface index of the interface just below the current filter module. That is,
if there are filter modules or NDIS 5.
*x* filter intermediate drivers that are installed over a physical miniport
adapter or the highest-level MUX intermediate driver, this member contains the interface index of the
filter module interface or filter intermediate driver interface that is just below the current filter
module. If there are no filter module or filter intermediate driver interfaces installed over the
physical miniport adapter or the highest-level MUX intermediate driver, this member contains the
interface index of the underlying physical miniport adapter or the highest-level MUX intermediate driver
virtual miniport.

### `LowerIfNetLuid`

The NDIS network interface NET_LUID value of the interface just below the current filter module.
That is, if there are filter modules or NDIS 5.
*x* filter intermediate drivers that are installed over a physical miniport
adapter or the highest-level MUX intermediate driver, this member contains the network interface
NET_LUID of the filter module interface or filter intermediate driver interface that is just below the
current filter module. If there are no filter module or filter intermediate driver interfaces installed
over the physical miniport adapter or the highest-level MUX intermediate driver, this member contains
the network interface NET_LUID of the underlying physical miniport adapter or the highest-level MUX
intermediate driver virtual miniport.

### `Flags`

Reserved for future use.

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

### `MiniportPhysicalDeviceObject`

A pointer to a
[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure. This structure
represents the physical device for the underlying miniport adapter.

### `NicSwitchCapabilities`

A pointer to an
[NDIS_NIC_SWITCH_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_capabilities) structure. This structure specifies the NIC switch capabilities of
the underlying miniport adapter. This value can be **NULL** if the miniport adapter does not support NIC
switch features.

### `BaseMiniportIfConnectorPresent`

A Boolean value that, if set to TRUE, indicates whether a network interface (if) connector is present on the underlying network adapter. This value should be set to TRUE for a physical adapter.

### `SriovCapabilities`

A pointer to an [NDIS_SRIOV_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_sriov_capabilities) structure. This structure specifies the single root I/O virtualization (SR-IOV) capabilities that are currently enabled on the underlying miniport adapter. This value can be **NULL** if the miniport adapter does not support SR-IOV features.

For more information, see [Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/single-root-i-o-virtualization--sr-iov-).

### `NicSwitchArray`

A pointer to an [NDIS_NIC_SWITCH_INFO_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_info_array) structure. This array enumerates the NIC switches that have been created on the miniport adapter. NIC switches can be created only if SR-IOV is supported and enabled on the adapter.

**Note** Starting with Windows Server 2012, Windows supports only the default NIC switch that is created on the physical function (PF) miniport adapter. Therefore, this array can contain only one element.

## Remarks

To define filter module attach parameters, NDIS passes a pointer to an NDIS_FILTER_ATTACH_PARAMETERS
structure to the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

Filter drivers should avoid issuing unnecessary OID queries. Instead, use the information in
NDIS_FILTER_ATTACH_PARAMETERS, when available, to obtain information about underlying drivers.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[NDIS_HD_SPLIT_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_hd_split_current_config)

[NDIS_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ne-ntddndis-_ndis_medium)

[NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff565926(v=vs.85))

[NDIS_NIC_SWITCH_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_capabilities)

[NDIS_NIC_SWITCH_INFO_ARRAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_info_array)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_OFFLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload)

[NDIS_RECEIVE_FILTER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_capabilities)

[NDIS_SRIOV_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_sriov_capabilities)

[NET_IF_MEDIA_CONNECT_STATE](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_media_connect_state)

[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh)

[OID_802_3_CURRENT_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-802-3-current-address)

[OID_GEN_LINK_SPEED_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-link-speed-ex)

[OID_GEN_MEDIA_CONNECT_STATUS_EX](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-connect-status-ex)

[OID_GEN_MEDIA_DUPLEX_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-media-duplex-state)

[OID_GEN_PHYSICAL_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-physical-medium)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)