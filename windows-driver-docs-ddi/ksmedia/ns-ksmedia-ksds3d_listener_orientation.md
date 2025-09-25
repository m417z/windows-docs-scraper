# KSDS3D_LISTENER_ORIENTATION structure

## Description

A KSD3D_LISTENER_ORIENTATION structure specifies the position vector of the 3D listener. This structure is used to get or set the data value for the [KSPROPERTY_DIRECTSOUND3DLISTENER_ORIENTATION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-directsound3dlistener-orientation) property.

## Members

### `Front`

Specifies the front orientation vector of the 3D listener. This member is a structure of type [DS3DVECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ds3dvector).

### `Top`

Specifies the top orientation vector of the 3D listener. This member is a structure of type DS3DVECTOR.

## Remarks

DirectSound uses this property to implement the **IDirectSound3DListener::GetOrientation** and **IDirectSound3DListener::SetOrientation** methods, which are described in the Microsoft Windows SDK documentation.

## See also

[DS3DVECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ds3dvector)

[KSPROPERTY_DIRECTSOUND3DLISTENER_ORIENTATION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-directsound3dlistener-orientation)