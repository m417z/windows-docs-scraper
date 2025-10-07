# TestUnlockData function

Unlocks the test handle that was locked with [TestQueryData](https://learn.microsoft.com/windows/win32/devnotes/tip-testquerydata-function).

## Parameters

### test

The test handle returned from [TestCreate](https://learn.microsoft.com/windows/win32/devnotes/tip-testcreate-function) or [TestOpen](https://learn.microsoft.com/windows/win32/devnotes/tip-testopen-function).

### options

The unlock data options. This parameter can be set to the following values.

| Value | Description |
|-------|---------|
| 0 | None. |
| 1 | This update is coming from a test class that was opened with an ambiguous entity, i.e.multiple tests running may assume contention.|

### data

An arbitrary JSON string.

### result [out]

A [TestInfo](https://learn.microsoft.com/windows/win32/devnotes/tip-testinfo-structure) structure containing information about the test.

## Return value

None

## Remarks

This function has no associated import library or header file; it must be invoked using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------|
| Minimum supported client | Windows Build 22000 |
| Minimum supported server | Windows Server 2022 |
| Header | None |
| DLL | kernelbase.dll |

