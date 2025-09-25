# GetFirmwareType function

## Description

Retrieves the firmware type of the local computer.

## Parameters

### `FirmwareType` [in, out]

A pointer to a [FIRMWARE_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-firmware_type) enumeration.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## See also

[FIRMWARE_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-firmware_type)