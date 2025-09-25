## Description

The **DXGKDDI_VALIDATEUPDATEALLOCATIONPROPERTY** function validates the update of an allocation property.

## Parameters

### `hAdapter`

[in] Handle to the display adapter that is associated with the allocation.

### `pValidateUpdateAllocProperty`

[in] A pointer to a [**DXGKARG_VALIDATEUPDATEALLOCATIONPROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_validateupdateallocproperty) structure that describes the allocation property to be validated for update.

## Return value

**DXGKDDI_VALIDATEUPDATEALLOCATIONPROPERTY** returns STATUS_SUCCESS if the allocation property can be updated; otherwise, it returns an appropriate error code.

## See also

[**DXGKARG_VALIDATEUPDATEALLOCATIONPROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_validateupdateallocproperty)