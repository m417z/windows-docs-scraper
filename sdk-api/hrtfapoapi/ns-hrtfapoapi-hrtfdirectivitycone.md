# HrtfDirectivityCone structure

## Description

Describes a cone directivity.

## Members

### `directivity`

Descriptor for the cone pattern. The type parameter must be set to HrtfDirectivityType.Cone.

### `innerAngle`

Angle, in radians, that defines the inner cone. Must be between 0 and 2 * pi.

### `outerAngle`

Angle, in radians, that defines the outer cone. Must be between 0 and 2 * pi.

## Remarks

Attenuation is 0 inside the inner cone. Attenuation is linearly interpolated between the inner cone, which is defined by *innerAngle*, and the outer cone, which is defined by *outerAngle.*

## See also

[HrtfDirectivity](https://learn.microsoft.com/windows/desktop/api/hrtfapoapi/ns-hrtfapoapi-hrtfdirectivity)

[HrtfDirectivityCardioid](https://learn.microsoft.com/windows/desktop/api/hrtfapoapi/ns-hrtfapoapi-hrtfdirectivitycardioid)

[Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)