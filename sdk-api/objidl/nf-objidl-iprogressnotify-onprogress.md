# IProgressNotify::OnProgress

## Description

Notifies registered objects and applications of the progress of a downloading operation.

## Parameters

### `dwProgressCurrent` [in]

The amount of data available.

### `dwProgressMaximum` [in]

The total amount of data to be downloaded.

### `fAccurate` [in]

Indicates the accuracy of the values in *dwProgressCurrent* and *dwProgressMaximum*. They are either reliable (**TRUE**) or unreliable (**FALSE**). The **FALSE** value indicates that control structures for determining the actual position of, or amount of, data yet to be downloaded are not available.

### `fOwner` [in]

Indicates whether this **OnProgress** call can control the blocking behavior of the operation. If **TRUE**, the caller can use return values from **OnProgress** to block (STG_S_BLOCK), retry (STG_S_RETRYNOW), or monitor (STG_S_MONITORING) the operation. If **FALSE**, the return value from **OnProgress** has no influence on blocking behavior.

## Return value

This method can return the standard return values E_FAIL, E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **STG_S_RETRYNOW** | The caller is to retry the operation immediately. (This value is most useful for applications that do blocking from within the callback routine.) |
| **STG_S_BLOCK** | The caller is to block the download and retry the call as needed to determine if additional data is available. This is the default behavior if no sinks are registered on the connection point. |
| **STG_S_MONITORING** | The callback recipient relinquishes control of the downloading process to one of the other objects or applications that have registered progress notification sinks on the same stream. This is useful if the notification sink is interested only in gathering statistics. |
| **E_PENDING** | Data is currently unavailable. The caller is to try again after some desired interval. The notification sink returns this value if the asynchronous storage is to operate in nonblocking mode. |

## Remarks

Sinks may be inherited by any substorage or substream of a given storage. If no sink is registered, the thread will block until the requested data becomes available, or the download is canceled by the downloader.

Where multiple objects or applications have registered progress notification sinks on a single stream, only one of them can control the behavior of a download. Ownership of the download goes to the first sink to register with the storage or stream, or any advise skinks that may have been inherited from the parent storage (if the storage was created with ASYNC_MODE_COMPATIBILITY.)

Any one of the sinks can relinquish control to the next connection point by returning STG_S_MONITORING to the connection point making the current caller. After a connection point obtains control (through receiving STG_S_BLOCK or STG_S_RETRYNOW), all subsequent connection points calling **OnProgress** will set *fOwner* to **FALSE**.

## See also

[IProgressNotify](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iprogressnotify)