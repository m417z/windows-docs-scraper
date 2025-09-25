# tagWPD_DEVICE_TYPES enumeration

## Description

The **WPD_DEVICE_TYPES** enumeration type describes the different Windows Portable Devices (WPD) types used to determine the basic classification and visual appearance of a portable device.

## Constants

### `WPD_DEVICE_TYPE_GENERIC`

A generic Windows Portable Device. These include multifunction devices that do not fall into one of the other **WPD_DEVICE_TYPES** enumeration values.

### `WPD_DEVICE_TYPE_CAMERA`

A camera device, such as a digital still camera.

### `WPD_DEVICE_TYPE_MEDIA_PLAYER`

A media player device that may support playing audio, video, or viewing pictures (such as a portable music player or Portable Media Center). Not all of this functionally is required to be classified as a **WPD_DEVICE_TYPE_MEDIA_PLAYER**. For example, Portable Music Player devices that only support audio output are classified as **WPD_DEVICE_TYPE_MEDIA_PLAYER**.

### `WPD_DEVICE_TYPE_PHONE`

A phone device, such as a mobile phone.

### `WPD_DEVICE_TYPE_VIDEO`

### `WPD_DEVICE_TYPE_PERSONAL_INFORMATION_MANAGER`

### `WPD_DEVICE_TYPE_AUDIO_RECORDER`

## Remarks

**WPD_DEVICE_TYPES** are read using the **IPortableDeviceManager** interface. WPD applications may use these values to determine the generic visual appearance of the device. For example, a camera picture is displayed for camera-like devices, a mobile phone picture is displayed for phone-like devices, and so on.

**Note** WPD applications must use the capabilities of the portable device to determine functionally, not the **WPD_DEVICE_TYPE** value.

## See also

[Structures and Enumeration Types](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff597672(v=vs.85))