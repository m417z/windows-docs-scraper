# SYSAUDIO_INSTANCE_INFO structure

## Description

The SYSAUDIO_INSTANCE_INFO structure specifies which virtual audio device to open and includes flags for configuring that device.

## Members

### `Property`

Specifies the property. This parameter is a structure of type [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure).

### `Flags`

Flags specifying how to configure the virtual audio device. Currently, the only flag bit defined for this parameter is SYSAUDIO_FLAGS_DONT_COMBINE_PINS. If set, this flag bit instructs SysAudio not to combine rendering pins. For more information, see the following Remarks section.

### `DeviceNumber`

Specifies the device ID. This member identifies the virtual audio device that is to be opened by the property request. If SysAudio enumerates *N* virtual audio devices (see [KSPROPERTY_SYSAUDIO_DEVICE_COUNT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-sysaudio-device-count)), the valid device IDs range from 0 to *N*-1.

## Remarks

This structure is used by the [KSPROPERTY_SYSAUDIO_INSTANCE_INFO](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-sysaudio-instance-info) property.

By default, a virtual audio device combines its wave-rendering pins. The SYSAUDIO_FLAGS_DONT_COMBINE_PINS flag overrides this default.

When pins are combined, the virtual audio device exposes a single pin factory that combines hardware-accelerated rendering pins on the audio device with software-emulated mixer pins on the [KMixer system driver](https://learn.microsoft.com/windows-hardware/drivers/audio/kernel-mode-wdm-audio-components). If the pins are not combined, then hardware-accelerated pins and software-emulated pins are exposed through separate pin factories. In order to correctly report the number of hardware-accelerated pins to application programs, DirectSound requires that the pins not be combined.

This property is similar to [KSPROPERTY_SYSAUDIO_DEVICE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-sysaudio-device-instance), with the exception that it includes flags specifying how to configure the virtual audio device.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_SYSAUDIO_DEVICE_COUNT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-sysaudio-device-count)

[KSPROPERTY_SYSAUDIO_DEVICE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-sysaudio-device-instance)

[KSPROPERTY_SYSAUDIO_INSTANCE_INFO](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-sysaudio-instance-info)