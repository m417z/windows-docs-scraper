# ILockBytes::LockRegion

## Description

The
**LockRegion** method restricts access to a specified range of bytes in the byte array.

## Parameters

### `libOffset` [in]

Specifies the byte offset for the beginning of the range.

### `cb` [in]

Specifies, in bytes, the length of the range to be restricted.

### `dwLockType` [in]

Specifies the type of restrictions being requested on accessing the range. This parameter uses one of the values from the
[LOCKTYPE](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-locktype) enumeration.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The specified range of bytes was locked.|
|STG_E_INVALIDFUNCTION | Locking is not supported at all or the specific type of lock requested is not supported.|
|STG_E_ACCESSDENIED | Access denied because the caller has insufficient permission, or another caller has the file open and locked.|
|STG_E_LOCKVIOLATION | Access denied because another caller has the file open and locked.|
|STG_E_INVALIDHANDLE | An underlying file has been prematurely closed, or the correct floppy disk has been replaced by an invalid one.|

## Remarks

**ILockBytes::LockRegion** restricts access to the specified range of bytes. Once a region is locked, attempts by others to gain access to the restricted range must fail with the STG_E_ACCESSDENIED error.

The byte range can extend past the current end of the byte array. Locking beyond the end of an array is useful as a method of communication between different instances of the byte array object without changing data that is actually part of the byte array. For example, an implementation of
[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) for compound files could rely on locking past the current end of the array as a means of access control, using specific locked regions to indicate permissions currently granted.

The *dwLockType* parameter specifies one of three types of locking, using values from the
[LOCKTYPE](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-locktype) enumeration. The types are as follows: locking to exclude other writers, locking to exclude other readers or writers, and locking that allows only one requester to obtain a lock on the given range. This third type of locking is usually an alias for one of the other two lock types, and permits an Implementer to add other behavior as well. A given byte array might support either of the first two types, or both.

To determine the lock types supported by a particular
[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) implementation, you can examine the **grfLocksSupported** member of the
[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure returned by a call to
[ILockBytes::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-stat).

Any region locked with **ILockBytes::LockRegion** must later be explicitly unlocked by calling
[ILockBytes::UnlockRegion](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-unlockregion) with exactly the same values for the *libOffset*, *cb*, and *dwLockType* parameters. The region must be unlocked before the stream is released. Two adjacent regions cannot be locked separately and then unlocked with a single unlock call.

### Notes to Callers

Since the type of locking supported is optional and can vary in different implementations of
[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes), you must provide code to deal with the STG_E_INVALIDFUNCTION error.

### Notes to Implementers

Support for this method depends on how the storage object built on top of the
[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) implementation is used. If you know that only one storage object at any given time can be opened on the storage device that underlies the byte array, then your
**ILockBytes** implementation does not need to support locking. However, if multiple simultaneous openings of a storage object are possible, then region locking is needed to coordinate them.

A
**LockRegion** implementation can choose to support all, some, or none of the lock types. For unsupported lock types, the implementation should return STG_E_INVALIDFUNCTION.

## See also

[ILockBytes - File-Based Implementation](https://learn.microsoft.com/windows/desktop/Stg/ilockbytes-file-based-implementation)

[ILockBytes - Global Memory Implementation](https://learn.microsoft.com/windows/desktop/Stg/ilockbytes-global-memory-implementation)

[ILockBytes::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-stat)

[ILockBytes::UnlockRegion](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-unlockregion)

[IStream::LockRegion](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-lockregion)

[LOCKTYPE](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-locktype)