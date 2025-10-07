# EXECUTE\_ASSERT macro

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Evaluates an expression in debug and retail builds. In debug builds, displays a diagnostic message if the expression is **FALSE**.

## Parameters

*cond*

Expression to evaluate.

## Return value

This macro does not return a value.

## Remarks

Unlike the [**ASSERT**](https://learn.microsoft.com/windows/win32/directshow/assert) macro, this macro evaluates the expression in retail builds. In debug builds, if the expression is **FALSE**, the macro displays a message box with the text of the expression, the name of the source file, and the line number. The user can ignore the assertion, enter the debugger, or quit the application.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------------------------|
| Header<br> | Wxdebug.h (include Streams.h) |

## See also

[Assert and Breakpoint Macros](https://learn.microsoft.com/windows/win32/directshow/assert-and-breakpoint-macros)

