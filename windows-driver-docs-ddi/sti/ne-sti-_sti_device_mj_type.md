# _STI_DEVICE_MJ_TYPE enumeration

## Description

The STI_DEVICE_TYPE type identifies the device type of a still image device.

The DWORD is divided into a HIWORD containing the major device type, and a LOWORD containing a vendor-defined subtype.

## Constants

### `StiDeviceTypeDefault`

Default type.

### `StiDeviceTypeScanner`

Scanner.

### `StiDeviceTypeDigitalCamera`

Digital camera.

### `StiDeviceTypeStreamingVideo`

Streaming video.

## Remarks

The following macros are used to extract the major device type and subtype:

```cpp
GET_STIDEVICE_TYPE(dwDevType)
GET_STIDEVICE_SUBTYPE(dwDevType)
```