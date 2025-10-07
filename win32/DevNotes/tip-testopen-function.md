# TestOpen function

Returns an existing test handle that was created with [TestCreate](https://learn.microsoft.com/windows/win32/devnotes/tip-testcreate-function).

## Parameters

### testCaseId

The test identifier.

### options

The test retrieval options. This parameter can be set to the following values.

| Value | Description |
|-------|---------|
| 0 | Default option. |
| 1 | Optimize retrieval with locking, like subsequently calling [TestQueryData](https://learn.microsoft.com/windows/win32/devnotes/tip-testquerydata-function). |
| 2 | Deprecated, this is the same as default option. |
| 131072 | Indicates that additional “properties” field will be included in the returned [TestInfo](https://learn.microsoft.com/windows/win32/devnotes/tip-testinfo-structure) structure. |

### storage

The test storage options. This parameter can be set to the following values.

| Value | Description |
|-------|---------|
| 1 | Data will be stored in process. |
| 2 | Data will be stored out of process. |

### testId

The identifier of the test instance.

### result [out]

A [TestInfo](https://learn.microsoft.com/windows/win32/devnotes/tip-testinfo-structure) structure containing information about the test.

## Return value

The test handle.

## Remarks

This function has no associated import library or header file; it must be invoked using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------|
| Minimum supported client | Windows Build 22000 |
| Minimum supported server | Windows Server 2022 |
| Header | None |
| DLL | kernelbase.dll |

