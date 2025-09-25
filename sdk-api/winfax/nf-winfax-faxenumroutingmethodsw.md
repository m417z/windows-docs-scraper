# FaxEnumRoutingMethodsW function

## Description

The **FaxEnumRoutingMethods** function enumerates all fax routing methods for a specific fax device. The function returns information about each routing method to a fax client application.

## Parameters

### `FaxPortHandle` [in]

Type: **HANDLE**

Specifies a fax port handle returned by a call to the [FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport) function.

### `RoutingMethod` [out]

Type: **PFAX_ROUTING_METHOD***

Pointer to the address of a buffer to receive an array of [FAX_ROUTING_METHOD](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_routing_methoda) structures. Each structure contains information about one fax routing method. The data includes, among other items, the name of the DLL that exports the routing method, the GUID and function name that identify the routing method, and the method's user-friendly name.

For information about memory allocation, see the following Remarks section. For information about fax routing methods, see [About the Fax Routing Extension API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api).

### `MethodsReturned` [out]

Type: **LPDWORD**

Pointer to a **DWORD** variable to receive the number of [FAX_ROUTING_METHOD](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_routing_methoda) structures the **FaxEnumRoutingMethods** function returns in the *RoutingMethod* parameter.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_PORT_QUERY](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |
| **ERROR_INVALID_PARAMETER** | One or all of the *MethodsReturned*, *RoutingMethod*, or *FaxPortHandle* parameters are **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | An error occurred during memory allocation. |

## Remarks

A fax administration application typically calls the **FaxEnumRoutingMethods** function to query the fax routing methods associated with a particular device. A call to the [FaxSetRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetroutinginfoa) function changes the routing information for a particular fax routing method.

The [FaxEnumGlobalRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumglobalroutinginfoa) function retrieves routing information that applies globally to the fax server, such as routing priority. An application can modify global data with a call to the [FaxSetGlobalRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetglobalroutinginfoa) function.

The **FaxEnumRoutingMethods** function allocates the memory required for the [FAX_ROUTING_METHOD](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_routing_methoda) buffer array pointed to by the *RoutingMethod* parameter. An application must call the [FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer) function to deallocate the resources associated with this parameter.

For more information, see [Fax Server Configuration Management](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-server-configuration-management) and [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

> [!NOTE]
> The winfax.h header defines FaxEnumRoutingMethods as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_GLOBAL_ROUTING_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_global_routing_infoa)

[FAX_ROUTING_METHOD](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_routing_methoda)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxEnableRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenableroutingmethoda)

[FaxEnumGlobalRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumglobalroutinginfoa)

[FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer)

[FaxGetRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetroutinginfoa)

[FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport)

[FaxSetGlobalRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetglobalroutinginfoa)

**FaxSetRoutingInfo**