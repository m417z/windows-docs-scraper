# HrtfDistanceDecayType enumeration

## Description

Indicates a distance-based decay type applied to a sound.

## Constants

### `NaturalDecay:0`

Simulates natural decay with distance, as constrained by minimum and maximum gain distance limits. Drops to silence at rolloff distance.

### `CustomDecay`

Used to set up a custom gain curve, within the maximum and minimum gain limit.

## See also

[Enumerations](https://learn.microsoft.com/windows/desktop/xaudio2/enumerations)

[HrtfDistanceDecay](https://learn.microsoft.com/windows/desktop/api/hrtfapoapi/ns-hrtfapoapi-hrtfdistancedecay)