# _D3DHAL_CONTEXTDESTROYDATA structure

## Description

The D3DHAL_CONTEXTDESTROYDATA structure contains the information that the [D3dContextDestroy](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_contextdestroycb) function requires to delete a context.

## Members

### `dwhContext`

Specifies the handle to the context to be destroyed.

### `ddrval`

Specifies the location where the driver writes the return code for [D3dContextDestroy](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_contextdestroycb). D3D_OK indicates success. For more information, see [Return Codes for Direct3D Driver Callbacks](https://learn.microsoft.com/windows-hardware/drivers/display/return-codes-for-direct3d-driver-callbacks).

## See also

[D3dContextDestroy](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_contextdestroycb)