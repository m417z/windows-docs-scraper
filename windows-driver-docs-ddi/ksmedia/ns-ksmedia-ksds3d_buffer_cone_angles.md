# KSDS3D_BUFFER_CONE_ANGLES structure

## Description

A KSDS3D_BUFFER_CONE_ANGLES structure specifies the inside and outside cone angles.

## Members

### `InsideConeAngle`

Specifies the angle in degrees of the inside sound projection cone.

### `OutsideConeAngle`

Specifies the angle in degrees of the outside sound projection cone.

## Remarks

This structure is used to set or get the data value for the [KSPROPERTY_DIRECTSOUND3DBUFFER_CONEANGLES](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-directsound3dbuffer-coneangles) property. DirectSound uses this property to implement the **IDirectSound3DBuffer::GetConeAngles** and **IDirectSound3DBuffer::SetConeAngles** methods, which are described in the Microsoft Windows SDK documentation.

## See also

[KSPROPERTY_DIRECTSOUND3DBUFFER_CONEANGLES](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-directsound3dbuffer-coneangles)