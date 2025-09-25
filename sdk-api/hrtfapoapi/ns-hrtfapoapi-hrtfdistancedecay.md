# HrtfDistanceDecay structure

## Description

Describes a distance-based decay behavior.

## Members

### `type`

The type of decay behavior, natural or custom.

### `maxGain`

The maximum gain limit applied at any distance. Applies to both natural and custom decay. This value is specified in dB, with a range from -96 to 12 inclusive. The default value is 12 dB.

### `minGain`

The minimum gain limit applied at any distance. Applies to both natural and custom decay. This value is specified in dB, with a range from -96 to 12 inclusive. The default value is -96 dB.

### `unityGainDistance`

The distance at which the gain is 0dB. Applies to natural decay only. This value is specified in meters, with a range from 0.05 to infinity (FLT_MAX). The default value is 1 meter.

### `cutoffDistance`

The distance at which output is silent. Applies to natural decay only. This value is specified in meters, with a range from zero (non-inclusive) to infinity (FLT_MAX). The default value is infinity.

## See also

[HrtfApoInit](https://learn.microsoft.com/windows/desktop/api/hrtfapoapi/ns-hrtfapoapi-hrtfapoinit)

[HrtfDistanceDecayType](https://learn.microsoft.com/windows/desktop/api/hrtfapoapi/ne-hrtfapoapi-hrtfdistancedecaytype)

[Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)