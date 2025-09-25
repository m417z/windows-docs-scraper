# ILockBytes::UnlockRegion

## Description

The **UnlockRegion** method removes the access restriction on a previously locked range of bytes.

## Parameters

### `libOffset` [in]

Specifies the byte offset for the beginning of the range.

### `cb` [in]

Specifies, in bytes, the length of the range that is restricted.

### `dwLockType` [in]

Specifies the type of access restrictions previously placed on the range. This parameter uses a value from the
[LOCKTYPE](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-locktype) enumeration.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The byte range was unlocked.|
|STG_E_INVALIDFUNCTION | Locking is not supported at all or the specific type of lock requested is not supported.|
|STG_E_LOCKVIOLATION | The requested unlock cannot be granted.|

## Remarks

**ILockBytes::UnlockRegion** unlocks a region previously locked with a call to
[ILockBytes::LockRegion](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-lockregion). Each region locked must be explicitly unlocked, using the same values for the *libOffset*, *cb*, and *dwLockType* parameters as in the matching calls to **ILockBytes::LockRegion**. Two adjacent regions cannot be locked separately and then unlocked with a single unlock call.

## See also

[ILockBytes - File-Based Implementation](https://learn.microsoft.com/windows/desktop/Stg/ilockbytes-file-based-implementation)

[ILockBytes - Global Memory Implementation](https://learn.microsoft.com/windows/desktop/Stg/ilockbytes-global-memory-implementation)

[ILockBytes::LockRegion](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-lockregion)

[LOCKTYPE](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-locktype)