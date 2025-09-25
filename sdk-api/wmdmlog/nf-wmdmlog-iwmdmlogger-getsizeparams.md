# IWMDMLogger::GetSizeParams

## Description

The **GetSizeParams** method retrieves the current size parameters of the current log file.

## Parameters

### `pdwMaxSize` [out]

Pointer to a buffer that receives the approximate maximum size of the log file. This parameter can be **NULL**.

### `pdwShrinkToSize` [out]

Pointer to a buffer that receives the approximate size to which the log file will be reduced after it reaches the maximum size. This parameter can be **NULL**.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## See also

[Enabling Logging](https://learn.microsoft.com/windows/desktop/WMDM/enabling-logging)

[IWMDMLogger Interface](https://learn.microsoft.com/windows/desktop/api/wmdmlog/nn-wmdmlog-iwmdmlogger)