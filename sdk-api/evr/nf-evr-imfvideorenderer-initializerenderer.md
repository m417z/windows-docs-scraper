# IMFVideoRenderer::InitializeRenderer

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Sets a new mixer or presenter for the enhanced video renderer (EVR).

## Parameters

### `pVideoMixer` [in]

Pointer to the [IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform) interface of the mixer to use. This parameter can be **NULL**. If this parameter is **NULL**, the EVR uses its default mixer.

### `pVideoPresenter` [in]

Pointer to the [IMFVideoPresenter](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfvideopresenter) interface of the presenter to use. This parameter can be **NULL**. If this parameter is **NULL**, the EVR uses its default presenter.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Either the mixer or the presenter is invalid. |
| **MF_E_INVALIDREQUEST** | The mixer and presenter cannot be replaced in the current state. (EVR media sink.) |
| **MF_E_SHUTDOWN** | The video renderer has been shut down. |
| **VFW_E_WRONG_STATE** | One or more input pins are connected. (DirectShow EVR filter.) |

## Remarks

Call this method directly after creating the EVR, before you do any of the following:

* Call [IMFGetService::GetService](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfgetservice-getservice) on the EVR.
* Call [IEVRFilterConfig::SetNumberOfStreams](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-ievrfilterconfig-setnumberofstreams) on the EVR.
* Connect any pins on the EVR filter, or set any media types on EVR media sink.

The EVR filter returns VFW_E_WRONG_STATE if any of the filter's pins are connected. The EVR media sink returns MF_E_INVALIDREQUEST if a media type is set on any of the streams, or the presentation clock is running or paused.

The device identifiers for the mixer and the presenter must match. The [IMFVideoDeviceID::GetDeviceID](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imfvideodeviceid-getdeviceid) method returns the device identifier. If they do not match, the method returns E_INVALIDARG.

If the video renderer is in the protected media path (PMP), the mixer and presenter objects must be certified safe components and pass any trust authority verification that is being enforced. Otherwise, this method will fail.

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[How to Write an EVR Presenter](https://learn.microsoft.com/windows/desktop/medfound/how-to-write-an-evr-presenter)

[IMFVideoRenderer](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfvideorenderer)