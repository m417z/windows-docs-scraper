# NDK_ADAPTER_INFO structure

## Description

The **NDK_ADAPTER_INFO** structure specifies information about limits and capabilities of an NDK adapter.

## Members

### `Version`

The major and minor versions of the NDK interface ([NDK_VERSION](https://learn.microsoft.com/windows/desktop/api/ndkinfo/ns-ndkinfo-ndk_version)).

### `VendorId`

A vendor's organizational unique identifier (OUI).

### `DeviceId`

A vendor defined device identifier.

### `MaxRegistrationSize`

The maximum size, in bytes, of a single memory registration that the adapter can address.

### `MaxWindowSize`

The maximum size, in bytes, for a single memory window.

### `FRMRPageCount`

The fast-register memory region (FRMR) size (in **PAGE_SIZE** pages) for which the adapter supports the greatest number of FRMRs. A provider must support at least 16 FRMR pages. This value is typically used by upper layers as an FRMR size that optimizes concurrent FRMR-based I/O operations. Hence, advertising a value greater than 16 should be done only if the total number of FRMRs supported with that size is not meaningfully reduced as a result.

### `MaxInitiatorRequestSge`

The maximum number of scatter-gather entries (SGEs) that can be specified in a single request over an initiator queue.

### `MaxReceiveRequestSge`

The maximum number of SGEs that can be specified in a single request over a receive queue.

### `MaxReadRequestSge`

The maximum number of SGEs that can be specified in a read request.

**Note** This value overrides the **MaxInitiatorRequestSge** value for read requests.

### `MaxTransferLength`

The maximum total length that can be referenced by all SGEs in a single send, receive, read, or write request.

### `MaxInlineDataSize`

The maximum amount of inline data, in bytes, that can be sent in a single send or write request.

### `MaxInboundReadLimit`

The maximum number of in-progress incoming read operations for each QP.

### `MaxOutboundReadLimit`

The maximum number of in-progress outgoing read operations for each QP.

### `MaxReceiveQueueDepth`

The maximum number of outstanding requests for each receive queue.

### `MaxInitiatorQueueDepth`

The maximum number of outstanding requests for each initiator queue.

### `MaxSrqDepth`

The maximum number of outstanding requests for each shared receive queue (SRQ). A value of zero means no SRQ support.

### `MaxCqDepth`

The maximum number of completion entries for each completion queue (CQ).

### `LargeRequestThreshold`

The data size hint, in bytes, above which read and write operations will yield better results than send and receive operations.

### `MaxCallerData`

 The maximum size, in bytes, of the private data that can be sent with a
connect request.

### `MaxCalleeData`

The maximum size, in bytes, of the private data that can be sent with an accept or reject request.

### `AdapterFlags`

A set of flags that determine adapter properties. The currently defined flags include:

| Value | Meaning |
| --- | --- |
| **NDK_ADAPTER_FLAG_IN_ORDER_DMA_SUPPORTED**<br><br>0x00000001 | Set if the provider writes incoming data into the consumer’s buffer in order. That is, the last byte position in the consumer’s buffer is guaranteed not to be updated before any prior byte position. |
| **NDK_ADAPTER_FLAG_RDMA_READ_SINK_NOT_REQUIRED**<br><br>0x00000002 | Set if the provider does not require special access rights on the sink buffer for an RDMA read request. When this flag is set, the consumer is not required to use the NDK_MR_FLAG_RDMA_READ_SINK or NDK_OP_FLAG_RDMA_READ_SINK flags when it registers sink buffers for RDMA read requests. The consumer can also use logical address mappings directly (with a token obtained with the [NDK_FN_GET_PRIVILEGED_MEMORY_REGION_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndkpi/nc-ndkpi-ndk_fn_get_privileged_memory_region_token) function) as RDMA read sink buffers. This is similar to access to local buffers for RDMA write, send, and receive operations. |
| **NDK_ADAPTER_FLAG_CQ_INTERRUPT_MODERATION_SUPPORTED**<br><br>0x00000004 | Set if the provider supports programmatically controlled interrupt moderation for each completion queue (CQ). When this flag is set, an NDK consumer can use the [NDK_FN_CONTROL_CQ_INTERRUPT_MODERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndkpi/nc-ndkpi-ndk_fn_control_cq_interrupt_moderation) function in the [NDK_CQ_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndkpi/ns-ndkpi-_ndk_cq_dispatch) table. |
| **NDK_ADAPTER_FLAG_MULTI_ENGINE_SUPPORTED**<br><br>0x00000008 | Set if the provider supports concurrent processing of multiple connections with multiple execution engines. If this flag is set, an NDK consumer that uses more than one connection concurrently on the adapter might provide better performance than a single connection. |
| **NDK_ADAPTER_FLAG_RDMA_READ_LOCAL_INVALIDATE_SUPPORTED**<br><br>0x00000010 | Set if the provider supports invalidation of the local token specified in the first [NDK_SGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndkpi/ns-ndkpi-_ndk_sge) passed to an *NdkRead* ([NDK_FN_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndkpi/nc-ndkpi-ndk_fn_read)) function when completing the read request.<br><br>**Note** This value is supported only in NDKPI 1.2 (Windows Server 2012 R2) and later. |
| **NDK_ADAPTER_FLAG_CQ_RESIZE_SUPPORTED**<br><br>0x00000100 | Set if the provider supports resizing CQ objects. If this flag is not set, the consumer must not attempt a CQ resize. |
| **NDK_ADAPTER_FLAG_LOOPBACK_CONNECTIONS_SUPPORTED**<br><br>0x00010000 | Set if the provider supports loopback connections. That is, loopback from a local network address on a given RNIC to the same local address on the same RNIC. |

### `RdmaTechnology`

## Remarks

The [NDK_FN_QUERY_ADAPTER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndkpi/nc-ndkpi-ndk_fn_query_adapter_info) function retrieves the **NDK_ADAPTER_INFO**, which contains information on various limits and capabilities of the adapter.

## See also

[NDK_CQ_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndkpi/ns-ndkpi-_ndk_cq_dispatch)

[NDK_FN_CONTROL_CQ_INTERRUPT_MODERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndkpi/nc-ndkpi-ndk_fn_control_cq_interrupt_moderation)

[NDK_FN_GET_PRIVILEGED_MEMORY_REGION_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ndkpi/nc-ndkpi-ndk_fn_get_privileged_memory_region_token)

[NDK_VERSION](https://learn.microsoft.com/windows/desktop/api/ndkinfo/ns-ndkinfo-ndk_version)