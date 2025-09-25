## Description

Delivery Optimization calls your implementation of this method any time a download status has changed.

## Parameters

### `download`

An pointer to the **IDODownload** interface whose status changed.

### `status`

A pointer to a **DO_DOWNLOAD_STATUS** structure containing the download's status.

## Return value

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

## See also