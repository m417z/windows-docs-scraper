# _PosDeviceBasicsType structure

## Description

This structure indicates the type of device, version, and recommended buffer size as specified by the driver.

## Members

### `Version`

Contains the major and minor version of the POS driver interface. The top 16 bits contains the major version and the bottom 16 bits contains the minor version.

### `DeviceType`

Indicates the [PosDeviceType](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicecommontypes/ne-pointofservicecommontypes-_posdevicetype) of the POS device (for example, a barcode scanner or a magnetic stripe reader).

### `RecommendedBufferSize`

Indicates the size of the buffer that needs to be allocated to receive event data when calling [ReadFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfile) to retrieve events for this device.