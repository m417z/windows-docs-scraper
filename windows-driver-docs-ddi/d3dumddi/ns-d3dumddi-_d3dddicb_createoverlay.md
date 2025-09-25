# _D3DDDICB_CREATEOVERLAY structure

## Description

The D3DDDICB_CREATEOVERLAY structure describes overlay hardware.

## Members

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology to overlay on (that is, the identifier of the primary surface to overlay on).

### `OverlayInfo` [in]

A [D3DDDI_KERNELOVERLAYINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_kerneloverlayinfo) structure that describes information about the kernel-mode overlay object.

### `hKernelOverlay` [out]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the kernel-mode overlay object. This overlay object represents the overlay hardware in subsequent calls by the user-mode display driver to the Microsoft Direct3D runtime.

## See also

[D3DDDI_KERNELOVERLAYINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_kerneloverlayinfo)

[pfnCreateOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createoverlaycb)