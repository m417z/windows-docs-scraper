## Description

Specifies the type of an audio system effects property store.

## Constants

### `AUDIO_SYSTEMEFFECTS_PROPERTYSTORE_TYPE_DEFAULT`

Default property store. Contains custom effects properties and is populated from the INF file. Properties will not be persisted across OS upgrades.

### `AUDIO_SYSTEMEFFECTS_PROPERTYSTORE_TYPE_USER`

User property store. Contains user settings pertaining to effects properties and will be persisted by the OS across upgrades and migrations.

### `AUDIO_SYSTEMEFFECTS_PROPERTYSTORE_TYPE_VOLATILE`

The volatile property store. Contains audio effects properties that are lost on device reboot. The store is cleared each time the endpoint transitions to active

### `AUDIO_SYSTEMEFFECTS_PROPERTYSTORE_TYPE_ENUM_COUNT`

## Remarks

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also