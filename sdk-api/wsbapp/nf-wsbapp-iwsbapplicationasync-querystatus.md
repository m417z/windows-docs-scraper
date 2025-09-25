# IWsbApplicationAsync::QueryStatus

## Description

Queries the status of an asynchronous operation.

## Parameters

### `phrResult` [out]

The address of an **HRESULT** value that receives the status of the current asynchronous operation. If the asynchronous operation fails, this parameter receives the failure status code. Possible values include the following.

#### S_OK (0)

The asynchronous operation was completed successfully.

#### WSBAPP_ASYNC_IN_PROGRESS (0x407A0004L)

The asynchronous operation is still running.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

Windows Server Backup calls this method periodically to query the status of a pending asynchronous operation.

## See also

[IWsbApplicationAsync](https://learn.microsoft.com/previous-versions/windows/desktop/api/wsbapp/nn-wsbapp-iwsbapplicationasync)