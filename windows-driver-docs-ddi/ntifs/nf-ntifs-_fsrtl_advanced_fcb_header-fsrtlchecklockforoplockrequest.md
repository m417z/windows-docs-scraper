# FsRtlCheckLockForOplockRequest function

## Description

The **FsRtlCheckLockForOplockRequest** routine checks for locks within the allocation size of a file. The file lock object is checked for the presence of byte range locks that would prevent an oplock request from being granted.

## Parameters

### `FileLock` [in]

The file lock that specifies locked ranges.

### `AllocationSize` [in]

The file allocation size to check for any locked ranges.

## Return value

**FsRtlCheckLockForOplockRequest** returns TRUE if the oplock request can be granted; otherwise it returns FALSE.

## Remarks

**FsRtlCheckLockForOplockRequest** returns **TRUE** if **AllocationSize** = 0.

If **FileLock** has any pending lock requests, the check fails and **FsRtlCheckLockForOplockRequest** returns **FALSE**.