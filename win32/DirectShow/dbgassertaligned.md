# DbgAssertAligned macro

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Tests whether a pointer is aligned to a specified boundary. If not, this macro invokes the [**ASSERT**](https://learn.microsoft.com/windows/win32/directshow/assert) macro. Ignored in retail builds.

## Parameters

*ptr*

Pointer variable.

*alignment*

Required alignment.

## Return value

This macro does not return a value.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------------------------|
| Header<br> | Wxdebug.h (include Streams.h) |

## See also

[Assert and Breakpoint Macros](https://learn.microsoft.com/windows/win32/directshow/assert-and-breakpoint-macros)

