# ValidateReadWritePtr macro

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Verifies that the calling process has read/write access to a memory block. If not, the macro calls the [**DbgBreak**](https://learn.microsoft.com/windows/win32/directshow/dbgbreak) macro.

> [!Note]
> This macro is deprecated. In the Windows SDK for Windows Vista (and later) this macro does not do anything.

## Parameters

*p*

Pointer to a memory block.

*cb*

Size of the memory block, in bytes.

## Return value

This macro does not return a value.

## Remarks

This macro is ignored unless DEBUG, \_DEBUG, or VFWROBUST is defined when the DirectShow base-class header file is included. This macro can have a significant performance cost.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------------------------|
| Header<br> | Wxdebug.h (include Streams.h) |

## See also

[Pointer Validation Macros](https://learn.microsoft.com/windows/win32/directshow/pointer-validation-macros)

