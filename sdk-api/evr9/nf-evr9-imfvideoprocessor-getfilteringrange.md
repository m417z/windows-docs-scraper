# IMFVideoProcessor::GetFilteringRange

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Retrieves the range of values for a specified image filter setting.

## Parameters

### `dwProperty` [in]

The image filtering parameter to query. For a list of possible values, see [DXVA Image Filter Settings](https://learn.microsoft.com/windows/desktop/medfound/dxva-image-filter-settings).

### `pPropRange` [out]

Pointer to a [DXVA2_ValueRange](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_valuerange) structure that receives range of values for the specified image filtering parameter.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **DDERR_UNSUPPORTED** | The driver does not support this filter setting. |
| **E_INVALIDARG** | Invalid value for *dwProperty*. |
| **MF_E_INVALIDREQUEST** | No video processor mode has been set. |
| **MF_E_NOT_AVAILABLE** | The specified operation is not available. |
| **MF_E_TRANSFORM_TYPE_NOT_SET** | The media type for the reference stream is not set. |

## Remarks

This method returns the range of values that the current video processor mode supports for the specified image filter setting.

This method fails if the video processor mode has not been set on the mixer. To select a video processor mode, call [IMFVideoProcessor::SetVideoProcessorMode](https://learn.microsoft.com/windows/desktop/api/evr9/nf-evr9-imfvideoprocessor-setvideoprocessormode). Otherwise, the EVR automatically selects a mode when streaming begins.

To find out which image filters the driver supports, call [IMFVideoProcessor::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/evr9/nf-evr9-imfvideoprocessor-getvideoprocessorcaps).

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[IMFVideoProcessor](https://learn.microsoft.com/windows/desktop/api/evr9/nn-evr9-imfvideoprocessor)