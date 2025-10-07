# DbgBreak macro

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Displays a message box with the specified string, the name of the source file, and the line number. The user can ignore the message, enter the debugger, or quit the application. Ignored in retail builds.

## Parameters

*strLiteral*

Text string.

## Return value

This macro does not return a value.

## Examples

```C++
DbgBreak("Unrecoverable error occurred.");
```

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------------------------|
| Header<br> | Wxdebug.h (include Streams.h) |

## See also

[Assert and Breakpoint Macros](https://learn.microsoft.com/windows/win32/directshow/assert-and-breakpoint-macros)

