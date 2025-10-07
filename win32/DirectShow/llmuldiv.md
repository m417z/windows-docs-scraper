# llMulDiv function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `llMulDiv` function implements the formula `((a*b)+rnd)/c` where each term is a 64-bit value.

Time stamps and seek times are 64-bit values, so this function is useful for performing conversions on 32-bit systems. For example, the formula for bytes-per-second is

```C++
(Number of Bytes * Reference Time) / 10,000,000
```

which can be calculated as `llMulDiv(nBytes, rtTime, 10000000, 0)`. Use the *rnd* parameter as a rounding factor.

## Parameters

*a*

Multiplicand.

*b*

Multiplier.

*c*

Divisor.

*rnd*

Rounding factor.

## Return value

Returns either the `(a * b + rnd)/c` calculation or one of the following values.

| Return code | Description |
|---------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------|
| **0x7FFFFFFFFFFFFFFF** | Overflow occurred because the result is too large (positive).<br> |
| **0x8000000000000000** | Overflow occurred because the result is too large (negative).<br> |

## Remarks

Rounding on the division is toward zero. Division by zero is counted as an overflow condition.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Header<br> | Wxutil.h (include Streams.h) |
| Library<br> | Strmbase.lib (retail builds);

Strmbasd.lib (debug builds) | ## See also [Miscellaneous Helper Functions](https://learn.microsoft.com/windows/win32/directshow/miscellaneous-helper-functions) [**Int64x32Div32**](https://learn.microsoft.com/windows/win32/directshow/int64x32div32)