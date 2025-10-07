# KASSERT macro

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Evaluates an expression, and causes a breakpoint exception if the expression is **FALSE**. The text of the expression, the name of the source file, and the line number are logged using the [**DbgLog**](https://learn.microsoft.com/windows/win32/directshow/dbglog) macro. Ignored in retail builds.

## Parameters

*cond*

Expression to evaluate.

## Return value

This macro does not return a value.

## Remarks

Unlike the [**ASSERT**](https://learn.microsoft.com/windows/win32/directshow/assert) and [**EXECUTE\_ASSERT**](https://learn.microsoft.com/windows/win32/directshow/execute-assert) macros, this macro does not display a message box prompting the user. In debug builds, if the expression is **FALSE**, the macro automatically causes a breakpoint exception to occur.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------------------------|
| Header<br> | Wxdebug.h (include Streams.h) |

## See also

[Assert and Breakpoint Macros](https://learn.microsoft.com/windows/win32/directshow/assert-and-breakpoint-macros)

