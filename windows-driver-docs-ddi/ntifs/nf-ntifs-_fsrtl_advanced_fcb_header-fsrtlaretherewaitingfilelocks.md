# FsRtlAreThereWaitingFileLocks function

## Description

The **FsRtlAreThereWaitingFileLocks** routine checks a file lock queue for any waiting file locks.

## Parameters

### `FileLock` [in]

The file lock that specifies locked ranges.

## Return value

 Returns **TRUE** if waiting file locks are present; **FALSE** otherwise.