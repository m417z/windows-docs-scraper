# StgIsStorageFile function

## Description

The **StgIsStorageFile** function indicates whether a particular disk file contains a storage object.

## Parameters

### `pwcsName` [in]

Pointer to the null-terminated Unicode string name of the disk file to be examined. The *pwcsName* parameter is passed uninterpreted to the underlying file system.

## Return value

**StgIsStorageFile** function can also return any file system errors or system errors wrapped in an **HRESULT**. See
[Error Handling Strategies](https://learn.microsoft.com/windows/desktop/com/error-handling-strategies) and
[Handling Unknown Errors](https://learn.microsoft.com/windows/desktop/com/handling-unknown-errors)

## Remarks

At the beginning of the disk file underlying a storage object is a signature distinguishing a storage object from other file formats. The
**StgIsStorageFile** function is useful to applications whose documents use a disk file format that might or might not use storage objects.

If a root compound file has been created in transacted mode but not yet committed, this method still return S_OK.

## See also

[StgIsStorageILockBytes](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgisstorageilockbytes)