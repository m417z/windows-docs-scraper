# DDHAL_DESTROYDDLOCALDATA structure

## Description

DDHAL_DESTROYDDLOCALDATA contains the information required for the driver to destroy a set of surfaces associated to a given local DirectDraw object.

## Members

### `dwFlags`

Unused.

### `pDDLcl`

Points to the local Direct Draw object that serves as a reference for all Direct3D surfaces that have to be destroyed.

### `ddRVal`

Specifies the location where the driver writes the return value of [D3dDestroyDDLocal](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_destroyddlocal). A return code of D3D_OK indicates success. For more information, see [Return Codes for Direct3D Driver Callbacks](https://learn.microsoft.com/windows-hardware/drivers/display/return-codes-for-direct3d-driver-callbacks).

## See also

[D3dDestroyDDLocal](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_destroyddlocal)