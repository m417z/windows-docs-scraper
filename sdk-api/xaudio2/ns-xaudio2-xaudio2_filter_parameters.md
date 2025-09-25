# XAUDIO2_FILTER_PARAMETERS structure

## Description

Defines filter parameters for a source voice.

## Members

### `Type`

The [XAUDIO2_FILTER_TYPE](https://learn.microsoft.com/windows/desktop/api/xaudio2/ne-xaudio2-xaudio2_filter_type).

### `Frequency`

Filter radian frequency calculated as (2 * sin(pi * (desired filter cutoff frequency) / sampleRate)). The frequency must be greater than or equal to 0 and less than or equal to XAUDIO2_MAX_FILTER_FREQUENCY. The maximum frequency allowable is equal to the source sound's sample rate divided by six which corresponds to the maximum filter radian frequency of 1. For example, if a sound's sample rate is 48000 and the desired cutoff frequency is the maximum allowable value for that sample rate, 8000, the value for **Frequency** will be 1.
If XAUDIO2_HELPER_FUNCTIONS is defined, XAudio2.h will include the [XAudio2RadiansToCutoffFrequency](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-xaudio2radianstocutofffrequency) and [XAudio2CutoffFrequencyToRadians](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-xaudio2cutofffrequencytoradians) helper functions for converting between hertz and radian frequencies. Defining XAUDIO2_HELPER_FUNCTIONS will also include [XAudio2CutoffFrequencyToOnePoleCoefficient](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-xaudio2cutofffrequencytoonepolecoefficient) for converting between hertz and a one-pole coefficient suitable for use with the LowPassOnePoleFilter and HighPassOnePoleFilter.

### `OneOverQ`

Reciprocal of Q factor. Controls how quickly frequencies beyond Frequency are dampened. Larger values result in quicker dampening while smaller values cause dampening to occur more gradually. Must be greater than 0 and less than or equal to XAUDIO2_MAX_FILTER_ONEOVERQ.

## Remarks

Setting XAUDIO2_FILTER_PARAMETERS with the following values is acoustically equivalent to the filter being fully bypassed.

```
XAUDIO2_FILTER_PARAMETERS FilterParams;
FilterParams.Frequency = 1.0f;
FilterParams.OneOverQ = 1.0f;
FilterParams.Type = LowPassFilter;

```

The following formulas show the relationship between the members of XAUDIO2_FILTER_PARAMETERS and the per-voice filter.

```
Yl( n ) = F1 yb( n ) + yl( n - 1 )
Yb( n ) = F1 yh( n ) + yb( n - 1 )
Yh( n ) = x( n ) - yl( n ) - OneOverQ(yb( n - 1 )
Yn( n ) = Yl(n) + Yh(n)

```

Where:

```
Yl = lowpass output
Yb = bandpass output
Yh = highpass output
Yn = notch output
F1 = XAUDIO2_FILTER_PARAMETERS.Frequency
OneOverQ = XAUDIO2_FILTER_PARAMETERS.OneOverQ
```

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2Voice::GetFilterParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-getfilterparameters)

[IXAudio2Voice::SetFilterParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-setfilterparameters)

[XAudio2 Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)