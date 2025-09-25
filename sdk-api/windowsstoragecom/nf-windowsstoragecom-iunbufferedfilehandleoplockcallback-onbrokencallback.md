# IUnbufferedFileHandleOplockCallback::OnBrokenCallback

## Description

Runs when the opportunistic lock for a handle that you get by calling the [IUnbufferedFileHandleProvider::OpenUnbufferedFileHandle](https://learn.microsoft.com/windows/desktop/api/windowsstoragecom/nf-windowsstoragecom-iunbufferedfilehandleprovider-openunbufferedfilehandle) method is broken.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Implement this method to specify what your app should do when the opportunistic lock for a handle that you get by calling the [IUnbufferedFileHandleProvider::OpenUnbufferedFileHandle](https://learn.microsoft.com/windows/desktop/api/windowsstoragecom/nf-windowsstoragecom-iunbufferedfilehandleprovider-openunbufferedfilehandle) method is broken.

## See also

[IUnbufferedFileHandleOplockCallback](https://learn.microsoft.com/windows/desktop/api/windowsstoragecom/nn-windowsstoragecom-iunbufferedfilehandleoplockcallback)

[IUnbufferedFileHandleProvider::OpenUnbufferedFileHandle](https://learn.microsoft.com/windows/desktop/api/windowsstoragecom/nf-windowsstoragecom-iunbufferedfilehandleprovider-openunbufferedfilehandle)