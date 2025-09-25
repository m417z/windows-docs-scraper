# DXVAHD_STREAM_DATA structure

## Description

Contains per-stream data for the [IDXVAHD_VideoProcessor::VideoProcessBltHD](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-videoprocessblthd) method.

## Members

### `Enable`

Specifies whether this input stream is enabled. If the value is **TRUE**, the [VideoProcessBltHD](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-videoprocessblthd) method blits this stream to the output surface. Otherwise, the stream is not blitted. The maximum number of streams that can be enabled at one time is given in the **MaxInputStreams** member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure.

### `OutputIndex`

The zero-based index number of the output frame. See Remarks.

### `InputFrameOrField`

The zero-based index number of the input frame or field. See Remarks.

### `PastFrames`

The number of past reference frames. This value must be less than or equal to the value of the **PastFrames** member of the [DXVAHD_VPCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpcaps) structure.

### `FutureFrames`

The number of future reference frames. This value must be less than or equal to the value of the **FutureFrames** member of the [DXVAHD_VPCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpcaps) structure.

### `ppPastSurfaces`

A pointer to an array of [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) pointers, allocated by the caller. This array contains the past reference frames for the video processing operation. The number of elements in the array is equal to the value of the **PastFrames** member.

### `pInputSurface`

A pointer to the [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface of a Microsoft Direct3D surface that contains the current input frame.

### `ppFutureSurfaces`

A pointer to an array of [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) pointers, allocated by the caller. This array contains the future reference frames for the video processing operation. The number of elements in the array is equal to the value of the **FutureFrames** member.

## Remarks

### Input Surfaces

The Direct3D surfaces must be allocated in the memory pool specified by the **InputPool** member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure. The following surface types can be used:

* A video surface of type **DXVAHD_SURFACE_TYPE_VIDEO_INPUT** or **DXVAHD_SURFACE_TYPE_VIDEO_INPUT_PRIVATE**. See [IDXVAHD_Device::CreateVideoSurface](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-createvideosurface).
* A decoder render-target surface of type **DXVA2_VideoDecoderRenderTarget**. See [IDirectXVideoAccelerationService::CreateSurface](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoaccelerationservice-createsurface).
* An off-screen plain surface.

The past and future reference frames must be placed in the arrays in temporal order, from oldest to newest. For example, if *T* is the current input frame, the arrays would be ordered as follows:

* **ppPastSurfaces**: { …, *T*-3, *T*-2, *T*-1 }
* **ppInputSurface**: *T*
* **ppFutureSurfaces**: { *T*+1, *T*+2, *T*+3, … }

The [DXVAHD_VPCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpcaps) structure specifies the number of reference frames required to get the best deinterlacing quality. If the application provides fewer reference frames, the device will fall back to simpler deinterlacing algorithms. If no reference frames are provided, the device can use bob deinterlacing. Here are some cases where an application might provide fewer reference frames:

* At the beginning or end of the video sequence
* With progressive input
* During a transition between progressive and interlaced input
* For a substream that does not require high deinterlacing quality
* While dropping frames

### Input and Output Indexes

The **OutputIndex** and **InputFrameOrField** members are used to correlate input frames or fields with output frames. The value of the **OutputIndex** member is cyclic and resets to zero after each cycle.

Here are some example patterns:

* Progressive video at normal rate. Each input frame produces one output frame.
  + Output index: 0, 0, 0, 0, …
  + Input index: 0, 1, 2, 3, …
* Interlaced video at normal rate. Each interlaced frame (two fields) produces two output frames.
  + Output index: 0, 1, 0, 1, …
  + Input index: 0, 1, 2, 3, …
* Progressive video at 2/1 output rate. Each input frame produces one output frame.
  + Output index: 0, 1, 0, 1, …
  + Input index: 0, 1, 2, 3, …
* Interlaced video at 1/2 output rate. Each interlaced frame produces one output frame. (The two fields are blended to create one frame.)
  + Output index: 0, 0, 0, 0, …
  + Input index: 0, 2, 4, 6, …

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)