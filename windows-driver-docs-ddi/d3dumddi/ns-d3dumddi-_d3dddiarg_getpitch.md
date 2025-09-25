# _D3DDDIARG_GETPITCH structure

## Description

The D3DDDIARG_GETPITCH structure describes an encrypted surface for which the [GetPitch](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getpitch) function retrieves the pitch.

## Members

### `hCryptoSession` [in]

A handle to the encryption session.

### `hResource` [in]

A handle to the resource.

### `SubResourceIndex` [in]

The zero-based index into the resource, which the **hResource** handle specifies. This index indicates the encrypted surface.

### `Pitch` [out]

The pitch, in bytes, of the encrypted surface. The user-mode display driver's [GetPitch](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getpitch) function returns this pitch value to the Direct3D runtime.

## See also

[GetPitch](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getpitch)