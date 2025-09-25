# FAX_GLOBAL_ROUTING_INFOW structure

## Description

The **FAX_GLOBAL_ROUTING_INFO** structure contains information about one fax routing method, as it pertains globally to the fax service. The structure includes data on the priority level of the fax routing method, and the name of the DLL that exports the routing method. It also includes the GUID and function name that identify the fax routing method, and the method's user-friendly name.

The **Guid** member is required to identify the fax routing method. Currently the **Priority** member is the only member that an application can modify.

## Members

### `SizeOfStruct`

Type: **DWORD**

Specifies the size, in bytes, of the **FAX_GLOBAL_ROUTING_INFO** structure. The calling application must set this member to **sizeof(FAX_GLOBAL_ROUTING_INFO)** before it calls the [FaxSetGlobalRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetglobalroutinginfoa) function.

### `Priority`

Type: **DWORD**

Specifies a **DWORD** variable that indicates the priority of the fax routing method. The priority determines the relative order in which the fax service calls the fax routing methods when the service receives a fax document. Valid values for this member are 1 through n, where 1 is the highest priority.

### `Guid`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the GUID that uniquely identifies the fax routing method of interest.

For more information about fax routing methods, see [About the Fax Routing Extension API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api).

### `FriendlyName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the user-friendly name to display for the fax routing method.

### `FunctionName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the name of the function that executes the specified fax routing method. The fax routing extension DLL identified by the **ExtensionImageName** member exports the function.

### `ExtensionImageName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the name of the fax routing extension DLL that implements the fax routing method.

### `ExtensionFriendlyName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the user-friendly name to display for the fax routing extension DLL that implements the fax routing method.

## Remarks

A fax client application can call the [FaxEnumGlobalRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumglobalroutinginfoa) function to retrieve fax routing method information that applies globally to the fax service. The function returns information about each fax routing method in an individual **FAX_GLOBAL_ROUTING_INFO** structure.

Call the [FaxSetGlobalRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetglobalroutinginfoa) function to modify fax routing method data that applies globally to the fax server, such as routing priority.

For more information, see [Managing Global Fax Routing Data](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-global-fax-routing-data).

> [!NOTE]
> The winfax.h header defines FAX_GLOBAL_ROUTING_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Fax Service Client API Structures](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-structures)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxEnableRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenableroutingmethoda)

[FaxEnumGlobalRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumglobalroutinginfoa)

[FaxEnumRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumroutingmethodsa)

[FaxRouteMethod](https://learn.microsoft.com/windows/desktop/api/faxroute/nc-faxroute-pfaxroutemethod)

[FaxSetGlobalRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetglobalroutinginfoa)