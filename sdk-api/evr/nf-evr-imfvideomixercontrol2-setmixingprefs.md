# IMFVideoMixerControl2::SetMixingPrefs

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Sets the preferences for video deinterlacing.

## Parameters

### `dwMixFlags` [in]

Bitwise **OR** of zero or more flags from the [MFVideoMixPrefs](https://learn.microsoft.com/windows/desktop/api/evr/ne-evr-mfvideomixprefs) enumeration.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFVideoMixerControl2](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfvideomixercontrol2)

[Video Quality Management](https://learn.microsoft.com/windows/desktop/medfound/video-quality-management)