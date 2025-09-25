# _NDIS_PD_CAPABILITIES structure

## Description

This structure indicates the PD capabilities for a provider.

## Members

### `Header`

The [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the **NDIS_PD_CAPABILITIES** structure. Set the members of this structure as follows:

* **Type** = **NDIS_OBJECT_TYPE_DEFAULT**
* **Revision** = **NDIS_PD_CAPABILITIES_REVISION_1**
* **Size** = **NDIS_SIZEOF_PD_CAPABILITIES_REVISION_1**

### `Flags`

This member is reserved and must be set to 0.

### `MaximumTxPartialBufferCount`

The maximum partial transmit [PD_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_pd_buffer) chain lengths supported by the provider.

### `MaximumRxPartialBufferCount`

The maximum partial receive [PD_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_pd_buffer) chain lengths supported by the provider.

### `RxFilterContextWidth`

The filter context width that the provider supports. A provider can support up to 64-bits in width.

### `CapabilityFlags`

Flags that contain additional capabilities that the provider supports.

| Flag | Description |
| --- | --- |
| **NDIS_PD_CAPS_RECEIVE_FILTER_COUNTERS_SUPPORTED** | This flag indicates that the provider supports creation of counters with the **PDCounterTypeReceiveFilter** type that is part of the [NDIS_PD_COUNTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ne-ndis-ndis_pd_counter_type) enumeration |

### `MaxNumberOfRxQueues`

The maximum number of receive queues the provider supports. This is only relevant to queues created by the [NdisPDAllocateQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_allocate_queue) routine, therefore this number is not accurate for the client because additional pre-existing RSS queues (that the client can request PD-mode access to using the [NdisPDOnRssReceiveQueues](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/)) are not accounted for in the *NdisPDAllocateQueue* routine.

It is possible for providers to set this value to 0, if it only supports clients to put pre-existing RSS queues into PD-mode using the [NdisPDOnRssReceiveQueues](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/) routine.

### `MaxNumberOfTxQueues`

The maximum number of transmit queues the provider can create using the [NdisPDAllocateQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_allocate_queue) routine. The provider must not set this value to 0.

### `MaxNumberOfRxQueuesForDefaultVport`

The maximum number of receive queues that the provider supports for the default virtual port.

### `MaxNumberOfTxQueuesForDefaultVport`

The maximum number of transmit queues that the provider supports for the default virtual port.

### `MaxNumberOfRxQueuesPerNonDefaultVport`

The maximum number of receive queues that the provider supports for non-default virtual ports.

### `MaxNumberOfTxQueuesPerNonDefaultVport`

The maximum number of transmit queues that the provider supports for non-default virtual ports.

### `ExactMatchProfileArrayOffset`

The array offset for an array of NDIS_GFP_EXACT_MATCH_PROFILE structures.

### `ExactMatchProfileArrayNumElements`

The number of elements for an array of NDIS_GFP_EXACT_MATCH_PROFILE structures.

### `ExactMatchProfileArrayElementSize`

The number of elements for an array of NDIS_GFP_EXACT_MATCH_PROFILE structures.

### `WildcardMatchProfileArrayOffset`

The array offset for an array of NDIS_GFP_WILDCARD_MATCH_PROFILE structures.

### `WildcardMatchProfileArrayNumElements`

The number of elements for an array of NDIS_GFP_WILDCARD_MATCH_PROFILE structures.

### `WildcardMatchProfileArrayElementSize`

The number of elements for an array of NDIS_GFP_WILDCARD_MATCH_PROFILE structures.

### `MinimumModerationInterval`

### `MaximumModerationInterval`

### `ModerationIntervalGranularity`

### `MaxRxQueueSize`

### `MaxTxQueueSize`

### `DmaAddressWidth`

The DMA address width that the provider supports. Ideally, providers would support a 64-bit wide DMA address width, and setting this value to 0 indicates that a 64-bit wide DMA address. Providers must support a minimum of 32-bits in width, this means that valid values are either 0 or between 32-64 inclusive.

## Remarks

This structure must be aligned on an 8-byte boundary.

If the provider has a flexible implementation where it supports a maximum number of N queues, where any queue can be purposed flexibly as either an Rx or Tx queue, the provider should advertise ~N/2 for the MaxNumberOfRxQueues and MaxNumberOfTxQueues values because clients typically create a matching number of Rx and Tx queues.

If a provider can partition Rx or Tx queues flexibly between virtual ports then is can use NDIS_PD_QUEUE_COUNT_DYNAMIC for the virtual port specific max counts.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)