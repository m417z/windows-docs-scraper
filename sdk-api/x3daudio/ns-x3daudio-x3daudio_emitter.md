# X3DAUDIO_EMITTER structure

## Description

Defines a single-point or multiple-point 3D audio source that is used with an arbitrary number of sound channels.

## Members

### `pCone`

Pointer to a sound cone. Used only with single-channel emitters for matrix, LPF (both direct and reverb paths), and reverb calculations. NULL specifies the emitter is omnidirectional.

### `OrientFront`

Orientation of the front direction. This value must be orthonormal with **OrientTop**. **OrientFront** must be normalized when used. For single-channel emitters without cones **OrientFront** is only used for emitter angle calculations. For multi channel emitters or single-channel with cones **OrientFront** is used for matrix, LPF (both direct and reverb paths), and reverb calculations.

### `OrientTop`

Orientation of the top direction. This value must be orthonormal with **OrientFront**. **OrientTop** is only used with multi-channel emitters for matrix calculations.

### `Position`

Position in user-defined world units. This value does not affect **Velocity**.

### `Velocity`

Velocity vector in user-defined world units/second. This value is used only for doppler calculations. It does not affect **Position**.

### `InnerRadius`

Value to be used for the inner radius calculations. If **InnerRadius** is 0, then no inner radius is used, but **InnerRadiusAngle** may still be used. This value must be between 0.0f and MAX_FLT.

### `InnerRadiusAngle`

Value to be used for the inner radius angle calculations. This value must be between 0.0f and X3DAUDIO_PI/4.0.

### `ChannelCount`

Number of emitters defined by the **X3DAUDIO_EMITTER** structure. Must be greater than 0.

### `ChannelRadius`

Distance from **Position** that channels will be placed if **ChannelCount** is greater than 1. **ChannelRadius** is only used with multi-channel emitters for matrix calculations. Must be greater than or equal to 0.0f.

### `pChannelAzimuths`

Table of channel positions, expressed as an azimuth in radians along the channel radius with respect to the front orientation vector in the plane orthogonal to the top orientation vector. An azimuth of X3DAUDIO_2PI specifies a channel is a low-frequency effects (LFE) channel. LFE channels are positioned at the emitter base and are calculated with respect to **pLFECurve** only, never **pVolumeCurve**. **pChannelAzimuths** must have at least **ChannelCount** elements, but can be **NULL** if **ChannelCount** = 1. The table values must be within 0.0f to X3DAUDIO_2PI. **pChannelAzimuths** is used with multi-channel emitters for matrix calculations.

### `pVolumeCurve`

Volume-level distance curve, which is used only for matrix calculations. NULL specifies a specialized default curve that conforms to the inverse square law, such that when distance is between 0.0f and **CurveDistanceScaler** × 1.0f, no attenuation is applied.
When distance is greater than **CurveDistanceScaler** × 1.0f, the amplification factor is (**CurveDistanceScaler** × 1.0f)/distance. At a distance of **CurveDistanceScaler** × 2.0f, the sound will be at half volume or -6 dB, at a distance of **CurveDistanceScaler** × 4.0f, the sound will be at one quarter volume or -12 dB, and so on.

**pVolumeCurve** and pLFECurve are independent of each other. **pVolumeCurve** does not affect **LFE channel** volume.

### `pLFECurve`

LFE roll-off distance curve, or NULL to use default curve: [0.0f, **CurveDistanceScaler** ×1.0f], [**CurveDistanceScaler** ×1.0f, 0.0f]. A NULL value for **pLFECurve** specifies a default curve that conforms to the inverse square law with distances <= **CurveDistanceScaler** clamped to no attenuation.
**pVolumeCurve** and **pLFECurve** are independent of each other. **pLFECurve** does not affect non LFE channel volume.

### `pLPFDirectCurve`

Low-pass filter (LPF) direct-path coefficient distance curve, or NULL to use the default curve: [0.0f, 1.0f], [1.0f, 0.75f]. **pLPFDirectCurve** is only used for LPF direct-path calculations.

### `pLPFReverbCurve`

LPF reverb-path coefficient distance curve, or NULL to use default curve: [0.0f, 0.75f], [1.0f, 0.75f]. **pLPFReverbCurve** is only used for LPF reverb path calculations.

### `pReverbCurve`

Reverb send level distance curve, or NULL to use default curve: [0.0f, 1.0f], [1.0f, 0.0f].

### `CurveDistanceScaler`

Curve distance scaler that is used to scale normalized distance curves to user-defined world units, and/or to exaggerate their effect. This does not affect any other calculations. The value must be within the range FLT_MIN to FLT_MAX. **CurveDistanceScaler** is only used for matrix, LPF (both direct and reverb paths), and reverb calculations.

### `DopplerScaler`

Doppler shift scaler that is used to exaggerate Doppler shift effect. **DopplerScaler** is only used for Doppler calculations and does not affect any other calculations. The value must be within the range 0.0f to FLT_MAX.

## Remarks

**X3DAUDIO_EMITTER** only supports a cone in a single-point emitter. Multi-point emitters are a convenient and efficient way to manage a related group of sound sources. Many properties are shared among all channel points, such as Doppler—the same Doppler shift is applied to all channels in the emitter. Thus, the Doppler value need only be calculated once, not per-point as would be needed with multiple separate single-point emitters. Because **X3DAUDIO_EMITTER** only has one orientation vector, a multi-point emitter cone would be of limited usefulness, forcing all channels to behave as if they were facing the same direction. If multiple independent cones are needed, multiple single-point emitters should be used, each with its own orientation.

The parameter type X3DAUDIO_VECTOR is typed to DirectX::XMFLOAT3, to provide x , y , and z floating-point values.

X3DAudio uses a left-handed Cartesian coordinate system, with values on the x-axis increasing from left to right, on the y-axis from bottom to top, and on the z-axis from near to far. Azimuths are measured clockwise from a given reference direction.

To use X3DAudio with right-handed coordinates, you must negate the .z element of *OrientFront*, *OrientTop*, *Position*, and *Velocity*.

For user-defined distance curves, the distance field of the first point must be 0.0f and the distance field of the last point must be 1.0f.

If an emitter moves beyond a distance of (**CurveDistanceScaler** × 1.0f), the last point on the curve is used to compute the volume output level. The last point is determined by the following:

```
X3DAUDIO_DISTANCE_CURVE.pPoints[PointCount-1].DSPSetting)
```

### Inner Radius and Inner Radius Angle

**InnerRadius** is used to specify an area of smooth transition around the origin point as a sound travels directly through, above or below the listener. Elevation is accounted for by specifying an **InnerRadiusAngle**, whereby a sound whose elevation increases or decreases, will eventually start to bleed the sound into more than just two speakers.

When Inner Radius and Inner Radius Angle are not used, emitters are audible in the two closest speakers to their current position/orientation (or, if directly on a line with one speaker's defined angle, solely from that one speaker).

Inner Radius and Inner Radius Angle have no effect on emitters positioned outside of the cones they describe. Inside of the cone, they will gradually cause the sound to bleed into the opposite speakers, until the sound will be equally heard in all speakers when the emitter is at the same position as (or directly above or below) the listener.

![Inner radius and inner radius angle](https://learn.microsoft.com/windows/win32/api/x3daudio/images/x3daudio_emitter_structure.png)

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)