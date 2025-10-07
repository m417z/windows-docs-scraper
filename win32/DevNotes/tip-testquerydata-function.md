# TestQueryData function

Allows modification of the test handle with locking.

## Parameters

### test

The test handle returned from [TestCreate](https://learn.microsoft.com/windows/win32/devnotes/tip-testcreate-function) or [TestOpen](https://learn.microsoft.com/windows/win32/devnotes/tip-testopen-function).

### options

The test query options. This parameter can be set to the following values.

| Value | Description |
|-------|---------|
| 0 | Default option. |
| 1 | Acquires lock to protect modifications until unlock. |
| 2 | Close handle and mark as complete. |
| 3 | Close handle and mark complete if this is the final handle. |
| 4 | Set when the caller already owns the lock. |

### knownDataSequenceId

The last known *dataSequenceId* of the result. Allows optimization from caller by doing less work when this is the same on subsequent calls.

### result [out]

A [TestInfo](https://learn.microsoft.com/windows/win32/devnotes/tip-testinfo-structure) structure containing information about the test.

## Return value

True if the operation was successful.

## Remarks

This function has no associated import library or header file; it must be invoked using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------|
| Minimum supported client | Windows Build 22000 |
| Minimum supported server | Windows Server 2022 |
| Header | None |
| DLL | kernelbase.dll |

