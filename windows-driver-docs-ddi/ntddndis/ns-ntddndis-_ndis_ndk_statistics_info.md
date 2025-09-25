# _NDIS_NDK_STATISTICS_INFO structure

## Description

The **NDIS_NDK_STATISTICS_INFO** structure contains the NDK statistics.

## Members

### `Header`

An [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure that describes this **NDIS_NDK_STATISTICS_INFO** structure. Set the members of the **NDIS_OBJECT_HEADER** structure as follows:

* Set the **Type** member to **NDIS_OBJECT_TYPE_DEFAULT**.
* Set the **Revision** member to **NDIS_NDK_STATISTICS_INFO_REVISION_1**.
* Set the **Size** member to **NDIS_SIZEOF_NDK_STATISTICS_INFO_REVISION_1**.

### `Flags`

### `CounterSet`

An [NDIS_NDK_PERFORMANCE_COUNTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_performance_counters) structure that contains the NDK performance counters.

## Remarks

The **NDIS_NDK_STATISTICS_INFO** structure is returned with the [OID_NDK_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-ndk-statistics) OID. The **InformationBuffer** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure contains a pointer to this structure.

The NDK-capable miniport driver is required to fill in the **CounterSet** member, which is an [NDIS_NDK_PERFORMANCE_COUNTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_performance_counters) structure.

## See also

[NDIS_NDK_PERFORMANCE_COUNTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_performance_counters)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_NDK_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-ndk-statistics)