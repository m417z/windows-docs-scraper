# FaxGetLoggingCategoriesA function

## Description

The **FaxGetLoggingCategories** function returns to a fax client application the current logging categories for the fax server to which the client has connected. A logging category determines the errors or other events the fax server records in the application event log.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function.

### `Categories` [out]

Type: **PFAX_LOG_CATEGORY***

Pointer to the address of a buffer to receive an array of [FAX_LOG_CATEGORY](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_log_categorya) structures. Each structure describes one current logging category. The data includes the descriptive name of the logging category, the category number, and the current logging level.

For a description of predefined logging categories and logging levels, see the [FAX_LOG_CATEGORY](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_log_categorya) topic. For information about memory allocation, see the following Remarks section.

### `NumberCategories` [out]

Type: **LPDWORD**

Pointer to a **DWORD** variable to receive the number of [FAX_LOG_CATEGORY](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_log_categorya) structures the function returns in the *Categories* parameter.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_CONFIG_QUERY](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |
| **ERROR_INVALID_PARAMETER** | One or all of the *Categories*, *NumberCategories*, or *FaxHandle* parameters are **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | An error occurred during memory allocation. |

## Remarks

A fax client application typically calls the **FaxGetLoggingCategories** function to query the current logging categories and logging levels for a fax server. To modify the current logging categories and levels, call the [FaxSetLoggingCategories](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetloggingcategoriesa) function.

The **FaxGetLoggingCategories** function allocates the memory required for the [FAX_LOG_CATEGORY](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_log_categorya) buffer array pointed to by the *Categories* parameter. An application must call the [FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer) function to deallocate the resources associated with this parameter.

For more information, see [Managing Logging Categories](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-logging-categories) and [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

> [!NOTE]
> The winfax.h header defines FaxGetLoggingCategories as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_LOG_CATEGORY](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_log_categorya)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera)

[FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer)

[FaxSetLoggingCategories](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetloggingcategoriesa)