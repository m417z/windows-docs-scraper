# FaxSetConfigurationW function

## Description

A fax client application calls the **FaxSetConfiguration** function to change the global configuration settings for the fax server to which the client has connected. The configuration data can include, among other items, retransmission, branding, archive and cover page settings; discount rate periods; and the status of the fax server queue.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function.

### `FaxConfig` [in]

Type: **const [FAX_CONFIGURATION](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_configurationa)***

Pointer to a [FAX_CONFIGURATION](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_configurationa) structure. The structure contains data to modify the current fax server configuration settings.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_CONFIG_SET](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_PORT_QUERY](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |
| **ERROR_INVALID_PARAMETER** | The *FaxConfig* parameter is **NULL**, or the **SizeOfStruct** member of the specified [FAX_CONFIGURATION](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_configurationa) structure is not equal to **sizeof(FAX_CONFIGURATION)**. |

## Remarks

A fax administration application typically calls the **FaxSetConfiguration** function to administer the global configuration settings for a fax server. To query the settings, an application can call the [FaxGetConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetconfigurationa) function. For more information, see [Fax Server Configuration Management](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-server-configuration-management).

> [!NOTE]
> The winfax.h header defines FaxSetConfiguration as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_CONFIGURATION](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_configurationa)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera)

[FaxGetConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetconfigurationa)