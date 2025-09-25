# IMFVideoProcessor::SetFilteringValue

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Sets a parameter for an image filter.

## Parameters

### `dwProperty` [in]

The image filtering parameter to set. For a list of possible values, see [DXVA Image Filter Settings](https://learn.microsoft.com/windows/desktop/medfound/dxva-image-filter-settings).

### `pValue` [in]

Pointer to a [DXVA2_Fixed32](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_fixed32) structure that specifies the new value. To get the valid range of values for each parameter, call [IMFVideoProcessor::GetFilteringRange](https://learn.microsoft.com/windows/desktop/api/evr9/nf-evr9-imfvideoprocessor-getfilteringrange).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The value of *dwProperty* is invalid. |
| **MF_E_TRANSFORM_TYPE_NOT_SET** | The media type for the reference stream is not set. |

## Remarks

Before calling this method, set the video processor mode. To select a video processor mode, call [IMFVideoProcessor::SetVideoProcessorMode](https://learn.microsoft.com/windows/desktop/api/evr9/nf-evr9-imfvideoprocessor-setvideoprocessormode). Otherwise, the EVR automatically selects a mode when streaming begins.

To find out which image filters the driver supports, call [IMFVideoProcessor::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/evr9/nf-evr9-imfvideoprocessor-getvideoprocessorcaps).

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[IMFVideoProcessor](https://learn.microsoft.com/windows/desktop/api/evr9/nn-evr9-imfvideoprocessor)