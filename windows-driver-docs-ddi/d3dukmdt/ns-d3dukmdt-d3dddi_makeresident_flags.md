# D3DDDI_MAKERESIDENT_FLAGS structure

## Description

**D3DDDI_MAKERESIDENT_FLAGS** is used with **MakeResident** ([pfnMakeResidentCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_makeresidentcb) or [D3DKMTMakeResident](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtmakeresident)) to instruct the OS to add a resource to the device residency list and increment the residency reference count on this allocation.

## Members

### `CantTrimFurther`

This flag should be used after the user mode driver has trimmed all other possible resources in the device and require the current resource to be made resident in order to make forward progress on a particular single atomic operation.

### `MustSucceed`

This flag may only be set if **CantTrimFurther** is also set. It indicates that the resource being made resident is critical to the device forward progress. If the video memory manager can’t satisfy the request the device will be put in error.

### `Reserved`

This member is reserved and should be set to zero.

### `Value`

The consolidated value of the structure.

## See also

[D3DKMTMakeResident](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtmakeresident)

[pfnMakeResidentCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_makeresidentcb)