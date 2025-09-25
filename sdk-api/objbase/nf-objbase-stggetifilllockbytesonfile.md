# StgGetIFillLockBytesOnFile function

## Description

[The **StgGetIFillLockBytesOnFile** function is obsolete. The following information is provided to support versions of Windows prior to Windows 2000.]

The **StgGetIFillLockBytesOnFile** function opens a wrapper object on a temporary file.

## Parameters

### `pwcsName` [in]

A pointer to the null-terminated unicode string name of the file for which a wrapper object is created.

### `ppflb` [out]

A pointer to
[IFillLockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ifilllockbytes)* pointer variable that receives the interface pointer to the new byte array wrapper object.

## Return value

This function supports the standard return values E_OUTOFMEMORY, E_UNEXPECTED, E_INVALIDARG, and E_FAIL, in addition to the following:

The **StgGetIFillLockBytesOnFile** function can also return any file system errors.

## Remarks

The moniker that manages the downloading of the file specified in *pwcsName* calls this function in the course of creating the asynchronous storage necessary to manage the asynchronous downloading of data. The moniker first creates a temporary file, then calls this function to create the wrapper object on that file. Finally, the moniker calls
[StgOpenAsyncDocfileOnIFillLockBytes](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-stgopenasyncdocfileonifilllockbytes) to open the root storage of the compound file to be downloaded into the temporary file.

## See also

[IFillLockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ifilllockbytes)

[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes)

[StgOpenAsyncDocfileOnIFillLockBytes](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-stgopenasyncdocfileonifilllockbytes)