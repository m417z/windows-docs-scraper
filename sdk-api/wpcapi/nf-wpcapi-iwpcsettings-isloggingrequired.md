# IWPCSettings::IsLoggingRequired

## Description

Determines whether activity logging should be performed when obtaining the [IWPCSettings](https://learn.microsoft.com/windows/desktop/api/wpcapi/nn-wpcapi-iwpcsettings) interface.

## Parameters

### `pfRequired` [out]

Indicates whether logging is required.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_ACCESS_DENIED** | The calling process has insufficient privileges. |
| **E_FILE_NOT_FOUND** | The user settings were not found. |
| **E_FAIL** | The method failed. |

## See also

[IWPCSettings](https://learn.microsoft.com/windows/desktop/api/wpcapi/nn-wpcapi-iwpcsettings)