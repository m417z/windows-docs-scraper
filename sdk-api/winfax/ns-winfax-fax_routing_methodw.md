# FAX_ROUTING_METHODW structure

## Description

The **FAX_ROUTING_METHOD** structure contains information about one fax routing method, as it pertains to one fax device. The data includes, among other items, whether the fax routing method is enabled for the device, and the name of the DLL that exports the routing method. It also includes the GUID and function name that uniquely identify the routing method, and the method's user-friendly name.

## Members

### `SizeOfStruct`

Type: **DWORD**

Specifies the size, in bytes, of the **FAX_ROUTING_METHOD** structure. The fax service sets this member to **sizeof(FAX_ROUTING_METHOD)**.

### `DeviceId`

Type: **DWORD**

Specifies a **DWORD** variable that indicates the permanent line identifier for the fax device of interest.

### `Enabled`

Type: **BOOL**

Specifies a Boolean variable that indicates whether the fax routing method is enabled or disabled for the fax device of interest. If this parameter is equal to **TRUE**, the fax routing method is enabled for the device.

### `DeviceName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the name of the fax device of interest.

### `Guid`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the GUID that uniquely identifies the fax routing method of interest.

For more information about fax routing methods, see [About the Fax Routing Extension API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api).

### `FriendlyName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the user-friendly name to display for the fax routing method.

### `FunctionName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the name of the function that executes the specified fax routing procedure. The fax routing extension DLL identified by the **ExtensionImageName** member exports the function.

### `ExtensionImageName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the name of the fax routing extension DLL that implements the fax routing method.

### `ExtensionFriendlyName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the user-friendly name to display for the fax routing extension DLL.

## Remarks

A fax client application can call the [FaxEnumRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumroutingmethodsa) function to enumerate all the fax routing methods associated with a specific fax device. The function returns an array of **FAX_ROUTING_METHOD** structures. Each structure describes one fax routing method in detail.

Call the [FaxEnableRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenableroutingmethoda) function to enable or disable a fax routing method for a specific fax device.

For more information, see [Managing Fax Routing Data](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-fax-routing-data).

> [!NOTE]
> The winfax.h header defines FAX_ROUTING_METHOD as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Fax Service Client API Structures](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-structures)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxEnableRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenableroutingmethoda)

[FaxEnumRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumroutingmethodsa)

[FaxRouteMethod](https://learn.microsoft.com/windows/desktop/api/faxroute/nc-faxroute-pfaxroutemethod)