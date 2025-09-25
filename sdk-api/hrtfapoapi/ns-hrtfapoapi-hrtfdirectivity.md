# HrtfDirectivity structure

## Description

Base directivity pattern descriptor. Describes the type of directivity applied to a sound.

## Members

### `type`

Indicates the type of directivity.

### `scaling`

A normalized value between zero and one. Specifies the amount of linear interpolation between omnidirectional sound and the full directivity pattern, where 0 is fully omnidirectional and 1 is fully directional.

## Remarks

The scaling parameter is used to interpolate between directivity behavior and omnidirectional; it determines how much attenuation is applied to the source outside of the directivity pattern and controls how directional the source is.

For fully directional sources, while direct path signal outside the directivity pattern will be fully attenuated, any environmental reflections will still be audible.

## See also

[HrtfDirectivityType](https://learn.microsoft.com/windows/desktop/api/hrtfapoapi/ne-hrtfapoapi-hrtfdirectivitytype)

[Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)