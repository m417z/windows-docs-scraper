# IFillLockBytes::SetFillSize

## Description

The
**SetFillSize** method sets the expected size of the byte array.

## Parameters

### `ulSize` [in]

Size in bytes of the byte array object that is to be filled in subsequent calls to
[IFillLockBytes::FillAppend](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ifilllockbytes-fillappend).

## Return value

This function supports the standard return values E_OUTOFMEMORY, E_UNEXPECTED, E_INVALIDARG, and E_FAIL.

## Remarks

If
**SetFillSize** has not been called, any call to
[ILockBytes::ReadAt](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-readat) that attempts to access data that has not yet been written using
[IFillLockBytes::FillAppend](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ifilllockbytes-fillappend) or
[IFillLockBytes::FillAt](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ifilllockbytes-fillat) will return a new error message, E_PENDING. After
**SetFillSize** has been called, any call to
**ReadAt** that attempts to access data beyond the current size, as set by
**SetFillSize**, returns E_FAIL instead of E_PENDING.

## See also

[IFillLockBytes::FillAppend](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ifilllockbytes-fillappend)

[IFillLockBytes::FillAt](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ifilllockbytes-fillat)

[ILockBytes::ReadAt](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-readat)