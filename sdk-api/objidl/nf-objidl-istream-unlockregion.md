# IStream::UnlockRegion

## Description

The **UnlockRegion** method removes the access restriction on a range of bytes previously restricted with
[IStream::LockRegion](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-lockregion).

## Parameters

### `libOffset` [in]

Specifies the byte offset for the beginning of the range.

### `cb` [in]

Specifies, in bytes, the length of the range to be restricted.

### `dwLockType` [in]

Specifies the access restrictions previously placed on the range.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The byte range was unlocked.|
|E_PENDING | Asynchronous Storage only: Part or all of the stream's data is currently unavailable.|
|STG_E_INVALIDFUNCTION | Locking is not supported at all or the specific type of lock requested is not supported.|
|STG_E_LOCKVIOLATION | The requested unlock operation cannot be granted.|
|STG_E_REVERTED | The object has been invalidated by a revert operation above it in the transaction tree.|

## Remarks

**IStream::UnlockRegion** unlocks a region previously locked with the
[IStream::LockRegion](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-lockregion) method. Locked regions must later be explicitly unlocked by calling **IStream::UnlockRegion** with exactly the same values for the *libOffset*, *cb*, and *dwLockType* parameters. The region must be unlocked before the stream is released. Two adjacent regions cannot be locked separately and then unlocked with a single unlock call.

## See also

[IStream - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istream-compound-file-implementation)

[IStream::LockRegion](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-lockregion)

[LOCKTYPE](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-locktype)