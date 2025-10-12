# LPFNNewCOMObject function pointer

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Pointer to a function that creates an instance of the object.

## Parameters

*pUnkOuter*

Pointer to the **IUnknown** interface of the object that aggregates the new object, if any. This pointer can be **NULL**.

*phr*

Pointer to an **HRESULT** value. If the constructor fails, this parameter receives an error code.

## Return value

Returns a pointer to a new instance of the object.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------------------------|
| Header<br> | Combase.h (include Streams.h) |

## See also

[**CFactoryTemplate Class**](https://learn.microsoft.com/windows/win32/directshow/cfactorytemplate)

