# IDirectXVideoProcessorService::GetVideoProcessorDeviceGuids

## Description

Gets an array of GUIDs which identify the video processors supported by the graphics hardware.

## Parameters

### `pVideoDesc` [in]

Pointer to a [DXVA2_VideoDesc](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_videodesc) structure that describes the video content.

### `pCount` [out]

Receives the number of GUIDs.

### `pGuids` [out]

Receives an array of GUIDs. The size of the array is retrieved in the *pCount* parameter. The method allocates the memory for the array. The caller must free the memory by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The following video processor GUIDs are predefined.

| GUID | Description |
| --- | --- |
| **DXVA2_VideoProcBobDevice** | Bob deinterlace device. This device uses a "bob" algorithm to deinterlace the video. Bob algorithms create missing field lines by interpolating the lines in a single field. |
| **DXVA2_VideoProcProgressiveDevice** | Progressive video device. This device is available for progressive video, which does not require a deinterlace algorithm. |
| **DXVA2_VideoProcSoftwareDevice** | Reference (software) device. |

The graphics device may define additional vendor-specific GUIDs. The driver provides the list of GUIDs in descending quality order. The mode with the highest quality is first in the list. To get the capabilities of each mode, call [IDirectXVideoProcessorService::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoprocessorservice-getvideoprocessorcaps) and pass in the GUID for the mode.

#### Examples

```cpp

    // Initialize the video descriptor.

    g_VideoDesc.SampleWidth                         = VIDEO_MAIN_WIDTH;
    g_VideoDesc.SampleHeight                        = VIDEO_MAIN_HEIGHT;
    g_VideoDesc.SampleFormat.VideoChromaSubsampling = DXVA2_VideoChromaSubsampling_MPEG2;
    g_VideoDesc.SampleFormat.NominalRange           = DXVA2_NominalRange_16_235;
    g_VideoDesc.SampleFormat.VideoTransferMatrix    = EX_COLOR_INFO[g_ExColorInfo][0];
    g_VideoDesc.SampleFormat.VideoLighting          = DXVA2_VideoLighting_dim;
    g_VideoDesc.SampleFormat.VideoPrimaries         = DXVA2_VideoPrimaries_BT709;
    g_VideoDesc.SampleFormat.VideoTransferFunction  = DXVA2_VideoTransFunc_709;
    g_VideoDesc.SampleFormat.SampleFormat           = DXVA2_SampleProgressiveFrame;
    g_VideoDesc.Format                              = VIDEO_MAIN_FORMAT;
    g_VideoDesc.InputSampleFreq.Numerator           = VIDEO_FPS;
    g_VideoDesc.InputSampleFreq.Denominator         = 1;
    g_VideoDesc.OutputFrameFreq.Numerator           = VIDEO_FPS;
    g_VideoDesc.OutputFrameFreq.Denominator         = 1;

    // Query the video processor GUID.

    UINT count;
    GUID* guids = NULL;

    hr = g_pDXVAVPS->GetVideoProcessorDeviceGuids(&g_VideoDesc, &count, &guids);

```

## See also

[DXVA Video Processing](https://learn.microsoft.com/windows/desktop/medfound/dxva-video-processing)

[IDirectXVideoProcessorService](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideoprocessorservice)