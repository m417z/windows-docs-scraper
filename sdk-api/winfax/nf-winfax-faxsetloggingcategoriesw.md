# FaxSetLoggingCategoriesW function

## Description

A fax client application calls the **FaxSetLoggingCategories** function to modify the current logging categories for the fax server to which the client has connected. A logging category determines the errors or other events the fax server records in the application event log.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function.

### `Categories` [in]

Type: **const [FAX_LOG_CATEGORY](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_log_categorya)***

Pointer to an array of [FAX_LOG_CATEGORY](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_log_categorya) structures. Each structure contains the data to modify one logging category. The data includes the descriptive name of the logging category, the category number, and the current logging level for the category. For a description of predefined logging categories and logging levels, see the **FAX_LOG_CATEGORY** topic.

### `NumberCategories` [in]

Type: **DWORD**

Specifies a **DWORD** variable that contains the number of [FAX_LOG_CATEGORY](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_log_categorya) structures the function passes in the *Categories* parameter.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or all of the *FaxHandle*, *Categories*, or *NumberCategories* parameters are invalid or **NULL**. |
| **ERROR_INVALID_PARAMETER** | The *FaxHandle* parameter is **NULL**; or the *hWnd* parameter is specified but the *FaxHandle* parameter does not specify a connection with a local fax server; or the *MessageStart* parameter specifies a message in the range below [WM_USER](https://learn.microsoft.com/windows/desktop/winmsg/wm-user). |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_CONFIG_SET](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |
| **ERROR_NOT_ENOUGH_MEMORY** | An error occurred during memory allocation. |

## Remarks

The fax service administration application, a Microsoft Management Console (MMC) snap-in component, typically calls the **FaxSetLoggingCategories** function to modify the current logging categories and logging levels for a fax server. To query the categories and levels, an application can call the [FaxGetLoggingCategories](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetloggingcategoriesa) function. For more information, see [Managing Logging Categories](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-logging-categories).

> [!NOTE]
> The winfax.h header defines FaxSetLoggingCategories as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_LOG_CATEGORY](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_log_categorya)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera)

[FaxGetLoggingCategories](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetloggingcategoriesa)