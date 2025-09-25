# StgIsStorageILockBytes function

## Description

The **StgIsStorageILockBytes** function indicates whether the specified byte array contains a storage object.

## Parameters

### `plkbyt`

[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) pointer to the byte array to be examined.

## Return value

This function can also return any file system errors, or system errors wrapped in an **HRESULT**, or
[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) interface error return values. See
[Error Handling Strategies](https://learn.microsoft.com/windows/desktop/com/error-handling-strategies) and
[Handling Unknown Errors](https://learn.microsoft.com/windows/desktop/com/handling-unknown-errors)

## Remarks

At the beginning of the byte array underlying a storage object is a signature distinguishing a storage object (supporting the
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface) from other file formats. The
**StgIsStorageILockBytes** function is useful to applications whose documents use a byte array (a byte array object supports the
[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) interface) that might or might not use storage objects.

## See also

[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes)

[StgIsStorageFile](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgisstoragefile)