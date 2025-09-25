# GetHGlobalFromILockBytes function

## Description

The
**GetHGlobalFromILockBytes** function retrieves a global memory handle to a byte array object created using the
[CreateILockBytesOnHGlobal](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-createilockbytesonhglobal) function.

## Parameters

### `plkbyt` [in]

Pointer to the
[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) interface on the byte-array object previously created by a call to the
[CreateILockBytesOnHGlobal](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-createilockbytesonhglobal) function.

### `phglobal` [out]

Pointer to the current memory handle used by the specified byte-array object.

## Return value

This function returns HRESULT.

## Remarks

After a call to
[CreateILockBytesOnHGlobal](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-createilockbytesonhglobal), which creates a byte array object on global memory,
**GetHGlobalFromILockBytes** retrieves a pointer to the handle of the global memory underlying the byte array object. The handle this function returns might be different from the original handle due to intervening calls to the [GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc) function.

The contents of the returned memory handle can be written to a clean disk file, and then opened as a storage object using the
[StgOpenStorage](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorage) function.

This function only works within the same process from which the byte array was created.

## See also

[CreateILockBytesOnHGlobal](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-createilockbytesonhglobal)

[StgOpenStorage](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorage)