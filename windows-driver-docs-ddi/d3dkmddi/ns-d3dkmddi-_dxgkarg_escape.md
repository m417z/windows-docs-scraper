# DXGKARG_ESCAPE structure

## Description

The **DXGKARG_ESCAPE** structure describes information that the user-mode display driver (UMD) shares with the display miniport driver (KMD).

## Members

### `hDevice` [in]

A handle to the display device (graphics context) that was originally passed to KMD's [**DxgkDdiCreateDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice) function.

### `Flags` [in]

A [**D3DDDI_ESCAPEFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_escapeflags) structure that indicates, in bit-field flags, how to share information.

### `pPrivateDriverData` [in/out]

A pointer to a buffer that contains the information that the display miniport driver and the user-mode display driver share.

### `PrivateDriverDataSize` [in/out]

The size, in bytes, of the buffer that **pPrivateDriverData** points to.

### `hContext` [in]

A handle to the context that was originally passed to KMD's [**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext) function.

### `hKmdProcessHandle` [in]

A driver handle that is returned by the KMD from the call to [**DxgkDdiCreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess). The driver must check the handle for NULL. The handle is created when the first DXG device is created for a process. The handle is destroyed when the last adapter handle is closed for a process.

## See also

[**D3DDDI_ESCAPEFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_escapeflags)

[**DxgkDdiCreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess)

[**DxgkDdiCreateDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice)

[**DxgkDdiEscape**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_escape)