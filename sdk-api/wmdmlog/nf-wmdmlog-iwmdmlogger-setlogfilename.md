# IWMDMLogger::SetLogFileName

## Description

The **SetLogFileName** method sets the full path to the current log file. All subsequent log entries will be placed in this file.

## Parameters

### `pszFilename` [in]

Pointer to a string that is the full path to the new log file. Note that this is not a wide-character string.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The default log file is < *Windows directory* >\System32\Wmdm.log.

## See also

[Enabling Logging](https://learn.microsoft.com/windows/desktop/WMDM/enabling-logging)

[IWMDMLogger Interface](https://learn.microsoft.com/windows/desktop/api/wmdmlog/nn-wmdmlog-iwmdmlogger)