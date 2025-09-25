# IDirectXVideoProcessor::VideoProcessBlt

## Description

Performs a video process operation on one or more input samples and writes the result to a Direct3D9 surface.

## Parameters

### `pRenderTarget` [in]

A pointer to the [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface of a Direct3D surface. The output of the video processing operation will be written to this surface. The surface may be any of the following types:

* A surface created by calling [IDirectXVideoAccelerationService::CreateSurface](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoaccelerationservice-createsurface) with the **DXVA2_VideoProcessRenderTarget** flag. You can also use the **DXVA2_VideoSoftwareRenderTarget** flag, but only when the device GUID is **DXVA2_VideoProcSoftwareDevice** (software video processing device).
* A surface created from a Direct3D device with the **D3DUSAGE_RENDERTARGET** usage flag.
* A Direct3D swap chain.

### `pBltParams` [in]

A pointer to a [DXVA2_VideoProcessBltParams](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_videoprocessbltparams) structure that describes the video processing operation to perform.

### `pSamples` [in]

A pointer to an array of [DXVA2_VideoSample](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_videosample) structures that contain the input samples. There must be at least one element in the array.

The maximum number of input samples is given by the constant **MAX_DEINTERLACE_SURFACES**, defined in the header file dxva2api.h.

### `NumSamples` [in]

The number of elements in the *pSamples* array.

### `pHandleComplete` [out]

Reserved; set to **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **D3DERR_DRIVERINTERNALERROR** | Internal driver error. |
| **E_INVALIDARG** | Invalid arguments. |

## Remarks

When the method returns, the operation might not be complete.

If the method returns **E_INVALIDARG**, check for the following:

* The number of input samples (*NumSamples*) must be less than or equal to **MAX_DEINTERLACE_SURFACES**.
* The Direct3D surface must be a valid target for **VideoProcessBlt**. See the description of the *pRT* parameter for details.
* The presentation time (**TargetFrame**) given in *pBltParams* must match the start and end times for the current picture from the primary stream. Specifically, it must be less than the end time and greater than or equal to the start time. Note that the first sample in *pSamples* might not be the current picture, if the *pSamples* array contains backward reference pictures. For more information, see [Input Sample Order](https://learn.microsoft.com/windows/desktop/medfound/dxva-video-processing).
* The target rectangle (**TargetRect**) given in *pBltParams* cannot be larger than the destination surface (*pRT*).
* The constriction size (**ConstrictionSize**) given in *pBltParams* cannot be less than zero or larger than the target rectangle.
* The alpha component of the background color must be opqaue.
* The ProcAmp values given in *pBltParams* must be valid. For any ProcAmp settings that are supported by the driver, these values must fall within the ranges returned by the [IDirectXVideoProcessor::GetProcAmpRange](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoprocessor-getprocamprange) method.
* The noise and detail filters given in *pBltParams* must be valid. For any filters that are supported by the driver, these values must fall within the ranges returned by the [IDirectXVideoProcessor::GetFilterPropertyRange](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoprocessor-getfilterpropertyrange) method.
* The alpha value given in *pBltParams* must be in the range [0...1] inclusive.
* For each input sample given in *pSamples*:
  + The start time cannot be greater than the end time.
  + A valid [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) pointer must be provided.
  + The source rectangle cannot be larger than the input surface.
  + The destination rectangle cannot be larger than the destination surface.
  + The planar alpha must be in the range [0...1] inclusive.
* For all rectangles (source, destination, and target), the rectangle cannot be inverted (left > right or top > bottom) or have negative values.

## See also

[DXVA Video Processing](https://learn.microsoft.com/windows/desktop/medfound/dxva-video-processing)

[DXVA2_VideoSample](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_videosample)

[IDirectXVideoProcessor](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideoprocessor)