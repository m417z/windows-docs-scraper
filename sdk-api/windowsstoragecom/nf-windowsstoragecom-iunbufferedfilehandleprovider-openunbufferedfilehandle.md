# IUnbufferedFileHandleProvider::OpenUnbufferedFileHandle

## Description

Gets a handle from a random-access byte stream that the [StorageFile.OpenAsync](https://learn.microsoft.com/uwp/api/windows.storage.storagefile.openasync) method created and registers a callback method that you want to run when the opportunistic lock for the handle is broken.

## Parameters

### `oplockBreakCallback` [in]

An interface that contains the implementation of the [IUnbufferedFileHandleOplockCallback::OnBrokenCallback](https://learn.microsoft.com/windows/desktop/api/windowsstoragecom/nf-windowsstoragecom-iunbufferedfilehandleoplockcallback-onbrokencallback) method that you want to run when the opportunistic lock for the handle is broken.

### `fileHandle` [out, retval]

The handle from the random-access byte stream.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IUnbufferedFileHandleProvider::OpenUnbufferedFileHandle** opens a new handle that is open for GENERIC_READ. **IUnbufferedFileHandleProvider::OpenUnbufferedFileHandle** does not return the actual handle underlying the stream, or a duplicate of that handle.

 Call [IUnbufferedFileHandleProvider::CloseUnbufferedFileHandle](https://learn.microsoft.com/windows/desktop/api/windowsstoragecom/nf-windowsstoragecom-iunbufferedfilehandleprovider-closeunbufferedfilehandle) when you no longer need the handle. The handle is also closed when the opportunistic lock breaks, so your code must process exceptions that occur when the handle is not valid.

## See also

[IRandomAccessStream](https://learn.microsoft.com/previous-versions/hh438400(v=vs.85))

[IUnbufferedFileHandleOplockCallback](https://learn.microsoft.com/windows/desktop/api/windowsstoragecom/nn-windowsstoragecom-iunbufferedfilehandleoplockcallback)

[IUnbufferedFileHandleOplockCallback::OnBrokenCallback](https://learn.microsoft.com/windows/desktop/api/windowsstoragecom/nf-windowsstoragecom-iunbufferedfilehandleoplockcallback-onbrokencallback)

[IUnbufferedFileHandleProvider](https://learn.microsoft.com/windows/desktop/api/windowsstoragecom/nn-windowsstoragecom-iunbufferedfilehandleprovider)

[IUnbufferedFileHandleProvider::CloseUnbufferedFileHandle](https://learn.microsoft.com/windows/desktop/api/windowsstoragecom/nf-windowsstoragecom-iunbufferedfilehandleprovider-closeunbufferedfilehandle)