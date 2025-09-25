# IMFVideoProcessor::GetProcAmpValues

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Retrieves the current settings for one or more color adjustment (ProcAmp) settings.

## Parameters

### `dwFlags` [in]

Bitwise **OR** of one or more flags, specifying which operations to query. For a list of flags, see [ProcAmp Settings](https://learn.microsoft.com/windows/desktop/medfound/procamp-settings).

### `Values` [out]

Pointer to a [DXVA2_ProcAmpValues](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_procampvalues) structure. The method fills the structure with the current value of each operation specified in *dwFlags*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_TRANSFORM_TYPE_NOT_SET** | The media type for the reference stream is not set. |

## Remarks

Before calling this method, you must set the media type for the reference stream.

Until the mixer's video processor mode is set, the returned values are all zero. After the processor mode is set, the returned values reflect the current mode. To select a video processor mode, call [IMFVideoProcessor::SetVideoProcessorMode](https://learn.microsoft.com/windows/desktop/api/evr9/nf-evr9-imfvideoprocessor-setvideoprocessormode). Otherwise, the EVR automatically selects a mode when streaming begins.

To find out which ProcAmp settings the driver supports, call [IMFVideoProcessor::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/evr9/nf-evr9-imfvideoprocessor-getvideoprocessorcaps).

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[IMFVideoProcessor](https://learn.microsoft.com/windows/desktop/api/evr9/nn-evr9-imfvideoprocessor)