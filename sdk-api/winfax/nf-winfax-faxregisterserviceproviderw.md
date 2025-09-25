# FaxRegisterServiceProviderW function

## Description

The **FaxRegisterServiceProvider** function registers a fax service provider DLL with the fax service. The function configures the fax service registry to query and use the new fax service provider DLL when the fax service restarts.

## Parameters

### `DeviceProvider` [in]

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string that specifies the internal name of the fax service provider DLL to register. This should be a unique string, such as a GUID.

### `FriendlyName` [in]

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string to associate with the fax service provider DLL. This is the fax service provider's user-friendly name, suitable for display.

### `ImageName` [in]

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string that specifies the full path and file name for the fax service provider DLL. The path can include valid environment variables, for example, %SYSTEMDRIVE% and %SYSTEMROOT%.

### `TspName` [in]

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string that specifies the name of the telephony service provider associated with the devices for the fax service provider. For a virtual fax device, use an empty string.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | At least one parameter to the [FaxRegisterServiceProvider](https://learn.microsoft.com/windows/desktop/api/winfax/nf-winfax-faxregisterserviceproviderw) function is **NULL**. |

## Remarks

Because the **FaxRegisterServiceProvider** function modifies the registry, the user, generally a system administrator, must have write access to the **HKEY_LOCAL_MACHINE** registry key.

All parameters to the **FaxRegisterServiceProvider** function are required.

Local installation of a fax service provider is recommended. The local installation routine for a fax service provider DLL can call **FaxRegisterServiceProvider** instead of directly accessing the registry. For more information about the steps required to register locally with the fax service, see [Registration of a Fax Service Provider](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-registration-of-a-fax-service-provider).

## See also

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera)