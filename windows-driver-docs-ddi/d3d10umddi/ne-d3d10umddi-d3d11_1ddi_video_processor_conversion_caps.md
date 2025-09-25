# D3D11_1DDI_VIDEO_PROCESSOR_CONVERSION_CAPS enumeration

## Description

Specifies video processor-specific capabilities.

## Constants

### `D3D11_1DDI_VIDEO_PROCESSOR_CONVERSION_CAPS_DEINTERLACE_BLEND`

The driver can perform blend deinterlacing where the two fields in an interlaced frame are blended. The driver uses this deinterlacing type when it deinterlaces at half rate. For more information about half rate, see [DXVAHDDDI_OUTPUT_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_output_rate).

### `D3D11_1DDI_VIDEO_PROCESSOR_CONVERSION_CAPS_DEINTERLACE_BOB`

The driver can perform Bob deinterlacing where missing scan lines are created from the lines above and below the missing line. The 4tap filter ([-1,9,9,-1]/16) produces slightly better results. The driver uses this deinterlacing type when not enough reference frames are provided for adaptive deinterlacing.

### `D3D11_1DDI_VIDEO_PROCESSOR_CONVERSION_CAPS_DEINTERLACE_ADAPTIVE`

The driver can perform adaptive deinterlacing where missing scan lines are created from either spatial or temporal interpolation by switching between the two interpolation types, depending on the pixel or field motion.

### `D3D11_1DDI_VIDEO_PROCESSOR_CONVERSION_CAPS_DEINTERLACE_MOTION_COMPENSATION`

The driver can perform motion-compensated deinterlacing where missing scan lines are created by using the motion vectors. This deinterlacing type is the most advanced deinterlacing that is implemented by using a proprietary algorithm.

### `D3D11_1DDI_VIDEO_PROCESSOR_CONVERSION_CAPS_INVERSE_TELECINE`

The driver can convert from the interlaced frames to original progressive frames by reversing the telecine. For more information about reversing the telecine, see the **ITelecineCaps** member of the [D3D11_1DDI_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_rate_conversion_caps) structure.

### `D3D11_1DDI_VIDEO_PROCESSOR_CONVERSION_CAPS_FRAME_RATE_CONVERSION`

The driver can convert the frame rate by interpolating the frames.

## See also

[D3D11_1DDI_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_video_processor_rate_conversion_caps)

[DXVAHDDDI_OUTPUT_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_output_rate)