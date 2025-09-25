# IWMDMLogger::GetLogFileName

## Description

The **GetLogFileName** method returns the full path to the current log file.

## Parameters

### `pszFilename` [out]

Pointer to a buffer to receive the log file name.

### `nMaxChars` [in]

Specifies the size of the *pszFilename* buffer. This is the maximum number of characters that can be placed in the buffer, including the terminating **NULL** character.

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