# IUPnPAsyncResult::AsyncOperationComplete

## Description

The **AsyncOperationComplete** callback method provides notification of the completion of an asynchronous I/O operation.

## Parameters

### `ullRequestID`

The handle identifier corresponding to the completed asynchronous I/O operation.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h

## See also

[IUPnPAsyncResult](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpasyncresult)