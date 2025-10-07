# DbgLog macro

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DbgLog** macro sends a string to the debug output location, if logging is enabled for the specified type and level. This macro is ignored in retail builds.

## Parameters

*Types*

Bitwise combination of one or more message types.

*Level*

Logging level for this message.

*pFormat*

A **printf** -style format string.

*...*

Additional arguments for the format string.

## Return value

This macro does not return a value.

## Remarks

If debug logging for any of the message types is set to the specified level or higher, this macro sends the formatted string to the debug output location.

The macro automatically adds a newline character to the output string.

> [!Note]
> An additional set of parentheses must enclose the macro parameters:

```C++
DbgLog((LOG_TRACE, 3, TEXT("Connected input pin %d"), nPinNumber));
```

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------------------------|
| Header<br> | Wxdebug.h (include Streams.h) |

## See also

[Debug Output Functions](https://learn.microsoft.com/windows/win32/directshow/debug-output-functions)

