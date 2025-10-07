# WPD\_DEVICE\_TYPES enumeration

The **WPD\_DEVICE\_TYPES** enumeration type describes the different Windows Portable Device (WPD) types commonly used to determine the basic classification and visual appearance of a portable device.

## Constants

**WPD\_DEVICE\_TYPE\_GENERIC**

A generic WPD that includes multifunction devices that do not fall into one of the other [**WPD\_DEVICE\_TYPES**](https://learn.microsoft.com/windows/win32/wpd_sdk/wpd-device-types) enumeration values.

**WPD\_DEVICE\_TYPE\_CAMERA**

A camera device, such as a digital still camera.

**WPD\_DEVICE\_TYPE\_MEDIA\_PLAYER**

A media player device that supports playing audio, video, or viewing pictures, such as a portable music player or portable media center. Not all of this functionally is classified as a WPD\_DEVICE\_TYPE\_MEDIA\_PLAYER. For example, portable music player devices are classified as WPD\_DEVICE\_TYPE\_MEDIA\_PLAYER.

**WPD\_DEVICE\_TYPE\_PHONE**

A phone device, such as a mobile phone.

**WPD\_DEVICE\_TYPE\_VIDEO**

A video device.

**WPD\_DEVICE\_TYPE\_PERSONAL\_INFORMATION\_MANAGER**

A personal information manager device.

**WPD\_DEVICE\_TYPE\_AUDIO\_RECORDER**

An audio recorder device.

## Remarks

**WPD\_DEVICE\_TYPES** are read using the [**IPortableDeviceManager**](https://learn.microsoft.com/windows/desktop/api/PortableDeviceApi/nn-portabledeviceapi-iportabledevicemanager) interface. WPD applications may use these values to determine the generic visual appearance of the device. That is, a camera picture is displayed for camera-like devices, a mobile phone picture is displayed for phone-like devices, and so on.

> [!Note]
> WPD applications must use the capabilities of the portable device to determine functionally, not the **WPD\_DEVICE\_TYPES** value.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------------|
| Header<br> | PortableDevice.h |

## See also

[**Structures and Enumeration Types**](https://learn.microsoft.com/windows/win32/wpd_sdk/structures-and-enumeration-types)

