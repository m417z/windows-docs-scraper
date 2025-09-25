# IFillLockBytes::FillAt

## Description

The
**FillAt** method writes a new block of data to a specified location in the byte array.

## Parameters

### `ulOffset` [in]

The offset, expressed in number of bytes, from the first element of the byte array.

### `pv` [in]

Pointer to the data to be written at the location specified by *uIOffset*.

### `cb` [in]

Size of *pv* in bytes.

### `pcbWritten` [out]

Number of bytes that were successfully written.

## Return value

This function supports the standard return values E_OUTOFMEMORY, E_UNEXPECTED, E_INVALIDARG, and E_FAIL in addition to the following:

| Return code | Description |
|----------------|---------------|
| E_NOTIMPL | The byte array does not support the **FillAt** method. |

## Remarks

The
**FillAt** method is used for nonsequential downloading (for example, HTTP byte range requests). In nonsequential downloading the caller specifies ranges in the byte array where various blocks of data are to be written. Subsequent calls by the compound file implementation to [ILockBytes::ReadAt](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-readat) are passed by the byte array wrapper object's own implementation of
[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) to the underlying byte array. This method is not currently implemented and will return E_NOTIMPL.

**Note** The system-supplied
[IFillLockBytes](https://learn.microsoft.com/windows/desktop/Stg/ifilllockbytes-implementation) implementation does not support
**FillAt** and returns E_NOTIMPL.

## See also

[IFillLockBytes - Implementation](https://learn.microsoft.com/windows/desktop/Stg/ifilllockbytes-implementation)

[IFillLockBytes::FillAppend](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ifilllockbytes-fillappend)

[ILockBytes::ReadAt](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-readat)