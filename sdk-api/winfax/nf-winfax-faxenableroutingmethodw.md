# FaxEnableRoutingMethodW function

## Description

The **FaxEnableRoutingMethod** function enables or disables a fax routing method for a specific fax device. A fax administration application typically calls this function for device management.

## Parameters

### `FaxPortHandle` [in]

Type: **HANDLE**

Specifies a fax port handle returned by a call to the [FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport) function.

### `RoutingGuid` [in]

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the GUID that uniquely identifies the fax routing method of interest.

For information about fax routing methods, see [About the Fax Routing Extension API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api). For information about the relationship between routing methods and GUIDs, see [Fax Routing Methods](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-routing-methods).

### `Enabled` [in]

Type: **BOOL**

Specifies a Boolean variable that indicates whether the application is enabling or disabling the fax routing method specified by the *RoutingGuid* parameter. If this parameter is **TRUE**, the application is enabling the routing method; if this parameter is **FALSE**, the application is disabling the routing method.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or both of the *FaxPortHandle* or *RoutingGuid* parameters are **NULL**. |
| **ERROR_INVALID_DATA** | The *RoutingGuid* parameter is invalid. |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_PORT_SET](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |

## Remarks

A fax client application can call the **FaxEnableRoutingMethod** function to enable a fax routing method for a particular fax device. It can also call the function to disable a routing method enabled by a prior call to **FaxEnableRoutingMethod** or by the fax service administration application. For more information, see [Managing Fax Routing Data](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-fax-routing-data).

Call the [FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport) function to obtain a valid port handle to specify in the *FaxPortHandle* parameter.

> [!NOTE]
> The winfax.h header defines FaxEnableRoutingMethod as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxEnumRoutingMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumroutingmethodsa)

[FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport)

[FaxRouteMethod](https://learn.microsoft.com/windows/desktop/api/faxroute/nc-faxroute-pfaxroutemethod)