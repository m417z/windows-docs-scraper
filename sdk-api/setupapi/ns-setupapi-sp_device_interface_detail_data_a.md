# SP_DEVICE_INTERFACE_DETAIL_DATA_A structure

## Description

An SP_DEVICE_INTERFACE_DETAIL_DATA structure contains the path for a device interface.

## Members

### `cbSize`

The size, in bytes, of the SP_DEVICE_INTERFACE_DETAIL_DATA structure. For more information, see the following Remarks section.

### `DevicePath`

A NULL-terminated string that contains the device interface path. This path can be passed to Win32 functions such as [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

## Remarks

An SP_DEVICE_INTERFACE_DETAIL_DATA structure identifies the path for a device interface in a device information set.

**SetupDi***Xxx* functions that take an SP_DEVICE_INTERFACE_DETAIL_DATA structure as a parameter verify that the **cbSize** member of the supplied structure is equal to the size, in bytes, of the structure. If the **cbSize** member is not set correctly for an input parameter, the function will fail and set an error code of ERROR_INVALID_PARAMETER. If the **cbSize** member is not set correctly for an output parameter, the function will fail and set an error code of ERROR_INVALID_USER_BUFFER.

> [!NOTE]
> The setupapi.h header defines SP_DEVICE_INTERFACE_DETAIL_DATA as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiGetDeviceInterfaceDetail](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinterfacedetaila)