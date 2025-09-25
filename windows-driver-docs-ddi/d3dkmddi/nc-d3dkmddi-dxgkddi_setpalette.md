# DXGKDDI_SETPALETTE callback function

## Description

The *DxgkDdiSetPalette* function programs the color registers for palettized 8 bits-per-pixel (bpp) modes.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pSetPalette` [in]

A pointer to a [DXGKARG_SETPALETTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkarg_setpalette) structure that describes the palette to set for the display.

## Return value

*DxgkDdiSetPalette* returns STATUS_SUCCESS, or an appropriate error result if the display palette is not successfully set.

## Remarks

Implementation of the *DxgkDdiSetPalette* function in the Windows Vista display driver model replaces [IOCTL_VIDEO_SET_COLOR_REGISTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_video_set_color_registers) functionality in the Windows 2000 display driver model.

*DxgkDdiSetPalette* should be made pageable.

## See also

[D3DKMDT_PALETTEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_palettedata)

[DXGKARG_SETPALETTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkarg_setpalette)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)