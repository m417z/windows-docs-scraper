# SHUnlockShared function

## Description

[**SHUnlockShared** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Unlocks memory locked by [SHLockShared](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shlockshared).

## Parameters

### `pvData` [in]

Type: **void***

A pointer to the shared memory block returned by [SHLockShared](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shlockshared).

## Return value

Type: **BOOL**

If the function succeeds, the return value is **TRUE** and all modified pages within the specified range are written to the disk with low priority. If the function fails, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Call [SHFreeShared](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shfreeshared) to free the memory block.