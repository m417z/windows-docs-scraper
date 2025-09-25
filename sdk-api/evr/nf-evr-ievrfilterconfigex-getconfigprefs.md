# IEVRFilterConfigEx::GetConfigPrefs

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Gets the configuration parameters for the Microsoft DirectShow [Enhanced Video Renderer Filter](https://learn.microsoft.com/windows/desktop/DirectShow/enhanced-video-renderer-filter) filter.

## Parameters

### `pdwConfigFlags` [out]

Receives a bitwise **OR** of flags from the [EVRFilterConfigPrefs](https://learn.microsoft.com/windows/win32/api/evr/ne-evr-evrfilterconfigprefs) enumeration.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Enhanced Video Renderer Filter](https://learn.microsoft.com/windows/desktop/DirectShow/enhanced-video-renderer-filter)

[IEVRFilterConfigEx](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-ievrfilterconfigex)

[Video Quality Management](https://learn.microsoft.com/windows/desktop/medfound/video-quality-management)