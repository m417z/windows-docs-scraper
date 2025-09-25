# ID3D11VideoDevice::CreateVideoProcessorOutputView

## Description

Creates a resource view for a video processor, describing the output sample for the video processing operation.

## Parameters

### `pResource` [in]

A pointer to the [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource) interface of the output surface. The resource must be created with the **D3D11_BIND_RENDER_TARGET** flag. See [D3D11_BIND_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag).

### `pEnum` [in]

A pointer to the [ID3D11VideoProcessorEnumerator](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessorenumerator) interface that specifies the video processor. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessorEnumerator](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessorenumerator).

### `pDesc` [in]

A pointer to a [D3D11_VIDEO_PROCESSOR_OUTPUT_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_output_view_desc) structure that describes the view.

### `ppVPOView` [out]

Receives a pointer to the [ID3D11VideoProcessorOutputView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessoroutputview) interface. The caller must release the resource. If this parameter is **NULL**, the method checks whether the view is supported, but does not create the view.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Set the *ppVPOView* parameter to **NULL** to test whether a view is supported.

Resources used for video processor output views must use the following [D3D11_BIND_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag) combinations:

* [D3D11_BIND_RENDER_TARGET](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag) indicates that it can be used for a video processor output view. The following bind flags are allowed to be set with **D3D11_BIND_RENDER_TARGET**:
  + [D3D11_BIND_VIDEO_ENCODER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag)
  + [D3D11_BIND_SHADER_RESOURCE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag)
* Other restrictions will apply such as:
  + No multi-sampling is allowed.
  + The Texture2D must have been created using [D3D11_USAGE_DEFAULT](https://learn.microsoft.com/windows/desktop/medfound/mf-sa-d3d11-usage).
* Some YUV formats can be supported as a video processor output view, but might not be supported as a 3D render target. D3D11 will allow the [D3D11_BIND_RENDER_TARGET](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag) flag for these formats, but [CreateRenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createrendertargetview) will not be allowed for these formats.

If stereo output is enabled, the output view must have 2 array elements. Otherwise, it must only have a single array element.

## See also

[ID3D11VideoDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodevice)