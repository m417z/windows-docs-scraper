# _D3DKMT_CREATEOVERLAY structure

## Description

The D3DKMT_CREATEOVERLAY structure describes overlay hardware.

## Members

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology on which to overlay (that is, the identifier of the primary surface on which to overlay).

### `hDevice` [in]

A handle to the device that the overlay is associated with.

### `OverlayInfo` [in]

A [D3DDDI_KERNELOVERLAYINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_kerneloverlayinfo) structure that describes information about the kernel-mode overlay object.

### `hOverlay` [out]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the kernel-mode overlay object, which represents the overlay hardware in subsequent calls by the OpenGl ICD.

## See also

[D3DDDI_KERNELOVERLAYINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_kerneloverlayinfo)

[D3DKMTCreateOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateoverlay)