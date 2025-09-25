# IMFVideoProcessor::GetAvailableVideoProcessorModes

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Retrieves the video processor modes that the video driver supports.

## Parameters

### `lpdwNumProcessingModes` [in, out]

Receives the number of video processor modes.

### `ppVideoProcessingModes` [out]

Receives a pointer to an array of GUIDs. The number of elements in the array is returned in the *lpdwNumProcessingModes* parameter. The caller must release the memory for the array by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree). This parameter can be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_TRANSFORM_TYPE_NOT_SET** | The media type for the reference stream is not set. |

## Remarks

Video processor modes are identified by GUID. For a list of predefined GUIDs, see [IDirectXVideoProcessorService::GetVideoProcessorDeviceGuids](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideoprocessorservice-getvideoprocessordeviceguids). A driver can define additional vendor-specific GUIDs. To get the capabilities of each mode, pass the GUID to the [IMFVideoProcessor::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/evr9/nf-evr9-imfvideoprocessor-getvideoprocessorcaps) method.

Before calling this method, you must set the media type for the reference stream. Which modes are available might depend on the media type of the reference stream.

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[IMFVideoProcessor](https://learn.microsoft.com/windows/desktop/api/evr9/nn-evr9-imfvideoprocessor)