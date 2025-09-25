# _DXVAHDDDI_STREAM_DATA structure

## Description

The DXVAHDDDI_STREAM_DATA structure describes an input stream that is processed.

## Members

### `Enable` [in]

A Boolean value that specifies whether the input stream is enabled. The number of input streams that the runtime enables must not be more than the number, which the driver sets in the **MaxStreamStates** member of the [DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps) structure.

### `OutputIndex` [in]

A zero-based cyclic frame index number of the output frames that are composed.

### `InputFrameOrField` [in]

A zero-based frame number of the input frames or fields that are processed.

### `PastFrames` [in]

The number of past reference frames. This number must not be more than the number that the driver sets in the **PastFrames** member of the [DXVAHDDDI_VPCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpcaps) structure.

### `FutureFrames` [in]

The number of future reference frames. This number must not be more than the number that the driver sets in the **FutureFrames** member of the [DXVAHDDDI_VPCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpcaps) structure.

### `pPastSurfaces` [in]

An array of [DXVAHDDDI_SURFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_surface) structures that describe the past reference surfaces.

### `InputSurface` [in]

A [DXVAHDDDI_SURFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_surface) structure that describes the input surface.

### `pFutureSurfaces` [in]

An array of [DXVAHDDDI_SURFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_surface) structures that describe the future reference surfaces.

## Remarks

The driver must allocate the surfaces that the **pPastSurfaces**, **InputSurface**, and **pFutureSurfaces** members specify in the pool type, which the driver sets in the **InputPool** member of the [DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps) structure, and with one of the following surface types; otherwise, the driver's [VideoProcessBltHD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_videoprocessblthd) function returns an error.

* A video surface that is created with the DXVAHD_SURFACE_TYPE_VIDEO_INPUT or DXVAHD_SURFACE_TYPE_VIDEO_INPUT_PRIVATE type.
* A decode render target surface that is created with the DXVA2_VideoDecodeRenderTarget type.
* An off-screen plain surface.

The **OutputIndex** member is a zero-based cyclic number that indicates the frame index number of the output. The driver uses this output-index information to perform the video processing in a certain pattern or cycle, especially when the driver performs deinterlacing, frame-rate conversion, and inverse telecine. For example, with the following output-index pattern, the driver performs the indicated video processing:

* Progressive format at normal and half rate:

  OutputIndex = 0, 0,...
* Progressive format at 2/1 custom rate (double frame-rate conversion, OutputFrames=2):

  OutputIndex = 0, 1, 0, 1,...
* Interlaced format at normal rate:

  OutputIndex = 0, 1, 0, 1,... (0: first field, 1: second field)
* Interlaced format at half rate:

  OutputIndex = 0, 0,... (for example, first and second fields are blended to one frame)
* Interlaced at 4/5 custom rate (3:2 inverse telecine, OutputFrames=4):

  OutputIndex = 0, 1, 2, 3, 0, 1, 2, 3,... (0:A, 1:B, 2:C, 3:D film frame)

The **InputFrameOrField** member is a zero-based number that indicates the frame or the field number of the input surface. For example, with the following input-frame-or-field number, the driver can perform the indicated video processing:

* Progressive format and interlaced format at normal rate:

  InputFrameOrField = 0, 1, 2,...
* Progressive format and interlaced format at half rate:

  InputFrameOrField = 0, 2, 4,...
* Interlaced format at 4/5 custom rate (3:2 inverse telecine, OutputFrames=4 and InputFrameOrField=10):

  InputFrameOrField = 0, 0, 0, 0, 10, 10, 10, 10, 20, 20, 20, 20,...
* Interlaced format at 4/15 custom rate (8:7 inverse telecine, OutputFrames=2 and InputFrameOrField=15):

  InputFrameOrField = 0, 0, 15, 15, 30, 30,...

The application should cause both the **OutputIndex** and **InputFrameOrField** members to reset when either the frame format or the output rate is changed so that the driver can reset its internal processing state. For more information about changing frame format or output rate, see [DXVAHDDDI_STREAM_STATE_FRAME_FORMAT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_frame_format_data) and [DXVAHDDDI_STREAM_STATE_OUTPUT_RATE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_output_rate_data).

However, if the driver switches between normal and half rate (values from the [DXVAHDDDI_OUTPUT_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_output_rate) enumeration), the driver should not require the reset.

If both the **OutputIndex** and **InputFrameOrField** members remain unchanged at the next process time, the driver determines that the frame is unchanged (for example, paused) in the stream processing. Therefore, the driver can optimize the frame by using cached data.

The driver should fallback to a less intensive video processing method as less reference frames are provided. The driver should fallback to Bob de-interlacing when no reference samples are provided.

An application can provide less past and future reference frames than the reference frames that the driver requests. For example, an application can provide less reference frames in the following conditions:

* At the beginning or at the end of the frame sequence.
* Transition between progressive and interlaced.
* Normal or half rate progressive stream.
* Sub-video streams that do not require high quality de-interlacing.
* While throttling the reference frames to recover from frame drops and to keep up the frame rate.
* Frame dropping from the input (for example, frame drops in the decoder).

Both the past and the future reference frames are provided in the **pPastSurfaces** and **pFutureSurfaces** array members in temporal order from older to newer frames continuously. For example, the order of the elements in the arrays are as shown in the following example:

**pPastSurfaces** [] = {..., T-3, T-2, T-1}

**InputSurface** = T

**pFutureSurfaces** [] = {T+1, T+2, T+3,...}

The input and reference frames change location from the future location to the past location through the current location as the **OutputIndex** and **InputFrameOrField** members increment. For example, the input surface changes as the **OutputIndex** and **InputFrameOrField** increment when the driver performs the following video processing:

* Progressive format at normal rate:

  OutputIndex = 0, 0, 0,...

  InputFrameOrField = 0, 1, 2,...

  InputSurface = T, T+1, T+2,...
* Interlaced format at normal rate:

  OutputIndex = 0, 1, 0, 1, 0, 1,...

  InputFrameOrField = 0, 1, 2, 3, 4, 5,...

  InputSurface = T, T, T+1, T+1, T+2, T+2,...
* Interlaced format at half rate:

  OutputIndex = 0, 0, 0,...

  InputFrameOrField = 0, 2, 4,...

  InputSurface = T, T+1, T+2,...
* Interlaced format at 4/5 custom rate (3:2 inverse telecine, OutputFrames=4 and InputFrameOrField=10):

  OutputIndex = 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3,...

  InputFrameOrField = 0, 0, 0, 0, 10, 10, 10, 10, 20, 20, 20, 20,...

  InputSurface = T, T, T, T, T+5, T+5, T+5, T+5, T+10, T+10, T+10, T+10,...
* Interlaced format at 4/15 custom rate (8:7 inverse telecine, OutputFrames=2 and InputFrameOrField=15):

  OutputIndex = 0, 1, 0, 1, 0, 1,...

  InputFrameOrField = 0, 0, 15, 15, 30, 30,...

  InputSurface = T, T, T+7, T+7, T+15, T+15,... (note that T+7 frame contains 15th field)

The following pseudo-code example shows the interaction between the application (APP) and the driver (DRV) while performing Inverse Telecine (IVTC) on 3:2 pull-down, 30 frames (60 fields) per second interlaced content:

```cpp
-[60i -> 60p]
DRV: VPGuid[0] requests 1 past and 2 future reference frames.
APP: Creates VPGuid[0] video processor and set output rate to normal.
APP: Decodes frame 0(A0:A1), 1(A0:B1), 2(B0:C1), 3(C0:C1), 4(D0:D1), ...
    :
-APP: VPBltHD(frame x, 0, 1, 2), InputFrameOrField=0, OutputIndex=0
DRV: Bob [0(A0)+0(A1)] = A'
-APP: VPBltHD(frame x, 0, 1, 2), InputFrameOrField=1, OutputIndex=1
DRV: Weave [0(A1)+1(A0)] = A
-APP: VPBltHD(frame 0, 1, 2, 3), InputFrameOrField=2, OutputIndex=0
DRV: Weave [1(A0)+0(A1)] = A
-APP: VPBltHD(frame 0, 1, 2, 3), InputFrameOrField=3, OutputIndex=1
DRV: Weave [1(B1)+2(B0)] = B
-APP: VPBltHD(frame 1, 2, 3, 4), InputFrameOrField=4, OutputIndex=0
DRV: Weave [2(B0)+1(B1)] = B
-APP: VPBltHD(frame 1, 2, 3, 4), InputFrameOrField=5, OutputIndex=1
DRV: Weave [2(C1)+3(C0)] = C
-APP: VPBltHD(frame 2, 3, 4, 5), InputFrameOrField=6, OutputIndex=0
DRV: Weave [3(C0)+3(C1)] = C
-APP: VPBltHD(frame 2, 3, 4, 5), InputFrameOrField=7, OutputIndex=1
DRV: Weave [3(C1)+3(C0)] = C
-APP: VPBltHD(frame 3, 4, 5, 6), InputFrameOrField=8, OutputIndex=0
DRV: Weave [4(D0)+4(D1)] = D
-APP: VPBltHD(frame 3, 4, 5, 6), InputFrameOrField=9, OutputIndex=1
DRV: Weave [4(D1)+4(D0)] = D
    :
-[60i -> 24p]
DRV: VPGuid[1] requests 4 future reference frames.
DRV: Exports CustomRate=4/5, OutputFrames=4, InputInterlaced=TRUE, InputFramesOrFields=10.
APP: Creates VPGuid[1] video processor and set output rate to 4/5 custom rate.
-APP: VPBltHD(frame 0, 1, 2, 3, 4), InputFrameOrField=0, OutputIndex=0
DRV: Bob [0(A0)+0(A1)] = A' (playback or speed mode) or Weave [0(A0)+0(A1)] = A (quality mode)
-APP: VPBltHD(frame 0, 1, 2, 3, 4), InputFrameOrField=0, OutputIndex=1
DRV: Weave [1(B1)+2(B0)] = B
-APP: VPBltHD(frame 0, 1, 2, 3, 4), InputFrameOrField=0, OutputIndex=2
DRV: Weave [3(C0)+3(C1)] = C
-APP: VPBltHD(frame 0, 1, 2, 3, 4), InputFrameOrField=0, OutputIndex=3
DRV: Weave [4(D0)+4(D1)] = D
-APP: VPBltHD(frame 5, 6, 7, 8, 9), InputFrameOrField=10, OutputIndex=0
DRV: Weave [0(A0)+0(A1)] = A
    :
```

## See also

[DXVAHDDDI_OUTPUT_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_output_rate)

[DXVAHDDDI_STREAM_STATE_FRAME_FORMAT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_frame_format_data)

[DXVAHDDDI_STREAM_STATE_OUTPUT_RATE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_output_rate_data)

[DXVAHDDDI_SURFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_surface)

[DXVAHDDDI_VPCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpcaps)

[DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps)

[VideoProcessBltHD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_videoprocessblthd)