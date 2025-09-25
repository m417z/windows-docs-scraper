# GetServiceKeyNameA function

## Description

Retrieves the service name of the specified service.

## Parameters

### `hSCManager` [in]

A handle to the computer's service control manager database, as returned by
[OpenSCManager](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openscmanagera).

### `lpDisplayName` [in]

The service display name. This string has a maximum length of 256 characters.

### `lpServiceName` [out, optional]

A pointer to a buffer that receives the service name. If the function fails, this buffer will contain an empty string.

The maximum size of this array is 4K bytes. To determine the required size, specify NULL for this parameter and 0 for the *lpcchBuffer* parameter. The function will fail and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return **ERROR_INSUFFICIENT_BUFFER**. The *lpcchBuffer* parameter will receive the required size.

### `lpcchBuffer` [in, out]

A pointer to variable that specifies the size of the buffer pointed to by the *lpServiceName* parameter, in **TCHARs**. When the function returns, this parameter contains the size of the service name, in **TCHARs**, excluding the null-terminating character.

If the buffer pointed to by *lpServiceName* is too small to contain the service name, the function stores no data in it. When the function returns, *lpcchBuffer* contains the size of the service name, excluding the NULL terminator.

## Return value

If the functions succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

There are two names for a service: the service name and the display name. The service name is the name of the service's key in the registry. The display name is a user-friendly name that appears in the Services control panel application, and is used with the **NET START** command. Both names are specified with the [CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function and can be modified with the [ChangeServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfiga) function. Information specified for a service is stored in a key with the same name as the service name under the **HKEY_LOCAL_MACHINE**\**System**\**CurrentControlSet**\**Services**\*ServiceName* registry key.

To map the service name to the display name, use the
[GetServiceDisplayName](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-getservicedisplaynamea) function. To map the display name to the service name, use the
**GetServiceKeyName** function.

> [!NOTE]
> The winsvc.h header defines GetServiceKeyName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetServiceDisplayName](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-getservicedisplaynamea)

[OpenSCManager](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openscmanagera)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)