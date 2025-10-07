# TestReport function

Emits event to an ETW provider with the properties in the input struct.

## Parameters

### reportingInfo

A [TipReportingInfo](https://learn.microsoft.com/windows/win32/devnotes/tip-tipreportinginfo-structure) containing the properties that will be included in the ETW event as fields.

## Return value

None.

## Remarks

This function has no associated import library or header file; it must be invoked using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------|
| Minimum supported client | Windows Build 22000 |
| Minimum supported server | Windows Server 2022 |
| Header | None |
| DLL | kernelbase.dll |

