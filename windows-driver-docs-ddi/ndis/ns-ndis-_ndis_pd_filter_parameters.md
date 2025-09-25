# _NDIS_PD_FILTER_PARAMETERS structure

## Description

This structure holds metadata for a packet filter.

## Members

### `Header`

The [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the **NDIS_PD_FILTER_PARAMETERS** structure. Set the members of this structure as follows:

* **Type** = **NDIS_OBJECT_TYPE_DEFAULT**
* **Revision** = **NDIS_PD_FILTER_PARAMETERS_REVISION_1**
* **Size** = **NDIS_SIZEOF_PD_FILTER_PARAMETERS_REVISION_1**

### `Flags`

This member is reserved and must be set to 0 by the client. It is ignored by the provider.

### `MatchProfileId`

This value is used to determine if the HeaderGroupMatchArray members describe an NDIS_GFP_HEADER_GROUP_EXACT_MATCH array or a NDIS_GFP_HEADER_GROUP_WILDCARD_MATCH array.

### `Priority`

The priority of this filter.

### `CounterHandle`

A handle to a counter.

### `TargetReceiveQueue`

The target receive queue to filter.

### `RxFilterContext`

The context for the receive filter.

### `HeaderGroupMatchArray`

An array of either NDIS_GFP_HEADER_GROUP_EXACT_MATCH or NDIS_GFP_HEADER_GROUP_WILDCARD_MATCH elements as determined by the MatchProfileId member.

### `HeaderGroupMatchArrayNumElements`

The number of elements for the HeaderGroupMatchArray.

### `HeaderGroupMatchArrayElementSize`

The size of each element for the HeaderGroupMatchArray.

### `HeaderGroupMatchArrayTotalSize`

The total size of the HeaderGroupMatchArray.

## Remarks

This structure must be aligned on an 8-byte boundary.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)