# FaxRegisterRoutingExtensionW function

## Description

The **FaxRegisterRoutingExtension** function registers a fax routing extension DLL with the fax service. The function configures the fax service registry to use the new routing extension DLL.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function.

### `ExtensionName` [in]

Type: **LPCWSTR**

Specifies a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function.

### `FriendlyName` [in]

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string to associate with the fax routing extension DLL. This is the routing extension's user-friendly name, suitable for display.

### `ImageName` [in]

Type: **LPCWSTR**

Pointer to a constant null-terminated Unicode character string that specifies the full path and file name for the fax routing extension DLL. The path can include valid environment variables, for example, %SYSTEMDRIVE% and %SYSTEMROOT%.

### `CallBack` [in]

Type: **PFAX_ROUTING_INSTALLATION_CALLBACK**

Pointer to a [FaxRoutingInstallationCallback](https://learn.microsoft.com/windows/desktop/api/winfax/nc-winfax-pfax_routing_installation_callbackw) function that installs a fax routing method for the specified fax routing extension DLL. The **FaxRegisterRoutingExtension** function calls the **FaxRoutingInstallationCallback** function multiple times, until it returns a value of zero, indicating that all routing methods in the fax routing extension DLL have been registered.

### `Context` [in]

Type: **LPVOID**

Pointer to a variable that contains application-specific context information or an application-defined value. **FaxRegisterRoutingExtension** passes this data to the [FaxRoutingInstallationCallback](https://learn.microsoft.com/windows/desktop/api/winfax/nc-winfax-pfax_routing_installation_callbackw) function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | At least one parameter to the [FaxRegisterRoutingExtension](https://learn.microsoft.com/windows/desktop/api/winfax/nf-winfax-faxregisterroutingextensionw) function is **NULL**. |
| **ERROR_INVALID_FUNCTION** | The *FaxHandle* specifies a remote fax server connection. |

## Remarks

**FaxRegisterRoutingExtension** calls the [FaxRoutingInstallationCallback](https://learn.microsoft.com/windows/desktop/api/winfax/nc-winfax-pfax_routing_installation_callbackw) function once for each fax routing method in the fax routing extension DLL.

Because the **FaxRegisterRoutingExtension** function modifies the registry, the user, generally a system administrator, must have write access to the **HKEY_LOCAL_MACHINE** registry key.

**Note** **FaxRegisterRoutingExtension** has only Unicode and local versions.

All parameters to the **FaxRegisterRoutingExtension** function are required.

You must restart the fax service to use a fax routing method exported by a fax routing extension you install using **FaxRegisterRoutingExtension**.

For more information about the steps required to register with the fax service, see [Registration of a Fax Routing Extension](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-registration-of-a-fax-routing-extension).

## See also

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera)

[FaxRoutingInstallationCallback](https://learn.microsoft.com/windows/desktop/api/winfax/nc-winfax-pfax_routing_installation_callbackw)