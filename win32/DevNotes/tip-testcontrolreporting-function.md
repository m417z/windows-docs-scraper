# TestControlReporting function

Changes the keywords of ETW events.

## Parameters

### reportingRequest

The options for changing emitted ETW event. This parameter can have the following values.

| Value | Description |
|-------|-------------|
| 0 | Save process data into persistent storage. |
| 1 | Add keyword bits 45 and 46 back to ETW event. |
| 2 | Remove keyword bits 45 and 46 from ETW event. |

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

