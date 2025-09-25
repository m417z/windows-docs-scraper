# StgOpenAsyncDocfileOnIFillLockBytes function

## Description

[The **StgOpenAsyncDocfileOnIFillLockBytes** function is obsolete. The following information is provided to support versions of Windows prior to Windows 2000.]

The **StgOpenAsyncDocfileOnIFillLockBytes** opens an existing root asynchronous storage object on a byte-array wrapper object provided by the caller.

## Parameters

### `pflb` [in]

A [IFillLockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ifilllockbytes) pointer to the byte-array wrapper object that contains the storage object to be opened.

### `grfMode` [in]

A value that specifies the access mode to use to open the storage object. The most common access mode, taken from [STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants), is STGM_READ.

### `asyncFlags` [in]

A value that indicates whether a connection point on a storage is inherited by its substorages and streams. ASYNC_MODE_COMPATIBILITY indicates that the connection point is inherited; ASYNC_MODE_DEFAULT indicates that the connection point is not inherited.

### `ppstgOpen` [out]

A pointer to
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage)* pointer variable that receives the interface pointer to the root asynchronous storage object.

## Return value

This function supports the standard return values E_OUTOFMEMORY, E_UNEXPECTED, E_INVALIDARG, and E_FAIL, as well as the following:

## Remarks

The root storage of the asynchronous storage object is opened according to the access mode in the *grfMode* parameter. A pointer to the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface on the opened storage object is supplied through the *ppstgOpen* parameter.

The byte array wrapper object must have been previously instantiated through a call to the
[StgGetIFillLockBytesOnFile](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-stggetifilllockbytesonfile) function.

**StgOpenAsyncDocfileOnIFillLockBytes** does not support priority access mode or exclusions. Otherwise, it works in much the same way as the
[StgOpenStorageOnILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorageonilockbytes) function.

The returned storage object has a connection point for
[IProgressNotify](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iprogressnotify).

## See also

[IFillLockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ifilllockbytes)

[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes)

[StgGetIFillLockBytesOnFile](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-stggetifilllockbytesonfile)

[StgOpenStorageOnILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorageonilockbytes)