# _NDIS_PD_PROVIDER_DISPATCH structure

## Description

This structure is used as input for the [OID_PD_OPEN_PROVIDER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pd-open-provider) and serves as a container for all the provider's driver routines.

## Members

### `Header`

The [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the **NDIS_PD_PROVIDER_DISPATCH** structure. Set the members of this structure as follows:

* **Type** = **NDIS_OBJECT_TYPE_DEFAULT**
* **Revision** = **NDIS_PD_PROVIDER_DISPATCH_REVISION_1**
* **Size** = **NDIS_SIZEOF_PD_PROVIDER_DISPATCH_REVISION_1**

### `Flags`

This member is reserved and must be set to 0 by the provider.

### `NdisPDAllocateQueue`

See [NdisPDAllocateQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_allocate_queue).

### `NdisPDFreeQueue`

See [NdisPDFreeQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_free_queue).

### `NdisPDAcquireReceiveQueues`

### `NdisPDReleaseReceiveQueues`

### `NdisPDAllocateCounter`

See [NdisPDAllocateCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_allocate_counter).

### `NdisPDFreeCounter`

See [NdisPDFreeCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_free_counter).

### `NdisPDQueryCounter`

See [NdisPDQueryCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_query_counter).

### `NdisPDSetReceiveFilter`

See [NdisPDSetReceiveFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_set_receive_filter).

### `NdisPDClearReceiveFilter`

See [NdisPDClearReceiveFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_clear_receive_filter).

### `NdisPDRequestDrainNotification`

### `NdisPDQueueControl`

### `NdisPDProviderControl`

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)