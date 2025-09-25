# DXVA2_VideoProcessorCaps structure

## Description

Describes the capabilities of a DirectX Video Acceleration (DVXA) video processor mode.

## Members

### `DeviceCaps`

Identifies the type of device. The following values are defined.

| Value | Meaning |
| --- | --- |
| **DXVA2_VPDev_EmulatedDXVA1** | DXVA 2.0 video processing is emulated by using DXVA 1.0. An emulated device may be missing significant processing capabilities and have lower image quality and performance. |
| **DXVA2_VPDev_HardwareDevice** | Hardware device. |
| **DXVA2_VPDev_SoftwareDevice** | Software device. |

### `InputPool`

The Direct3D memory pool used by the device.

### `NumForwardRefSamples`

Number of forward reference samples the device needs to perform deinterlacing. For the bob, progressive scan, and software devices, the value is zero.

### `NumBackwardRefSamples`

Number of backward reference samples the device needs to perform deinterlacing. For the bob, progressive scan, and software devices, the value is zero.

### `Reserved`

Reserved. Must be zero.

### `DeinterlaceTechnology`

Identifies the deinterlacing technique used by the device. This value is a bitwise **OR** of one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **DXVA2_DeinterlaceTech_Unknown** | The algorithm is unknown or proprietary. |
| **DXVA2_DeinterlaceTech_BOBLineReplicate** | The algorithm creates missing lines by repeating the line either above or below the missing line. This algorithm produces a jagged image and is not recommended. |
| **DXVA2_DeinterlaceTech_BOBVerticalStretch** | The algorithm creates missing lines by averaging two lines. Slight vertical adjustments are made so that the resulting image does not bob up and down. |
| **DXVA2_DeinterlaceTech_BOBVerticalStretch4Tap** | The algorithm creates missing lines by applying a [−1, 9, 9, −1]/16 filter across four lines. Slight vertical adjustments are made so that the resulting image does not bob up and down. |
| **DXVA2_DeinterlaceTech_MedianFiltering** | The algorithm uses median filtering to recreate the pixels in the missing lines. |
| **DXVA2_DeinterlaceTech_EdgeFiltering** | The algorithm uses an edge filter to create the missing lines. In this process, spatial directional filters are applied to determine the orientation of edges in the picture content. Missing pixels are created by filtering along (rather than across) the detected edges. |
| **DXVA2_DeinterlaceTech_FieldAdaptive** | The algorithm uses spatial or temporal interpolation, switching between the two on a field-by-field basis, depending on the amount of motion. |
| **DXVA2_DeinterlaceTech_PixelAdaptive** | The algorithm uses spatial or temporal interpolation, switching between the two on a pixel-by-pixel basis, depending on the amount of motion. |
| **DXVA2_DeinterlaceTech_MotionVectorSteered** | The algorithm identifies objects within a sequence of video fields. Before it recreates the missing pixels, it aligns the movement axes of the individual objects in the scene to make them parallel with the time axis. |
| **DXVA2_DeinterlaceTech_InverseTelecine** | The device can undo the 3:2 pulldown process used in telecine. |

### `ProcAmpControlCaps`

Specifies the available video processor (ProcAmp) operations. The value is a bitwise OR of [ProcAmp Settings](https://learn.microsoft.com/windows/desktop/medfound/procamp-settings) constants.

### `VideoProcessorOperations`

Specifies operations that the device can perform concurrently with the [IDirectXVideoProcessor::VideoProcessBlt](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoprocessor-videoprocessblt) operation. The value is a bitwise **OR** of the following flags.

| Value | Meaning |
| --- | --- |
| **DXVA2_VideoProcess_YUV2RGB** | The device can convert the video from YUV color space to RGB color space, with at least 8 bits of precision for each RGB component. |
| **DXVA2_VideoProcess_StretchX** | The device can stretch or shrink the video horizontally. If this capability is present, aspect ratio correction can be performed at the same time as deinterlacing. |
| **DXVA2_VideoProcess_StretchY** | The device can stretch or shrink the video vertically. If this capability is present, image resizing and aspect ratio correction can be performed at the same time. |
| **DXVA2_VideoProcess_AlphaBlend** | The device can alpha blend the video. |
| **DXVA2_VideoProcess_SubRects** | The device can operate on a subrectangle of the video frame. If this capability is present, source images can be cropped before further processing occurs. |
| **DXVA2_VideoProcess_SubStreams** | The device can accept substreams in addition to the primary video stream, and can composite them. |
| **DXVA2_VideoProcess_SubStreamsExtended** | The device can perform color adjustments on the primary video stream and substreams, at the same time that it deinterlaces the video and composites the substreams. The destination color space is defined in the **DestFormat** member of the [DXVA2_VideoProcessBltParams](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_videoprocessbltparams) structure. The source color space for each stream is defined in the SampleFormat member of the [DXVA2_VideoSample](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_videosample) structure. |
| **DXVA2_VideoProcess_YUV2RGBExtended** | The device can convert the video from YUV to RGB color space when it writes the deinterlaced and composited pixels to the destination surface.<br><br>An RGB destination surface could be an off-screen surface, texture, Direct3D render target, or combined texture/render target surface. An RGB destination surface must use at least 8 bits for each color channel. |
| **DXVA2_VideoProcess_AlphaBlendExtended** | The device can perform an alpha blend operation with the destination surface when it writes the deinterlaced and composited pixels to the destination surface. |
| **DXVA2_VideoProcess_Constriction** | The device can downsample the output frame, as specified by the **ConstrictionSize** member of the [DXVA2_VideoProcessBltParams](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_videoprocessbltparams) structure. |
| **DXVA2_VideoProcess_NoiseFilter** | The device can perform noise filtering. |
| **DXVA2_VideoProcess_DetailFilter** | The device can perform detail filtering. |
| **DXVA2_VideoProcess_PlanarAlpha** | The device can perform a constant alpha blend to the entire video stream when it composites the video stream and substreams. |
| **DXVA2_VideoProcess_LinearScaling** | The device can perform accurate linear RGB scaling, rather than performing them in nonlinear gamma space. |
| **DXVA2_VideoProcess_GammaCompensated** | The device can correct the image to compensate for artifacts introduced when performing scaling in nonlinear gamma space. |
| **DXVA2_VideoProcess_MaintainsOriginalFieldData** | The deinterlacing algorithm preserves the original field lines from the interlaced field picture, unless scaling is also applied.<br><br>For example, in deinterlacing algorithms such as bob and median filtering, the device copies the original field into every other scan line and then applies a filter to reconstruct the missing scan lines. As a result, the original field can be recovered by discarding the scan lines that were interpolated.<br><br>If the image is scaled vertically, however, the original field lines cannot be recovered. If the image is scaled horizontally (but not vertically), the resulting field lines will be equivalent to scaling the original field picture. (In other words, discarding the interpolated scan lines will yield the same result as stretching the original picture without deinterlacing.) |

### `NoiseFilterTechnology`

Specifies the supported noise filters. The value is a bitwise **OR** of the following flags.

| Value | Meaning |
| --- | --- |
| **DXVA2_NoiseFilterTech_Unsupported** | Noise filtering is not supported. |
| **DXVA2_NoiseFilterTech_Unknown** | Unknown or proprietary filter. |
| **DXVA2_NoiseFilterTech_Median** | Median filter. |
| **DXVA2_NoiseFilterTech_Temporal** | Temporal filter. |
| **DXVA2_NoiseFilterTech_BlockNoise** | Block noise filter. |
| **DXVA2_NoiseFilterTech_MosquitoNoise** | Mosquito noise filter. |

### `DetailFilterTechnology`

Specifies the supported detail filters. The value is a bitwise **OR** of the following flags.

| Value | Meaning |
| --- | --- |
| **DXVA2_DetailFilterTech_Unsupported** | Detail filtering is not supported. |
| **DXVA2_DetailFilterTech_Unknown** | Unknown or proprietary filter. |
| **DXVA2_DetailFilterTech_Edge** | Edge filter. |
| **DXVA2_DetailFilterTech_Sharpening** | Sharpen filter. |

## See also

[IDirectXVideoProcessor::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoprocessor-getvideoprocessorcaps)

[IDirectXVideoProcessorService::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoprocessorservice-getvideoprocessorcaps)

[IMFVideoProcessor::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/evr9/nf-evr9-imfvideoprocessor-getvideoprocessorcaps)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)