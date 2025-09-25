# DXVAHD_PROCESSOR_CAPS enumeration

## Description

Specifies the processing capabilities of a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) video processor.

## Constants

### `DXVAHD_PROCESSOR_CAPS_DEINTERLACE_BLEND:0x1`

The video processor can perform blend deinterlacing.

 In *blend deinterlacing*, the two fields from an interlaced frame are blended into a single progressive frame. A video processor uses blend deinterlacing when it deinterlaces at half rate, as when converting 60i to 30p. Blend deinterlacing does not require reference frames.

### `DXVAHD_PROCESSOR_CAPS_DEINTERLACE_BOB:0x2`

The video processor can perform bob deinterlacing.

In *bob deinterlacing*, missing field lines are interpolated from the lines above and below. Bob deinterlacing does not require reference frames.

### `DXVAHD_PROCESSOR_CAPS_DEINTERLACE_ADAPTIVE:0x4`

The video processor can perform adaptive deinterlacing.

*Adaptive deinterlacing* uses spatial or temporal interpolation, and switches between the two on a field-by-field basis, depending on the amount of motion. If the video processor does not receive enough reference frames to perform adaptive deinterlacing, it falls back to bob deinterlacing.

### `DXVAHD_PROCESSOR_CAPS_DEINTERLACE_MOTION_COMPENSATION:0x8`

The video processor can perform motion-compensated deinterlacing.

*Motion-compensated deinterlacing* uses motion vectors to recreate missing lines. If the video processor does not receive enough reference frames to perform motion-compensated deinterlacing, it falls back to bob deinterlacing.

### `DXVAHD_PROCESSOR_CAPS_INVERSE_TELECINE:0x10`

The video processor can perform inverse telecine (IVTC).

 If the video processor supports this capability, the **ITelecineCaps** member of the [DXVAHD_VPCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpcaps) structure specifies which IVTC modes are supported.

### `DXVAHD_PROCESSOR_CAPS_FRAME_RATE_CONVERSION:0x20`

The video processor can convert the frame rate by interpolating frames.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[Direct3D Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-enumerations)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)