# SpatialAudioHrtfDistanceDecayType enumeration

## Description

Specifies the type of decay applied over distance from the position of an [ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf) to the position of the listener.

## Constants

### `SpatialAudioHrtfDistanceDecay_NaturalDecay:0`

A natural decay over distance, as constrained by minimum and maximum gain distance limits. The output drops to silent at the distance specified by [SpatialAudioHrtfDistanceDecay.CutoffDistance](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/ns-spatialaudiohrtf-spatialaudiohrtfdistancedecay).

### `SpatialAudioHrtfDistanceDecay_CustomDecay`

A custom gain curve, within the maximum and minimum gain limit.