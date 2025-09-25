# eAVDecDDOperationalMode enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the compression control mode for a Dolby AC-3 or Dolby Enhanced AC-3 audio stream. This enumeration is used with the [AVDecDDOperationalMode](https://learn.microsoft.com/windows/desktop/DirectShow/avdecddoperationalmode-property) property.

## Constants

### `eAVDecDDOperationalMode_NONE:0`

No dynamic range control or dialogue normalization (dialnorm). This mode should be used only for signal tests.

### `eAVDecDDOperationalMode_LINE:1`

Line mode. Dialnorm is enabled with a reference level of -31 decibels full scale (dBFS). Dynamic range control is applied, and high-level/low-level scaling is enabled. To set the high-level scaling factor, set the [AVDecDDDynamicRangeScaleHigh](https://learn.microsoft.com/windows/desktop/DirectShow/avdecdddynamicrangescalehigh-property) property. To set the low-level scaling factor, set the [AVDecDDDynamicRangeScaleLow](https://learn.microsoft.com/windows/desktop/DirectShow/avdecdddynamicrangescalelow-property) property.

### `eAVDecDDOperationalMode_RF:2`

RF mode. Dialnorm is enabled with a reference level of -20 dBFS. Dynamic range control is applied. High-level/low-level scaling is disabled; instead, the maximum dynamic range reduction is applied.

### `eAVDecDDOperationalMode_CUSTOM0:3`

Custom mode 0 (analog dialnorm).

### `eAVDecDDOperationalMode_CUSTOM1:4`

Custom mode 1 (digital dialnorm).

### `eAVDecDDOperationalMode_PORTABLE8:5`

Dialnorm enabled, dialogue at -8dBFS. Dynamic range and compression used. High-level/low-level scaling is not allowed (always fully compressed).

### `eAVDecDDOperationalMode_PORTABLE11:6`

Dialnorm enabled, dialogue at -11dBFS. Dynamic range and compression used. High-level/low-level scaling is not allowed (always fully compressed).

### `eAVDecDDOperationalMode_PORTABLE14:7`

Dialnorm enabled, dialogue at -14dBFS. Dynamic range and compression used. High-level/low-level scaling is not allowed (always fully compressed).

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)