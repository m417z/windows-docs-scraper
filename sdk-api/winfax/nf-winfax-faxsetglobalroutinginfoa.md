# FaxSetGlobalRoutingInfoA function

## Description

A fax management application calls the **FaxSetGlobalRoutingInfo** function to modify fax routing method data, such as routing priority, that applies globally to the fax server.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function.

### `RoutingInfo` [in]

Type: **const [FAX_GLOBAL_ROUTING_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_global_routing_infoa)***

Pointer to a buffer that contains a [FAX_GLOBAL_ROUTING_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_global_routing_infoa) structure.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_CONFIG_SET](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |
| **ERROR_INVALID_DATA** | The **Guid** member of the specified [FAX_GLOBAL_ROUTING_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_global_routing_infoa) structure does not correspond to an installed fax routing method. |
| **ERROR_INVALID_PARAMETER** | One or both of the *FaxHandle* or *RoutingInfo* parameters are invalid. |

## Remarks

An application such as the fax service administration application, a Microsoft Management Console (MMC) snap-in component that manages the specified fax routing method, typically calls the **FaxSetGlobalRoutingInfo** function.

To retrieve the current global configuration, call the [FaxEnumGlobalRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumglobalroutinginfoa) function. Call the [FaxEnumRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumroutingmethodsa) function to enumerate the fax routing methods associated with a particular device. For more information, see [Managing Fax Routing Data](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-fax-routing-data).

> [!NOTE]
> The winfax.h header defines FaxSetGlobalRoutingInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_GLOBAL_ROUTING_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_global_routing_infoa)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxEnumGlobalRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumglobalroutinginfoa)

[FaxEnumRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumroutingmethodsa)