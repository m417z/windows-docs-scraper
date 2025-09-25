# X3DAUDIO_LISTENER structure

## Description

Defines a point of 3D audio reception.

## Members

### `OrientFront`

Orientation of front direction. When **pCone** is NULL **OrientFront** is used only for matrix and delay calculations. When **pCone** is not NULL **OrientFront** is used for matrix, LPF (both direct and reverb paths), and reverb calculations. This value must be orthonormal with **OrientTop** when used.

### `OrientTop`

Orientation of top direction, used only for matrix and delay calculations. This value must be orthonormal with **OrientFront** when used.

### `Position`

Position in user-defined world units. This value does not affect **Velocity**.

### `Velocity`

Velocity vector in user-defined world units per second, used only for doppler calculations. This value does not affect **Position**.

### `pCone`

Pointer to an [X3DAUDIO_CONE](https://learn.microsoft.com/windows/desktop/api/x3daudio/ns-x3daudio-x3daudio_cone) structure for this listener. Providing a listener cone will specify that additional calculations are performed when determining the volume and filter DSP parameters for individual sound sources. A NULL **pCone** value specifies an omnidirectional sound and no cone processing is applied. **pCone** is only used for matrix, LPF (both direct and reverb paths), and reverb calculations.

## Remarks

X3DAudio uses a left-handed Cartesian coordinate system, with values on the x-axis increasing from left to right, on the y-axis from bottom to top, and on the z-axis from near to far. Azimuths are measured clockwise from a given reference direction.

To use X3DAudio with right-handed coordinates, you must negate the .z element of *OrientFront*, *OrientTop*, *Position*, and *Velocity*.

The parameter type **X3DAUDIO_VECTOR** is typed to DirectX::XMFLOAT3, to provide x, y and z floating-point values.

A listener's front and top vectors must be orthonormal. To be considered orthonormal, a pair of vectors must have a magnitude of 1 +- 1x10-5 and a dot product of 0 +- 1x10-5.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)