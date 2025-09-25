# _D3DKMT_SETDISPLAYMODE structure

## Description

The D3DKMT_SETDISPLAYMODE structure describes the primary allocation that is used for scanning out to the display.

## Members

### `hDevice` [in]

A handle to the device that requests setting of the display mode.

### `hPrimaryAllocation` [in]

A D3DKMT_HANDLE data type that represents the kernel-mode handle to the primary allocation for scanning out.

### `ScanLineOrdering` [in]

A [D3DDDI_VIDEO_SIGNAL_SCANLINE_ORDERING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_video_signal_scanline_ordering)-typed value that indicates how scan lines are ordered in the display mode.

### `DisplayOrientation` [in]

A [D3DDDI_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_rotation)-typed value that identifies the orientation of the display mode.

### `PrivateDriverFormatAttribute` [out]

A UINT value that specifies a private format attribute that the OpenGL installable client driver (ICD) should use to convert the current primary surface if a call to the [D3DKMTSetDisplayMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetdisplaymode) function failed with STATUS_GRAPHICS_INCOMPATIBLE_PRIVATE_FORMAT.

### `Flags` [in]

Supported in Windows 7 and later versions.

A [D3DKMT_SETDISPLAYMODE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setdisplaymode_flags) structure that specifies, in bit-field flags, attributes for setting the display mode.

## See also

[D3DDDI_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_rotation)

[D3DDDI_VIDEO_SIGNAL_SCANLINE_ORDERING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_video_signal_scanline_ordering)

[D3DKMTSetDisplayMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetdisplaymode)

[D3DKMT_SETDISPLAYMODE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setdisplaymode_flags)