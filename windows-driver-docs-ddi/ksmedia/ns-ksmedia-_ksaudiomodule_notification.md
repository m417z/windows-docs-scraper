# _KSAUDIOMODULE_NOTIFICATION structure

## Description

The **KSAUDIOMODULE_NOTIFICATION** structure describes the properties associated with audio modules change notification.

## Members

### `ProviderId`

A structure that specifies the ProviderId of the audio module notification.

### `ProviderId.DeviceId`

Specifies the DeviceId of the audio module notification. The DeviceId matches the value returned in [KSPROPERTY_AUDIOMODULE_NOTIFICATION_DEVICE_ID](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audiomodule-notification-device-id).

### `ProviderId.ClassId`

The ClassId of the audio module. The ClassId is an identifier that establishes what type of module this is. The value and mapping is established by the ISV and IHV.

### `ProviderId.InstanceId`

The InstanceId of the audio module. The InstanceId is a unique identifier that distinguishes this instance of a module from another instance of an module.

### `ProviderId.Reserved`

This member is reserved.

### `Alignment`

Specifies the value that is used for alignment.

## Remarks

The Audio module notification KSNOTIFICATIONID_AudioModule is defined in Ksmedia.h as shown here.

```cpp
//
// Audio module notification definitions.
//

#define STATIC_KSNOTIFICATIONID_AudioModule \
    0x9C2220F0, 0xD9A6, 0x4D5C, 0xA0, 0x36, 0x57, 0x38, 0x57, 0xFD, 0x50, 0xD2

DEFINE_GUIDSTRUCT("9C2220F0-D9A6-4D5C-A036-573857FD50D2", KSNOTIFICATIONID_AudioModule);

#define KSNOTIFICATIONID_AudioModule DEFINE_GUIDNAMED(KSNOTIFICATIONID_AudioModule)
```

For more information about audio modules, see [Implementing Audio Module Discovery](https://learn.microsoft.com/windows-hardware/drivers/audio/implementing-audio-module-communication).