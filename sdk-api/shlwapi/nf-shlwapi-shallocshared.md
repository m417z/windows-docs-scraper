# SHAllocShared function

## Description

[**SHAllocShared** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Allocates a handle in a specified process to a copy of a specified memory block in the calling process.

## Parameters

### `pvData` [in, optional]

Type: **const void***

A pointer to the memory block in the calling process that is to be copied. You can set this parameter to **NULL** if you want to share a block of memory without copying any data to it.

### `dwSize` [in]

Type: **DWORD**

The size, in bytes, of the memory block pointed to by *pvData*.

### `dwProcessId` [in]

Type: **DWORD**

The process ID of the process that will share memory block specified by *pvData*.

## Return value

Type: **HANDLE**

Returns a handle to the shared memory for the process specified by *dwDestinationProcessId*. Returns **NULL** if unsuccessful.

## Remarks

Use [SHFreeShared](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shfreeshared) to free the handle when you are finished.

## See also

[SHFreeShared](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shfreeshared)

[SHLockShared](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shlockshared)

[SHUnlockShared](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shunlockshared)