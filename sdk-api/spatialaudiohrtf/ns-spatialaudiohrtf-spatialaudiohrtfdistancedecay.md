# SpatialAudioHrtfDistanceDecay structure

## Description

Represents the decay model that is applied over distance from the position of an [ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf) to the position of the listener.

## Members

### `Type`

The type of decay, natural or custom. The default value for this field is **SpatialAudioHrtfDistanceDecay_NaturalDecay**.

### `MaxGain`

### `MinGain`

### `UnityGainDistance`

### `CutoffDistance`

#### - float

The maximum gain limit applied at any distance. Applies to both natural and custom decay. This value is specified in dB, with a range from -96 to 12 inclusive. The default value is 12 dB.

The minimum gain limit applied at any distance. Applies to both natural and custom decay. This value is specified in dB, with a range from -96 to 12 inclusive. The default value is -96 dB.

The distance at which the gain is 0dB. Applies to natural decay only. This value is specified in meters, with a range from 0.05 to infinity (**FLT_MAX**). The default value is 1 meter.

The distance at which the output is silent. Applies to natural decay only. This value is specified in meters, with a range from zero (non-inclusive) to infinity (**FLT_MAX**). The default value is **INFINITY**.