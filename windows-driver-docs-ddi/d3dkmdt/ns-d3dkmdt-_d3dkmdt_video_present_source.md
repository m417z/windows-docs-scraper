# _D3DKMDT_VIDEO_PRESENT_SOURCE structure

## Description

The D3DKMDT_VIDEO_PRESENT_SOURCE structure contains the unique identifier of a video present source.

## Members

### `Id`

The identifier of a video present source.

### `dwReserved`

Reserved for future use.

## Remarks

The D3DDDI_VIDEO_PRESENT_SOURCE_ID data type is defined in *D3dukmdt.h*.

Video present source identifiers are assigned by the operating system. [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device), implemented by the display miniport driver, returns the number N of video present sources supported by the display adapter. Then the operating system assigns identifiers 0, 1, 2, ... NÂ -Â 1.

For more information about video present sources, see [Introduction to Video Present Networks](https://learn.microsoft.com/windows-hardware/drivers/display/introduction-to-video-present-networks).

## See also

[D3DKMDT_VIDEO_PRESENT_TARGET](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_video_present_target)

[D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path)

[DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)