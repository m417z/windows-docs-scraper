# PFAX_ROUTING_INSTALLATION_CALLBACKW callback function

## Description

The *FaxRoutingInstallationCallback* function is a library-defined callback function that the [FaxRegisterRoutingExtension](https://learn.microsoft.com/windows/desktop/api/winfax/nf-winfax-faxregisterroutingextensionw) function calls to install a fax routing extension DLL. **FaxRegisterRoutingExtension** calls the *FaxRoutingInstallationCallback* function multiple times, once for each fax routing method the fax routing extension exports.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function.

### `Context` [in]

Type: **LPVOID**

Pointer to a variable that contains application-specific context information or an application-defined value. The [FaxRegisterRoutingExtension](https://learn.microsoft.com/windows/desktop/api/winfax/nf-winfax-faxregisterroutingextensionw) function passes this data to the *FaxRoutingInstallationCallback* function.

### `MethodName` [out]

Type: **LPWSTR**

Pointer to a variable to receive a null-terminated Unicode character string that specifies the internal name of the fax routing method. The string must not exceed 100 characters. For information about fax routing methods, see [About the Fax Routing Extension API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api).

### `FriendlyName` [out]

Type: **LPWSTR**

Pointer to a variable to receive a null-terminated Unicode character string that specifies the user-friendly name to display for the fax routing method. The string must not exceed 100 characters.

### `FunctionName` [out]

Type: **LPWSTR**

Pointer to a variable to receive a null-terminated Unicode character string. The string contains the name of the exported function that executes the specified fax routing procedure. The string must not exceed 100 characters.

### `Guid` [out]

Type: **LPWSTR**

Pointer to a variable to receive a null-terminated Unicode character string. The string specifies the GUID that uniquely identifies the fax routing method of interest.

## Return value

Type: **BOOL**

The *FaxRoutingInstallationCallback* function returns a value of nonzero to indicate that the [FaxRegisterRoutingExtension](https://learn.microsoft.com/windows/desktop/api/winfax/nf-winfax-faxregisterroutingextensionw) function should register the fax routing method for the fax routing extension, using the data pointed to by the parameters.

The function returns a value of zero to indicate that there are no more fax routing methods to register, and calls to *FaxRoutingInstallationCallback* should be terminated.

## Remarks

The **PFAX_ROUTING_INSTALLATION_CALLBACKW** data type is a pointer to a *FaxRoutingInstallationCallback* function.

A fax client application specifies the *FaxRoutingInstallationCallback* function by passing its address when it calls the [FaxRegisterRoutingExtension](https://learn.microsoft.com/windows/desktop/api/winfax/nf-winfax-faxregisterroutingextensionw) function. For more information, see [Registration of a Fax Routing Extension](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-registration-of-a-fax-routing-extension).

For information about fax routing extensions, see [About the Fax Routing Extension API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api).

## See also

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera)

[FaxRegisterRoutingExtension](https://learn.microsoft.com/windows/desktop/api/winfax/nf-winfax-faxregisterroutingextensionw)