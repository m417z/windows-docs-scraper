# FaxGetConfigurationA function

## Description

The **FaxGetConfiguration** function returns to a fax client application the global configuration settings for the fax server to which the client has connected. The data includes, among other items, retransmission, branding, archive and cover page settings; discount rate periods; and the status of the fax server queue.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function.

### `FaxConfig` [out]

Type: **PFAX_CONFIGURATION***

Pointer to the address of a buffer to receive a [FAX_CONFIGURATION](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_configurationa) structure. The structure contains the current configuration settings for the fax server. For information about memory allocation, see the following Remarks section.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or both of the *FaxConfig* or *FaxHandle* parameters are **NULL**. |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_CONFIG_QUERY](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |
| **ERROR_NOT_ENOUGH_MEMORY** | An error occurred during memory allocation. |

## Remarks

A fax administration application typically calls the **FaxGetConfiguration** function to display the global configuration settings for the fax server. To change the configuration settings, call the [FaxSetConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetconfigurationa) function.

The **FaxGetConfiguration** function allocates the memory required for the [FAX_CONFIGURATION](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_configurationa) buffer pointed to by the *FaxConfig* parameter. An application must call the [FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer) function to deallocate the resources associated with this parameter.

For more information, see [Fax Server Configuration Management](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-server-configuration-management) and [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

> [!NOTE]
> The winfax.h header defines FaxGetConfiguration as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_CONFIGURATION](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_configurationa)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera)

[FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer)

[FaxSetConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetconfigurationa)