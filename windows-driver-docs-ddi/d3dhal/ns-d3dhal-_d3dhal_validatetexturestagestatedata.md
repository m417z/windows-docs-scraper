# _D3DHAL_VALIDATETEXTURESTAGESTATEDATA structure

## Description

The D3DHAL_VALIDATETEXTURESTAGESTATEDATA structure contains the information required for the driver to determine and return its ability to support multitexturing using the current state.

## Members

### `dwhContext`

Specifies the context ID of the Direct3D device.

### `dwFlags`

Currently set to zero and should be ignored by the driver.

### `dwReserved`

Reserved for system use and should be ignored by the driver.

### `dwNumPasses`

Specifies the location where the driver should write the number of passes required by the hardware to perform the blending operations.

### `ddrval`

Specifies the location where the driver writes the return value of the [D3dValidateTextureStageState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_validatetexturestagestatecb) function. A return code of D3D_OK indicates success. For more information, see [Return Codes for Direct3D Driver Callbacks](https://learn.microsoft.com/windows-hardware/drivers/display/return-codes-for-direct3d-driver-callbacks).

## See also

[D3dValidateTextureStageState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_validatetexturestagestatecb)