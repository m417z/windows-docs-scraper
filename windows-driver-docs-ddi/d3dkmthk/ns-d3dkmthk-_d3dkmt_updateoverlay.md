# _D3DKMT_UPDATEOVERLAY structure

## Description

The D3DKMT_UPDATEOVERLAY structure describes parameters for modifying an overlay.

## Members

### `hDevice` [in]

A D3DKMT_HANDLE data type that represents the kernel-mode handle to the device that the overlay is associated with.

### `hOverlay` [in]

A D3DKMT_HANDLE data type that represents the kernel-mode handle that is returned by the create-overlay function and that identifies the kernel-mode overlay object to modify.

### `OverlayInfo` [in]

A [D3DDDI_KERNELOVERLAYINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_kerneloverlayinfo) structure that describes modification information for the kernel-mode overlay object.

## See also

[D3DDDI_KERNELOVERLAYINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_kerneloverlayinfo)

[D3DKMTUpdateOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtupdateoverlay)