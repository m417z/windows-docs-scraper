# IUpdateDownloader::BeginDownload

## Description

Starts an asynchronous download of the content files that are associated with the updates.

## Parameters

### `onProgressChanged` [in]

An [IDownloadProgressChangedCallback](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadprogresschangedcallback) interface that is called periodically for download progress changes before download is complete.

### `onCompleted` [in]

An [IDownloadCompletedCallback](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadcompletedcallback) interface (C++/COM) that is called when an asynchronous download operation is complete.

### `state` [in]

The caller-specific state that the [AsyncState](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-idownloadjob-get_asyncstate) property of the [IDownloadJob](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadjob) interface returns. A caller may use this parameter to attach a value to the download job object. This allows the caller to retrieve custom information about that download job object at a later time.

**Note**

The [AsyncState](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-idownloadjob-get_asyncstate) property of the [IDownloadJob](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadjob) interface can be retrieved, but it cannot be set. This does not prevent the caller from changing the contents of the object already set to the **AsyncState** property of the **IDownloadJob** interface. In other words, if the **AsyncState** property contains a number, the number cannot be changed. But, if the **AsyncState** property contains a safe array or an object, the contents of the safe array or the object can be changed at will. The value is released when the caller releases **IDownloadJob** by calling [IUpdateDownloader::EndDownload](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatedownloader-enddownload).

### `retval` [out]

An [IDownloadJob](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadjob) interface that contains the properties and methods that are available to a download operation that has started.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **WU_E_INVALID_OPERATION** | The computer cannot access the update site. |
| **WU_E_NO_UPDATE** | The Windows Update Agent (WUA) does not have updates in the collection. |
| **WU_E_NOT_INITIALIZED** | The Windows Update Agent (WUA) is not initialized. |

## Remarks

 As an alternative to implementing the [IDownloadProgressChangedCallback](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadprogresschangedcallback) interface, you can use a script to implement a callback routine of any identifier with DISPID 0 on an automation object. The type of the *onProgressChanged* parameter is **IUnknown***.

 As an alternative to implementing the [IDownloadCompletedCallback](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-idownloadcompletedcallback) interface, you can use a script to implement a callback routine of any identifier with DISPID 0 on an automation object. The type of the *onCompleted* parameter is **IUnknown***.

This method returns **WU_E_INVALID_OPERATION** if the object that is implementing the interface is locked down.

This method returns **WU_E_NO_UPDATE** if the [Updates](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatedownloader-get_updates) property of the [IUpdateDownloader](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatedownloader) interface is not set. This method also returns WU_E_NO_UPDATE if the **Updates** property is set to an empty collection.

This method returns **SUS_E_NOT_INITIALIZED** if the download job contains no updates.

When you use any asynchronous WUA API in your app, you might need to implement a time-out mechanism. For more info about how to perform asynchronous WUA operations, see [Guidelines for Asynchronous WUA Operations](https://learn.microsoft.com/windows/desktop/Wua_Sdk/guidelines-for-asynchronous-wua-operations).

## See also

[IUpdateDownloader](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatedownloader)