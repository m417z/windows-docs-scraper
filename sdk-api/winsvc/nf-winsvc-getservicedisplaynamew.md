# GetServiceDisplayNameW function

## Description

Retrieves the display name of the specified service.

## Parameters

### `hSCManager` [in]

A handle to the service control manager database, as returned by the
[OpenSCManager](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openscmanagera) function.

### `lpServiceName` [in]

The service name. This name is the same as the service's registry key name. It is best to choose a name that is less than 256 characters.

### `lpDisplayName` [out, optional]

A pointer to a buffer that receives the service's display name. If the function fails, this buffer will contain an empty string.

The maximum size of this array is 4K bytes. To determine the required size, specify NULL for this parameter and 0 for the *lpcchBuffer* parameter. The function will fail and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return **ERROR_INSUFFICIENT_BUFFER**. The *lpcchBuffer* parameter will receive the required size.

This parameter can specify a localized string using the following format:

@[*path*\]*dllname*,-*strID*

The string with identifier *strID* is loaded from *dllname*; the *path* is optional. For more information, see [RegLoadMUIString](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regloadmuistringa).

**Windows Server 2003 and Windows XP:** Localized strings are not supported until Windows Vista.

### `lpcchBuffer` [in, out]

A pointer to a variable that specifies the size of the buffer pointed to by *lpDisplayName*, in **TCHARs**.

On output, this variable receives the size of the service's display name, in characters, excluding the null-terminating character.

If the buffer pointed to by *lpDisplayName* is too small to contain the display name, the function does not store it. When the function returns, *lpcchBuffer* contains the size of the service's display name, excluding the null-terminating character.

## Return value

If the functions succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

There are two names for a service: the service name and the display name. The service name is the name of the service's key in the registry. The display name is a user-friendly name that appears in the Services control panel application, and is used with the **NET START** command. To map the service name to the display name, use the
**GetServiceDisplayName** function. To map the display name to the service name, use the
[GetServiceKeyName](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-getservicekeynamea) function.

> [!NOTE]
> The winsvc.h header defines GetServiceDisplayName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetServiceKeyName](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-getservicekeynamea)

[OpenSCManager](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openscmanagera)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)