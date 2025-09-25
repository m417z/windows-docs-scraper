# EnumDeviceDrivers function

## Description

Retrieves the load address for each device driver in the system.

## Parameters

### `lpImageBase` [out]

An array that receives the list of load addresses for the device drivers.

### `cb` [in]

The size of the *lpImageBase* array, in bytes. If the array is not large enough to store the load addresses, the *lpcbNeeded* parameter receives the required size of the array.

### `lpcbNeeded` [out]

The number of bytes returned in the *lpImageBase* array.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To determine how many device drivers were enumerated by the call to
**EnumDeviceDrivers**, divide the resulting value in the *lpcbNeeded* parameter by `sizeof(LPVOID)`.

Starting with Windows 7 and Windows Server 2008 R2, Psapi.h establishes version numbers for the PSAPI functions. The PSAPI version number affects the name used to call the function and the library that a program must load.

If PSAPI_VERSION is 2 or greater, this function is defined as **K32EnumDeviceDrivers** in Psapi.h and exported in Kernel32.lib and Kernel32.dll. If PSAPI_VERSION is 1, this function is defined as **EnumDeviceDrivers** in Psapi.h and exported in Psapi.lib and Psapi.dll as a wrapper that calls **K32EnumDeviceDrivers**.

Programs that must run on earlier versions of Windows as well as Windows 7 and later versions should always call this function as **EnumDeviceDrivers**. To ensure correct resolution of symbols, add Psapi.lib to the TARGETLIBS macro and compile the program with –DPSAPI_VERSION=1. To use run-time dynamic linking, load Psapi.dll.

Starting in Windows 11 Version 24H2, **EnumDeviceDrivers** will require **SeDebugPrivilege** to return valid *ImageBase* values. The function will still succeed if the caller does not have this privilege enabled, but the returned *lpImageBase* array will contain addresses that are all NULL.

#### Examples

For an example, see [Enumerating all Device Drivers in the System](https://learn.microsoft.com/windows/desktop/psapi/enumerating-all-device-drivers-in-the-system).

## See also

[Device Driver Information](https://learn.microsoft.com/windows/desktop/psapi/device-driver-information)

[GetDeviceDriverBaseName](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getdevicedriverbasenamea)

[GetDeviceDriverFileName](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getdevicedriverfilenamea)

[PSAPI Functions](https://learn.microsoft.com/windows/desktop/psapi/psapi-functions)