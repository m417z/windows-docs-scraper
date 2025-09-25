# _NDIS_PD_QUEUE_DISPATCH structure

## Description

This structure contains a provider's driver routines for receive or transmit queues.

## Members

### `Header`

The [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the **NDIS_PD_QUEUE_DISPATCH** structure. Set the members of this structure as follows:

* **Type** = **NDIS_OBJECT_TYPE_DEFAULT**
* **Revision** = **NDIS_PD_QUEUE_DISPATCH_REVISION_1**
* **Size** = **NDIS_SIZEOF_PD_QUEUE_DISPATCH_REVISION_1**

### `Flags`

This member is reserved and must be set to 0.

### `PDPostAndDrainBufferList`

A pointer to the provider's [PDPostAndDrainBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_post_and_drain_buffer_list) routine.

### `PDQueryQueueDepth`

A pointer to the provider's [PDQueryQueueDepth](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_query_queue_depth) routine.

### `PDFlushQueue`

A pointer to the provider's [PDFlushQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_flush_queue) routine.

### `PDPostAndDrainBufferListEx`