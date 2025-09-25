# _NDIS_RSS_PROCESSOR_INFO structure

## Description

The **NDIS_RSS_PROCESSOR_INFO** structure specifies information about the CPU receive side scaling (RSS)
processor set on the local computer.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_RSS_PROCESSOR_INFO** structure. NDIS sets the
**Type** member of the structure that
**Header** specifies to **NDIS_OBJECT_TYPE_RSS_PROCESSOR_INFO**. NDIS also sets the
**Revision** and
**Size** members to the values shown in the following table.

| NDIS version | Revision value | Size value |
| --- | --- | --- |
| NDIS 6.20 | **NDIS_RSS_PROCESSOR_INFO_REVISION_1** | **NDIS_SIZEOF_RSS_PROCESSOR_INFO_REVISION_1** |
| NDIS 6.30 | **NDIS_RSS_PROCESSOR_INFO_REVISION_2** | **NDIS_SIZEOF_RSS_PROCESSOR_INFO_REVISION_2** |

### `Flags`

Reserved. NDIS sets this member to zero.

### `RssBaseProcessor`

The starting processor number that is used for RSS.

**Note** The RSS base CPU number is the CPU number of the first CPU that RSS can use. RSS cannot use the CPUs that are numbered below the base CPU number.

### `MaxNumRssProcessors`

The maximum number of processors that are used for RSS

### `PreferredNumaNode`

The preferred NUMA node, which is the node closest to the NIC

### `RssProcessorArrayOffset`

The offset, in bytes, from the start of the structure to an array of
[NDIS_RSS_PROCESSOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_rss_processor) structures, with each
entry describing an RSS processor on the system. The
**RssProcessorCount** member contains the number of **NDIS_RSS_PROCESSOR** structures in the array. The
**RssProcessorEntrySize** member contains the size of the **NDIS_RSS_PROCESSOR** structures in the
array.

### `RssProcessorCount`

The number of elements in the array of [NDIS_RSS_PROCESSOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_rss_processor) structures that follows this
structure.

### `RssProcessorEntrySize`

The size, in bytes, of elements in the array of [NDIS_RSS_PROCESSOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_rss_processor) structures that follows this
structure.

### `RssMaxProcessor`

The maximum processor number that is used for RSS.

### `RssProfile`

Reserved.

## Remarks

NDIS network drivers use the **NDIS_RSS_PROCESSOR_INFO** structure in calls to the
[NdisGetRssProcessorInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetrssprocessorinformation) function. After
**NdisGetRssProcessorInformation** returns, this structure contains information about the set of
processors that will be used for receive side scaling (RSS).

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RSS_PROCESSOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_rss_processor)

[NDIS_RSS_PROFILE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/jj849980(v=vs.85))

[NdisGetRssProcessorInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisgetrssprocessorinformation)