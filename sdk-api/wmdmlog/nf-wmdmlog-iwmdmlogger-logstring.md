# IWMDMLogger::LogString

## Description

The **LogString** method logs a string to the current log file. A carriage return and line feed are added to each log entry.

## Parameters

### `dwFlags` [in]

Flags that control the way a string is logged. This parameter is a combination of one or more of the following values.

| Value | Description |
| --- | --- |
| WMDM_LOG_SEV_INFO | Tag the log entry as informational. |
| WMDM_LOG_SEV_WARN | Tag the log entry as a warning. |
| WMDM_LOG_SEV_ERROR | Tag the log entry as an error. |
| WMDM_LOG_NOTIMESTAMP | Do not include a time stamp on the log entry. Time stamps are in ISO format minus the time-zone information. |

### `pszSrcName` [in]

Pointer to a string containing the name of the module that is making the log entry. This parameter can be **NULL**.

### `pszLog` [in]

Pointer to a string to be copied to the log. This parameter can be **NULL**.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## See also

[Enabling Logging](https://learn.microsoft.com/windows/desktop/WMDM/enabling-logging)

[IWMDMLogger Interface](https://learn.microsoft.com/windows/desktop/api/wmdmlog/nn-wmdmlog-iwmdmlogger)