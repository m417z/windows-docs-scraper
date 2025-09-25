# _NDIS_RSS_SET_INDIRECTION_ENTRIES structure

## Description

> [!WARNING]
> Some information in this topic relates to prereleased product, which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.
>
> RSSv2 is preview only in Windows 10, version 1803.

The **NDIS_RSS_SET_INDIRECTION_ENTRIES** structure represents a set of actions, where each action moves a single entry of the Receive Side Scaling (RSS) indirection table of a specified VPort to a specified target CPU. It is used in the [OID_GEN_RSS_SET_INDIRECTION_TABLE_ENTRIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-rss-set-indirection-table-entries) OID, which is a [Synchronous OID](https://learn.microsoft.com/windows-hardware/drivers/network/synchronous-oid-request-interface-in-ndis-6-80) for [RSS Version 2 (RSSv2)](https://learn.microsoft.com/windows-hardware/drivers/network/receive-side-scaling-version-2-rssv2-).

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_RSS_SET_INDIRECTION_ENTRIES** structure. Set the
**Type** member of the structure that
**Header** specifies to **NDIS_OBJECT_TYPE_RSS_SET_INDIRECTION_ENTRIES**.

For NDIS 6.80 and later drivers, set the
**Revision** member to **NDIS_RSS_SET_INDIRECTION_ENTRIES_REVISION_1** and the
**Size** member to **sizeof(NDIS_RSS_SET_INDIRECTION_ENTRIES)**.

### `Flags`

A **ULONG** value that contains a bitwise OR of flags. This member qualifies the other members of this structure, as well as the array processing policy. In Windows 10, version 1803, no flags are defined for this member.

### `RssEntrySize`

An opaque number that needs to be added to the pointer during array traversal.

### `RssEntryTableOffset`

The offset of the [NDIS_RSS_SET_INDIRECTION_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_rss_set_indirection_entry) array from the beginning of this structure.

### `NumberOfRssEntries`

The number of formatted [NDIS_RSS_SET_INDIRECTION_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_rss_set_indirection_entry) structures in the array.

## See also

[NDIS_NIC_SWITCH_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_nic_switch_capabilities)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RSS_SET_INDIRECTION_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_rss_set_indirection_entry)

[OID_GEN_RSS_SET_INDIRECTION_TABLE_ENTRIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-rss-set-indirection-table-entries)

[Receive Side Scaling Version 2 (RSSv2)](https://learn.microsoft.com/windows-hardware/drivers/network/receive-side-scaling-version-2-rssv2-)

[Synchronous OID request interface in NDIS 6.80](https://learn.microsoft.com/windows-hardware/drivers/network/synchronous-oid-request-interface-in-ndis-6-80)