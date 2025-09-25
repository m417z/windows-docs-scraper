## Description

Represents a system audio effect APO notification.

## Members

### `endpoint`

An [IMMDevice](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nn-mmdeviceapi-immdevice) representing the audio endpoint associated with the notification.

### `propertyStoreContext`

A GUID identifying the APO property store associated with the notification.

### `propertyStoreType`

A value from the [AUDIO_SYSTEMEFFECTS_PROPERTYSTORE_TYPE](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/ne-mmdeviceapi-audio_systemeffects_propertystore_type) enumeration specifying the type of the property store associated with the notification.

### `propertyStore`

An [IPropertyStore](https://learn.microsoft.com/windows/win32/api/propsys/nn-propsys-ipropertystore) representing the property store associated with the notification.

### `propertyKey`

A [PROPERTYKEY](https://learn.microsoft.com/windows/win32/api/wtypes/ns-wtypes-propertykey) structure identifying the property associated with the notification.

## Remarks

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also