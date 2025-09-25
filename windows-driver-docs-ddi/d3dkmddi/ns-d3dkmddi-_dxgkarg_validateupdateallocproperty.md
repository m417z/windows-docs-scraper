# DXGKARG_VALIDATEUPDATEALLOCPROPERTY structure

## Description

The **DXGKARG_VALIDATEUPDATEALLOCPROPERTY** structure holds the information needed to validate the parameters to update the properties of an allocation.

## Members

### `hAllocation` [in]

A handle to the allocation that will be updated.

### `SupportedSegmentSet` [in]

An index for the new supported segment set. If the current supported segment set is the same, then this will be ignored.

### `PreferredSegment` [in]

An index for the new preferred segment set. If the current preferred segment set is the same, then this will be ignored.

### `Flags` [in]

A [**D3DDDI_UPDATEALLOCPROPERTY_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_updateallocproperty_flags) structure with flags that specify how to update the allocation's properties.

### `SetAccessedPhysically`

A UINT value that specifies whether the allocation is accessed by its physical address.

### `SetSupportedSegmentSet`

A UINT value that specifies whether the supported segment is set to a new value.

### `SetPreferredSegment`

A UINT value that specifies whether the preferred segment is set to a new value.

### `Reserved`

This member is reserved and should be set to zero.

### `PropertyMaskValue`

An alternative way to access the property mask values.

## See also

[**DXGKDDI_VALIDATEUPDATEALLOCATIONPROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_validateupdateallocationproperty)