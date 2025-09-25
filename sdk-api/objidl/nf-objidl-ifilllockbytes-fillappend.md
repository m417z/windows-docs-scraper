# IFillLockBytes::FillAppend

## Description

The **FillAppend** method writes a new block of bytes to the end of a byte array.

## Parameters

### `pv` [in]

Pointer to the data to be appended to the end of an existing byte array. This operation does not create a danger of a memory leak or a buffer overrun.

### `cb` [in]

Size of *pv* in bytes.

### `pcbWritten` [out]

Number of bytes that were successfully written.

## Return value

This function supports the standard return values E_OUTOFMEMORY, E_UNEXPECTED, E_INVALIDARG, and E_FAIL.

## Remarks

The
**FillAppend** method is used for sequential downloading, where bytes are written to the end of the byte array in the order in which they are received. This method obtains the current size of the byte array (for example, lockbytes object) and writes a new block of data to the end of the array. As each block of data becomes available, the downloader calls this method to write it to the byte array. Subsequent calls by the compound file implementation to
[ILockBytes::ReadAt](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-readat) return any available data or return E_PENDING if data is currently unavailable.

## See also

[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes)