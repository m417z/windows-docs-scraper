# _NDIS_NDK_CAPABILITIES structure

## Description

The **NDIS_NDK_CAPABILITIES** structure specifies the capabilities of an NDK adapter.

## Members

### `Header`

The [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure that describes this **NDIS_NDK_CAPABILITIES** structure. Set the members of the **NDIS_OBJECT_HEADER** structure as follows:

* Set the **Type** member to **NDIS_OBJECT_TYPE_DEFAULT**.
* Set the **Revision** member to **NDIS_NDK_CAPABILITIES_REVISION_1**.
* Set the **Size** member to **NDIS_SIZEOF_NDK_CAPABILITIES_REVISION_1**.

### `Flags`

### `MaxQpCount`

The maximum number of queue pairs (QPs) that can be supported by the adapter.

### `MaxCqCount`

The maximum number of completion queues (CQs) that can be supported by the adapter.

### `MaxMrCount`

The maximum number of memory regions (MRs) that can be supported by the adapter.

### `MaxPdCount`

The maximum number of protection domains (PDs) that can be supported by the adapter

### `MaxInboundReadLimit`

The maximum number of incoming outstanding read requests that can be supported by the adapter.
If this member is zero, there is no adapter limit. In this case, there is still a limit for each queue pair. The limit for each queue pair is specified in the **MaxInboundReadLimit** member of the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure.

### `MaxOutboundReadLimit`

The maximum number of outgoing outstanding read requests that can be supported by the adapter.
If this member is zero, there is no adapter-wide limit. In this case, there is still a limit for each queue pair. The limit for each queue pair is specified in the **MaxOutboundReadLimit** member of the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure.

### `MaxMwCount`

The maximum number of memory windows (MWs) that are supported by the adapter.

### `MaxSrqCount`

The maximum number of shared receive queues (SRQs) that are supported by the adapter.

### `MissingCounterMask`

A bitmask that identifies counters that an NDK provider does not support. NDK providers are required to support all the performance counters that are included
in the [NDIS_NDK_PERFORMANCE_COUNTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_performance_counters) structure. However, in the rare case that
a provider cannot support a counter due to extreme implementation difficulties,
the provider must indicate any unsupported counters with the mask value for the
counter which it cannot support.

### `NdkInfo`

A pointer to an [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure that specifies NDK adapter capabilities and limits that are relevant for a specific NDK consumer. These capabilities can be different from system-wide limits.

## Remarks

**NDIS_NDK_CAPABILITIES** specifies capacity limits that are relevant for
system-wide management or partitioning of resources that are available on a given NDK adapter.

Independent of whether NDK functionality of an adapter is currently enabled or disabled,
an NDK-capable adapter must always indicate its capabilities during miniport initialization.

The **NDIS_NDK_CAPABILITIES** structure is used in the [NDIS_MINIPORT_ADAPTER_NDK_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_ndk_attributes) structure.

## See also

[NDIS_MINIPORT_ADAPTER_NDK_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_ndk_attributes)

[NDIS_NDK_PERFORMANCE_COUNTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_performance_counters)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info)