# SHLockShared function

## Description

[**SHLockShared** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Maps a block of memory from a specified process into the calling process.

## Parameters

### `hData` [in]

Type: **HANDLE**

A handle to the memory you want to map into the calling process.

### `dwProcessId` [in]

Type: **DWORD**

The process ID of the process from which you want to map the block of memory.

## Return value

Returns a void pointer to the shared memory. Returns **NULL** if unsuccessful.

## Remarks

Call [SHUnlockShared](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shunlockshared) to unlock the memory that this function maps. Call [SHFreeShared](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shfreeshared) to release the memory.