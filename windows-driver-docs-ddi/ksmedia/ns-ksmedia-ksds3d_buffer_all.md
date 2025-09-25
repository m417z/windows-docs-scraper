# KSDS3D_BUFFER_ALL structure

## Description

The KSDS3D_BUFFER_ALL structure specifies all the 3D characteristics of a DirectSound 3D buffer.

## Members

### `Position`

Specifies the x, y, and z position coordinates of the 3D sound buffer. This member is a structure of type [DS3DVECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ds3dvector).

### `Velocity`

Specifies the x, y, and z velocity components of the 3D sound buffer. This member is a structure of type DS3DVECTOR.

### `InsideConeAngle`

Specifies the angle in degrees of the inside sound projection cone.

### `OutsideConeAngle`

Specifies the angle in degrees of the outside sound projection cone.

### `ConeOrientation`

Specifies the x, y, and z components of the orientation of the 3D buffer's sound projection cone. This member is a structure of type DS3DVECTOR.

### `ConeOutsideVolume`

Specifies the cone outside volume.

### `MinDistance`

Specifies the minimum distance between the speaker and listener. (See the discussion of minimum and maximum distances for DirectSound 3D buffers in the Microsoft Windows SDK documentation.)

### `MaxDistance`

Specifies the maximum distance between the speaker and listener.

### `Mode`

Specifies the 3D sound-processing mode. This can be one of the following values from the header file Dsound.h:

* DS3DMODE_DISABLE
* DS3DMODE_HEADRELATIVE
* DS3DMODE_NORMAL

For the meaning of these parameters, see the description of the **dwMode** member of the DS3DBUFFER structure in the Microsoft Windows SDK documentation.

## Remarks

This structure is used to set or get the data value for the [KSPROPERTY_DIRECTSOUND3DBUFFER_ALL](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-directsound3dbuffer-all) property. DirectSound uses this property to implement the **IDirectSound3DBuffer::GetAllParameters** and **IDirectSound3DBuffer::SetAllParameters** methods, which are described in the Windows SDK documentation.

The members of this structure are similar to those defined for the DS3DBUFFER structure in the Windows SDK documentation.

## See also

[DS3DVECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ds3dvector)

[KSPROPERTY_DIRECTSOUND3DBUFFER_ALL](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-directsound3dbuffer-all)