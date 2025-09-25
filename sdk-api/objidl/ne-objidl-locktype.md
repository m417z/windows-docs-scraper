# LOCKTYPE enumeration

## Description

The
**LOCKTYPE** enumeration values indicate the type of locking requested for the specified range of bytes. The values are used in the
[ILockBytes::LockRegion](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-lockregion) and
[IStream::LockRegion](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-lockregion) methods.

## Constants

### `LOCK_WRITE:1`

If this lock is granted, the specified range of bytes can be opened and read any number of times, but writing to the locked range is prohibited except for the owner that was granted this lock.

### `LOCK_EXCLUSIVE:2`

If this lock is granted, writing to the specified range of bytes is prohibited except by the owner that was granted this lock.

### `LOCK_ONLYONCE:4`

If this lock is granted, no other **LOCK_ONLYONCE** lock can be obtained on the range. Usually this lock type is an alias for some other lock type. Thus, specific implementations can have additional behavior associated with this lock type.