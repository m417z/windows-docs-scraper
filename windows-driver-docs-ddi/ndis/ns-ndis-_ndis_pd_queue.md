# _NDIS_PD_QUEUE structure

## Description

This structure represents a provider's receive or transmit queue

## Members

### `Header`

The [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the **NDIS_PD_QUEUE** structure. Set the members of this structure as follows:

* **Type** = **NDIS_OBJECT_TYPE_PD_TRANSMIT_QUEUE** or **NDIS_OBJECT_TYPE_PD_RECEIVE_QUEUE**
* **Revision** = **NDIS_PD_QUEUE_REVISION_1**
* **Size** = **NDIS_SIZEOF_PD_QUEUE_REVISION_1**

### `Flags`

This member is reserved and must be set to 0.

### `Dispatch`

See [NDIS_PD_QUEUE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_pd_queue_dispatch).

### `PDPlatformReserved`

Reserved for the platform.

### `PDClientReserved`

Reserved for the client.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)