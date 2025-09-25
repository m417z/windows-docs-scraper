# ID3D11VideoDevice::CreateVideoProcessorInputView

## Description

Creates a resource view for a video processor, describing the input sample for the video processing operation.

## Parameters

### `pResource` [in]

A pointer to the [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource) interface of the input surface.

### `pEnum` [in]

A pointer to the [ID3D11VideoProcessorEnumerator](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessorenumerator) interface that specifies the video processor. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessorEnumerator](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessorenumerator).

### `pDesc` [in]

A pointer to a [D3D11_VIDEO_PROCESSOR_INPUT_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_input_view_desc) structure that describes the view.

### `ppVPIView` [out]

Receives a pointer to the [ID3D11VideoProcessorInputView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessorinputview) interface. The caller must release the resource. If this parameter is **NULL**, the method checks whether the view is supported, but does not create the view.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Set the *ppVPIView* parameter to **NULL** to test whether a view is supported.

The surface format is given in the **FourCC** member of the [D3D11_VIDEO_PROCESSOR_INPUT_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_input_view_desc) structure. The method fails if the video processor does not support this format as an input sample. An app must specify 0 when using 9_1, 9_2, or 9_3 feature levels.

Resources used for video processor input views must use the following bind flag combinations:

* Any combination of bind flags that includes [D3D11_BIND_DECODER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag),**D3D11_BIND_VIDEO_ENCODER**, **D3D11_BIND_RENDER_TARGET**, and **D3D11_BIND_UNORDERED_ACCESS_VIEW** can be used as for video processor input views (regardless of what other bind flags may be set).
* Bind flags = 0 is also allowed for a video processor input view.
* Other restrictions will apply such as:
  + No multi-sampling is allowed.
  + The Texture2D must have been created using [D3D11_USAGE_DEFAULT](https://learn.microsoft.com/windows/desktop/medfound/mf-sa-d3d11-usage).

## See also

[ID3D11VideoDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodevice)