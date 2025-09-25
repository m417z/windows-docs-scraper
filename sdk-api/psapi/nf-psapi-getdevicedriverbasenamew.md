# GetDeviceDriverBaseNameW function

## Description

Retrieves the base name of the specified device driver.

## Parameters

### `ImageBase` [in]

The load address of the device driver. This value can be retrieved using the
[EnumDeviceDrivers](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumdevicedrivers)
function.

### `lpBaseName` [out]

A pointer to the buffer that receives the base name of the device driver.

### `nSize` [in]

The size of the *lpBaseName* buffer, in characters. If the buffer is not large enough to store the base name plus the terminating null character, the string is truncated.

## Return value

If the function succeeds, the return value specifies the length of the string copied to the buffer, not including any terminating null character.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Starting with Windows 7 and Windows Server 2008 R2, Psapi.h establishes version numbers for the PSAPI functions. The PSAPI version number affects the name used to call the function and the library that a program must load.

If PSAPI_VERSION is 2 or greater, this function is defined as **K32GetDeviceDriverBaseName** in Psapi.h and exported in Kernel32.lib and Kernel32.dll. If PSAPI_VERSION is 1, this function is defined as **GetDeviceDriverBaseName** in Psapi.h and exported in Psapi.lib and Psapi.dll as a wrapper that calls **K32GetDeviceDriverBaseName**.

Programs that must run on earlier versions of Windows as well as Windows 7 and later versions should always call this function as **GetDeviceDriverBaseName**. To ensure correct resolution of symbols, add Psapi.lib to the TARGETLIBS macro and compile the program with –DPSAPI_VERSION=1. To use run-time dynamic linking, load Psapi.dll.

#### Examples

For an example, see
[Enumerating all Device Drivers in the System](https://learn.microsoft.com/windows/desktop/psapi/enumerating-all-device-drivers-in-the-system).

> [!NOTE]
> The psapi.h header defines GetDeviceDriverBaseName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Device Driver Information](https://learn.microsoft.com/windows/desktop/psapi/device-driver-information)

[EnumDeviceDrivers](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumdevicedrivers)

[PSAPI Functions](https://learn.microsoft.com/windows/desktop/psapi/psapi-functions)