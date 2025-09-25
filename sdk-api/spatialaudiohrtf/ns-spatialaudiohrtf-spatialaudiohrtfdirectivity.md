# SpatialAudioHrtfDirectivity structure

## Description

Represents an omnidirectional model for an [ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf). The omnidirectional emission is interpolated linearly with the directivity model specified in the **Type** field based on the value of the **Scaling** field.

## Members

### `Type`

The type of shape in which sound is emitted by an [ISpatialAudioObjectForHrtf](https://learn.microsoft.com/windows/desktop/api/spatialaudiohrtf/nn-spatialaudiohrtf-ispatialaudioobjectforhrtf).

### `Scaling`

The amount of linear interpolation applied between omnidirectional sound and the directivity specified in the **Type** field. This is a normalized value between 0 and 1.0 where 0 is omnidirectional and 1.0 is full directivity using the specified type.