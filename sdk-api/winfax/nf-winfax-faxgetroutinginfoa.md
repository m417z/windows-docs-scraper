# FaxGetRoutingInfoA function

## Description

The **FaxGetRoutingInfo** function returns to a fax client application routing information for a fax routing method that is associated with a specific fax device.

## Parameters

### `FaxPortHandle` [in]

Type: **HANDLE**

Specifies a fax port handle returned by a call to the [FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport) function.

### `RoutingGuid` [in]

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the GUID that uniquely identifies the fax routing method of interest.

For information about fax routing methods, see [About the Fax Routing Extension API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api). For information about the relationship between routing methods and GUIDs, see [Fax Routing Methods](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-routing-methods).

### `RoutingInfoBuffer` [out]

Type: **LPBYTE***

Pointer to the address of a buffer to receive the fax routing information.

### `RoutingInfoBufferSize` [out]

Type: **LPDWORD**

Pointer to a **DWORD** variable to receive the size of the buffer, in bytes, pointed to by the *RoutingInfoBuffer* parameter.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_PORT_QUERY](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |
| **ERROR_INVALID_PARAMETER** | One or all of the *RoutingGuid*, *RoutingInfoBuffer*, *RoutingInfoBufferSize*, or *FaxPortHandle* parameters are **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | An error occurred during memory allocation. |
| **ERROR_INVALID_DATA** | The *RoutingGuid* parameter is invalid. |

## Remarks

The fax service administration application, a Microsoft Management Console (MMC) snap-in component that manages the specified fax routing method, typically calls the **FaxGetRoutingInfo** function. This is because the format of the routing data is unavailable to a fax client application. The routing data is relevant only to the exported fax routing method and to the fax service administration application.

An application that manages a specific fax routing method can call the **FaxGetRoutingInfo** function to modify the routing information for the method on a specified fax device. To enumerate all fax routing methods associated with a device, call the [FaxEnumRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumroutingmethodsa) function.

The [FaxEnumGlobalRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumglobalroutinginfoa) function retrieves routing information that applies globally to the fax server, such as routing priority. An application can modify global data with a call to the [FaxSetGlobalRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetglobalroutinginfoa) function.

The **FaxGetRoutingInfo** function allocates the memory required for the buffer pointed to by the *RoutingInfoBuffer* parameter. An application must call the [FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer) function to deallocate the resources associated with this parameter.

For more information, see [Managing Fax Routing Data](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-fax-routing-data) and [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

> [!NOTE]
> The winfax.h header defines FaxGetRoutingInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_GLOBAL_ROUTING_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_global_routing_infoa)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxEnumGlobalRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumglobalroutinginfoa)

[FaxEnumRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumroutingmethodsa)

[FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer)

[FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport)

[FaxSetGlobalRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetglobalroutinginfoa)

[FaxSetRoutingInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetroutinginfoa)