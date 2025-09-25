# IStream::LockRegion

## Description

The **LockRegion** method restricts access to a specified range of bytes in the stream. Supporting this functionality is optional since some file systems do not provide it.

## Parameters

### `libOffset` [in]

Integer that specifies the byte offset for the beginning of the range.

### `cb` [in]

Integer that specifies the length of the range, in bytes, to be restricted.

### `dwLockType` [in]

Specifies the restrictions being requested on accessing the range.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The specified range of bytes was locked.|
|E_PENDING | Asynchronous Storage only: Part or all of the stream's data is currently unavailable. |
|STG_E_INVALIDFUNCTION | Locking is not supported at all or the specific type of lock requested is not supported.|
|STG_E_LOCKVIOLATION | Requested lock is supported, but cannot be granted because of an existing lock.|
|STG_E_REVERTED | The object has been invalidated by a revert operation above it in the transaction tree.|

## Remarks

The byte range of the stream can be extended. Locking an extended range for the stream is useful as a method of communication between different instances of the stream without changing data that is actually part of the stream.

Three types of locking can be supported: locking to exclude other writers, locking to exclude other readers or writers, and locking that allows only one requester to obtain a lock on the given range, which is usually an alias for one of the other two lock types. A given stream instance might support either of the first two types, or both. The lock type is specified by *dwLockType*, using a value from the
[LOCKTYPE](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-locktype) enumeration.

Any region locked with **IStream::LockRegion** must later be explicitly unlocked by calling
[IStream::UnlockRegion](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-unlockregion) with exactly the same values for the *libOffset*, *cb*, and *dwLockType* parameters. The region must be unlocked before the stream is released. Two adjacent regions cannot be locked separately and then unlocked with a single unlock call.

### Notes to Callers

Since the type of locking supported is optional and can vary in different implementations of
[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream), you must provide code to deal with the STG_E_INVALIDFUNCTION error.

The **LockRegion** method has no effect in the compound file implementation, because the implementation does not support range locking.

### Notes to Implementers

Support for this method is optional for implementations of stream objects since it may not be supported by the underlying file system. The type of locking supported is also optional. The STG_E_INVALIDFUNCTION error is returned if the requested type of locking is not supported.

## See also

[IStream - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istream-compound-file-implementation)

[IStream::UnlockRegion](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-unlockregion)

[LOCKTYPE](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-locktype)