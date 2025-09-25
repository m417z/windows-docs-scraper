# IWMDMLogger::SetSizeParams

## Description

The **SetSizeParams** method sets the current size parameters for the current log file.

## Parameters

### `dwMaxSize` [in]

The approximate maximum size of the log file. The size of the log file is checked before each log entry is made. Therefore, the log file can grow bigger than the maximum size until the next log entry is made.

### `dwShrinkToSize` [in]

The approximate file size to which the log file should be reduced when the maximum log file size is reached. The log file is generally shrunk to a little smaller than this value so that the file is not split in the middle of a log entry.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

## See also

[Enabling Logging](https://learn.microsoft.com/windows/desktop/WMDM/enabling-logging)

[IWMDMLogger Interface](https://learn.microsoft.com/windows/desktop/api/wmdmlog/nn-wmdmlog-iwmdmlogger)