# LPFNInitRoutine function pointer

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Pointer to a function that gets called from the DLL entry point.

## Parameters

*bLoading*

**TRUE** when the DLL is loaded, **FALSE** when the DLL is unloaded.

*rclsid*

Pointer to the object's CLISD, specified in the [**CFactoryTemplate::m\_ClsID**](https://learn.microsoft.com/windows/win32/directshow/cfactorytemplate-m-clsid) member variable.

## Return value

This function pointer does not return a value.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------------------------|
| Header<br> | Combase.h (include Streams.h) |

## See also

[**CFactoryTemplate Class**](https://learn.microsoft.com/windows/win32/directshow/cfactorytemplate)

