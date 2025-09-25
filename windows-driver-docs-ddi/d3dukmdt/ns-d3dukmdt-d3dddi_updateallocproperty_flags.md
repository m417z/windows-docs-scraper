# D3DDDI_UPDATEALLOCPROPERTY_FLAGS structure

## Description

The **D3DDDI_UPDATEALLOCPROPERTY_FLAGS** structure identifies how to update a property in an allocation.

## Members

### `AccessedPhysically`

When set, indicates that the allocation is accessed by its physical address.

### `Unmoveable`

When set, indicates that the allocation can't be moved while pinned in a memory segment.

### `Reserved`

This member is reserved and should be set to zero.

### `Value`

A member in the union that is contained in D3DDDI_UPDATEALLOC_PROPERTY_FLAGS that can hold one 32-bit value that identifies how to unlock a resource.

## See also

[**D3DDDI_UPDATEALLOCPROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_updateallocproperty)