# KsFilterCreateNode function

## Description

The **KsFilterCreateNode** function creates a new topology node on the specified filter.

## Parameters

### `Filter` [in]

A pointer to a [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure on which to create a new topology node.

### `NodeDescriptor` [in]

A pointer to a [KSNODE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksnode_descriptor) structure that describes the new node.

### `NodeID` [out]

A pointer to a ULONG where AVStream places the ID of the new node.

## Return value

**KsFilterCreateNode** returns the success or failure of creating the node. The call may fail because of invalid parameters, low memory, or other reasons.

## Remarks

Note that the filter control mutex must be held before calling this function. For more information, see [Filter Control Mutex in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-control-mutex-in-avstream).

## See also

[KsFilterCreatePinFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltercreatepinfactory)