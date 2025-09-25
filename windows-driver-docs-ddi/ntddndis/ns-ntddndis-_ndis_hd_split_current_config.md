# _NDIS_HD_SPLIT_CURRENT_CONFIG structure

## Description

The NDIS_HD_SPLIT_CURRENT_CONFIG structure provides the current header-data split configuration of a
miniport adapter.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_HD_SPLIT_CURRENT_CONFIG structure. The driver sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_HD_SPLIT_CURRENT_CONFIG_REVISION_1, and the
**Size** member to NDIS_SIZEOF_HD_SPLIT_CURRENT_CONFIG_REVISION_1.

### `HardwareCapabilities`

The header-data split hardware capabilities that the miniport adapter supports. These capabilities
should include capabilities that are currently disabled by INF file settings or through the
**Advanced** properties page. The value of
**HardwareCapabilities** is a bitwise OR of the following flags:

#### NDIS_HD_SPLIT_CAPS_SUPPORTS_HEADER_DATA_SPLIT

The miniport adapter can split the header and data into separate memory descriptor lists (MDLs)
that meet the requirements for header-data split support.

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

A set of flags that reports the status of header-data split for a miniport adapter. NDIS sets this
member with a bitwise OR of the following flags:

#### NDIS_HD_SPLIT_ENABLE_HEADER_DATA_SPLIT

The miniport driver has enabled header-data split in the hardware. Otherwise, header-data split
is disabled.

### `HDSplitCombineFlags`

A set of flags that specify the current header-data split settings of a miniport adapter. The
value of
**HDSplitCombineFlags** can be a bitwise OR of the following flags:

#### NDIS_HD_SPLIT_COMBINE_ALL_HEADERS

The miniport adapter is combining split frames. If header-data split is enabled in the hardware,
the miniport driver should combine the header and data before indicating the frame to NDIS.

### `BackfillSize`

The backfill size, in bytes, that the miniport driver is using for the data portion of a split
frame.

### `MaxHeaderSize`

The maximum size, in bytes, that the miniport driver is using for the header portion of a split
frame.

**Note** If the length of a header exceeds
**MaxHeaderSize** because of the presence of IPv4 options, IPsec headers, or IPv6 extension headers,
the frame must not be split. If a header that includes a TCP or UDP header exceeds
**MaxHeaderSize** because of the presence of TCP header, TCP options, or UDP header, the NIC must
split the frame at the beginning of the upper layer protocol header or must not split the
frame.

## Remarks

The NDIS_HD_SPLIT_CURRENT_CONFIG structure is used in the
[OID_GEN_HD_SPLIT_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-hd-split-current-config) OID query request to obtain the current header-data split
configuration of a miniport adapter.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[OID_GEN_HD_SPLIT_CURRENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-hd-split-current-config)