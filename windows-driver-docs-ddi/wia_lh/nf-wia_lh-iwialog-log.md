## Description

The **IWiaLog::Log** method is obsolete and is no longer supported. Use the [**Diagnostic Log Macros**](https://learn.microsoft.com/windows-hardware/drivers/image/wia-diagnostic-log-macros) instead.

The **IWiaLog::Log** method writes a diagnostic log message to *Wiaservc.log*.

## Parameters

### `lFlags` [in]

Specifies the type of diagnostic message. This parameter can be WIALOG_TRACE, WIALOG_WARNING or WIALOG_ERROR.

### `lResID` [in]

Specifies the resource id. This parameter should be set to WIALOG_NO_RESOURCE_ID.

### `lDetail`

Specifies the diagnostic detail level of the message. This parameter can be one of the following values.

| Level | Description |
|---|---|
| WIALOG_LEVEL1 | Logs entry and exit points for all WIA methods and functions. |
| WIALOG_LEVEL2 | Logs additional details for WIALOG_LEVEL1. |
| WIALOG_LEVEL3 | Logs entry and exit points for all WIA methods and functions and additional vendor-supplied functions. |
| WIALOG_LEVEL4 | Logs additional details for WIALOG_LEVEL3. |
| WIALOG_LEVELXXX | User-defined log levels. |

### `bstrText` [in]

Specifies the error text. The error text should be prefixed with the full name of the method or function and generate the message in the format of "class::method, error-text".

## Return value

If the method succeeds, it returns S_OK. If the method fails, it returns a standard COM error code.