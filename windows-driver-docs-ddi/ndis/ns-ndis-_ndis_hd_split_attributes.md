# _NDIS_HD_SPLIT_ATTRIBUTES structure

## Description

The NDIS_HD_SPLIT_ATTRIBUTES structure defines header-data split attributes, if any, that are
associated with a miniport adapter.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
provider characteristics structure (NDIS_HD_SPLIT_ATTRIBUTES). The driver sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_HD_SPLIT_ATTRIBUTES, the
**Revision** member to NDIS_OBJECT_HD_SPLIT_ATTRIBUTES_REVISION_1, and the
**Size** member to NDIS_SIZEOF_HD_SPLIT_ATTRIBUTES_REVISION_1.

### `HardwareCapabilities`

The header-data split hardware capabilities that the miniport adapter supports. These capabilities
should include capabilities that are currently disabled by INF file settings or through the
**Advanced** properties page. The value of
**HardwareCapabilities** is a bitwise OR of the following flags:

#### NDIS_HD_SPLIT_CAPS_SUPPORTS_HEADER_DATA_SPLIT

The miniport adapter can split the header and data into separate MDLs that meet the requirements
for header-data split support.

#### NDIS_HD_SPLIT_CAPS_SUPPORTS_IPV4_OPTIONS

The miniport adapter can split IPv4 Ethernet frames that include IPv4 options. The miniport
adapter can support splitting some IPv4 options while not splitting others.

**Note** The NIC must not split IPv4 frames that contain unsupported IPv4 options. If an
IPv4 frame is split, the header portion of the split frame must contain the entire IPv4 header and all
of the IPv4 options that are present.

#### NDIS_HD_SPLIT_CAPS_SUPPORTS_IPV6_EXTENSION_HEADERS

The miniport adapter can split IPv6 Ethernet frames that include IPv6 extension headers. The
miniport adapter can support some IPv6 extension headers while not supporting others.

**Note** The NIC must not split IPv6 frames that contain unsupported IPv6 extension
headers. If an IPv6 frame is split, the header portion of the split frame must contain the entire IPv6
header and all of the IPv6 extension headers that are present.

#### NDIS_HD_SPLIT_CAPS_SUPPORTS_TCP_OPTIONS

The miniport adapter can split TCP frames with other TCP options in addition to the timestamp
option. The miniport adapter can support some TCP options and not support others.

**Note** If the only TCP option in a frame is the timestamp option, the data-split
provider must be able to split the frame.

**Note** If a TCP header contains an unsupported TCP option, the NIC must split the frame
at the beginning of the TCP header or must not split the frame.

### `CurrentCapabilities`

The current header-data split capabilities that the miniport adapter supports. The miniport driver
uses the same flags that are defined for the
**HardwareCapabilities** member. In this case, the flags are set to indicate the current capabilities
that depend on the current configuration settings.

### `HDSplitFlags`

A set of flags that control the status of header-data split for a miniport adapter. The miniport
driver should set this member to zero before calling the
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function. After
**NdisMSetMiniportAttributes** successfully returns, the driver must check the flags and configure the
hardware accordingly. NDIS sets this member with a bitwise OR of the following flags:

#### NDIS_HD_SPLIT_ENABLE_HEADER_DATA_SPLIT

If this flag is set, the miniport driver should enable header-data split in the hardware.
Otherwise, header-data split is disabled. If the computer uses header-data split and the miniport
driver also set the NDIS_HD_SPLIT_CAPS_SUPPORTS_HEADER_DATA_SPLIT flag in the
**CurrentCapabilities** member, NDIS sets NDIS_HD_SPLIT_ENABLE_HEADER_DATA_SPLIT.

### `BackfillSize`

The backfill size, in bytes, for the data portion of a split frame. The miniport driver should set
**BackfillSize** to zero before calling
**NdisMSetMiniportAttributes**. NDIS sets this member if the miniport driver must pre-allocate
backfill storage in the data portion for split frames. After
**NdisMSetMiniportAttributes** successfully returns, the driver must use the
**BackfillSize** value that NDIS set to pre-allocate the data buffers.

### `MaxHeaderSize`

The maximum size, in bytes, for the header portion of a split frame. The miniport driver should
set
**MaxHeaderSize** to zero before calling
**NdisMSetMiniportAttributes**. NDIS sets this member to the maximum size for the header buffer for
split frames. After
**NdisMSetMiniportAttributes** successfully returns, the driver must use the value that NDIS provided.

**Note** If the length of a header exceeds
**MaxHeaderSize** because of the presence of IPv4 options, IPSec headers, or IPv6 extension headers,
the frame must not be split. If a header that includes a TCP or UDP header exceeds
**MaxHeaderSize** because of the presence of TCP header, TCP options, or UDP header, the NIC must
split the frame at the beginning of the upper layer protocol header or must not split the
frame.

## Remarks

To support header-data split, a miniport driver passes a pointer to an
[NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_hardware_assist_attributes) structure in the
*MiniportAttributes* parameter of the
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function. The
**HDSplitAttributes** member of NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES contains a pointer to
the NDIS_HD_SPLIT_ATTRIBUTES structure. A miniport driver calls
**NdisMSetMiniportAttributes** from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function
during initialization.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_hardware_assist_attributes)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)