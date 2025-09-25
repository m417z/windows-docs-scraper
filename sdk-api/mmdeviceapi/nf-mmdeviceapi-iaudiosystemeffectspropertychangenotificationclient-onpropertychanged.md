## Description

Called by the system when an audio system effects property changes.

## Parameters

### `type`

A value from the [AUDIO_SYSTEMEFFECTS_PROPERTYSTORE_TYPE](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/ne-mmdeviceapi-audio_systemeffects_propertystore_type) specifying the type of the property store that triggered the callback.
### `key`

A [PROPERTYKEY](https://learn.microsoft.com/windows/win32/api/wtypes/ns-wtypes-propertykey) structure identifying the property that changed.

## Return value

## Remarks

Register to receive callbacks by calling [IAudioSystemEffectsPropertyStore::RegisterPropertyChangeNotification](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nf-mmdeviceapi-iaudiosystemeffectspropertystore-registerpropertychangenotification). Unregister the callback interface by calling [IAudioSystemEffectsPropertyStore::UnregisterPropertyChangeNotification](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nf-mmdeviceapi-iaudiosystemeffectspropertystore-unregisterpropertychangenotification).

This method will not be called if the registry is manually edited. A notification is generated only when [IPropertyStore::SetValue](https://learn.microsoft.com/windows/win32/api/propsys/nf-propsys-ipropertystore-setvalue) is called on the associated default, user, or volatile property store.

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also