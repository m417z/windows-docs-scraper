# IEVRTrustedVideoPlugin::CanConstrict

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Queries whether the plug-in can limit the effective video resolution.

## Parameters

### `pYes` [out]

Receives a Boolean value. If **TRUE**, the plug-in can limit the effective video resolution. Otherwise, the plug-in cannot limit the video resolution. If the method fails, the EVR treats the value as **FALSE** (not supported).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Constriction is a protection mechanism that limits the effective resolution of the video frame to a specified maximum number of pixels.

Video constriction can be implemented by either the mixer or the presenter.

If the method returns **TRUE**, the EVR might call [IEVRTrustedVideoPlugin::SetConstriction](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-ievrtrustedvideoplugin-setconstriction) at any time.

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[IEVRTrustedVideoPlugin](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-ievrtrustedvideoplugin)

[Protected Media Path](https://learn.microsoft.com/windows/desktop/medfound/protected-media-path)