# XAUDIO2_FILTER_TYPE enumeration

## Description

Indicates the filter type.

## Constants

### `LowPassFilter`

Attenuates (reduces) frequencies above the cutoff frequency.

### `BandPassFilter`

Attenuates frequencies outside a given range.

### `HighPassFilter`

Attenuates frequencies below the cutoff frequency.

### `NotchFilter`

Attenuates frequencies inside a given range.

### `LowPassOnePoleFilter`

Attenuates frequencies above the cutoff frequency. This is a one-pole filter, and [XAUDIO2_FILTER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_filter_parameters).**OneOverQ** has no effect.

### `HighPassOnePoleFilter`

Attenuates frequencies below the cutoff frequency. This is a one-pole filter, and [XAUDIO2_FILTER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_filter_parameters).**OneOverQ** has no effect.

## Remarks

**Note** Note that the DirectX SDK versions of XAUDIO2 do not support the **LowPassOnePoleFilter** or the **HighPassOnePoleFilter**.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[XAUDIO2_FILTER_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_filter_parameters)

[XAudio2::Enumerations](https://learn.microsoft.com/windows/desktop/xaudio2/enumerations)