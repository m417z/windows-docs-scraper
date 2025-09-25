# KSDS3D_LISTENER_ALL structure

## Description

The KSDS3D_LISTENER_ALL structure specifies all the properties of the DirectSound 3D listener. This structure is used to get or set the data value for the [KSPROPERTY_DIRECTSOUND3DLISTENER_ALL](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-directsound3dlistener-all) property.

## Members

### `Position`

Specifies the position vector of the 3D listener. This member is a structure of type [DS3DVECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ds3dvector).

### `Velocity`

Specifies the velocity vector of the 3D listener. This member is a structure of type DS3DVECTOR.

### `OrientFront`

Specifies the front orientation vector of the 3D listener. This member is a structure of type DS3DVECTOR.

### `OrientTop`

Specifies the top orientation vector of the 3D listener. This member is a structure of type DS3DVECTOR.

### `DistanceFactor`

Specifies the distance factor for the 3D listener.

### `RolloffFactor`

Specifies the rolloff factor for the 3D listener.

### `DopplerFactor`

Specifies the Doppler factor for the 3D listener.

## Remarks

This structure is similar to the DS3DBUFFER structure that is described in the Microsoft Windows SDK documentation. The Windows SDK documentation also discusses the distance, rolloff, and Doppler factors for DirectSound 3D listeners.

DirectSound uses this property to implement the **IDirectSound3DListener::GetAllParameters** and **IDirectSound3DListener::SetAllParameters** methods, which are described in the Windows SDK documentation.

## See also

[DS3DVECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ds3dvector)

[KSPROPERTY_DIRECTSOUND3DLISTENER_ALL](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-directsound3dlistener-all)