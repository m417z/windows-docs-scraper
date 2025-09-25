# X3DAUDIO_DISTANCE_CURVE structure

## Description

Defines an explicit piecewise curve made up of linear segments, directly defining DSP behavior with respect to normalized distance.

## Members

### `pPoints`

[X3DAUDIO_DISTANCE_CURVE_POINT](https://learn.microsoft.com/windows/desktop/api/x3daudio/ns-x3daudio-x3daudio_distance_curve_point) array. The array must have no duplicates and be sorted in ascending order with respect to distance.

### `PointCount`

Number of distance curve points. There must be two or more points since all curves must have at least two endpoints defining values at 0.0f and 1.0f normalized distance, respectively.

## Remarks

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)