# GetHGlobalFromStream function

## Description

The **GetHGlobalFromStream** function retrieves the global memory handle to a stream that was created through a call to the
[CreateStreamOnHGlobal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-createstreamonhglobal) function.

## Parameters

### `pstm` [in]

[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) pointer to the stream object previously created by a call to the
[CreateStreamOnHGlobal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-createstreamonhglobal) function.

### `phglobal` [out]

Pointer to the current memory handle used by the specified stream object.

## Return value

This function returns HRESULT.

## Remarks

The handle **GetHGlobalFromStream** returns may be different from the original handle due to intervening [GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc) calls.

This function can be called only from within the same process from which the byte array was created.

## See also

[CreateStreamOnHGlobal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-createstreamonhglobal)

[GlobalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalrealloc)