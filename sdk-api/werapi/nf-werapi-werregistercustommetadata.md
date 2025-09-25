# WerRegisterCustomMetadata function

## Description

Registers app-specific metadata to be collected (in the form of key/value strings) for the [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) error report.

## Parameters

### `key`

The "key" string for the metadata element being registered.

### `value`

The value string for the metadata element being registered.

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error codes.

|Return code|Description|
|--- |--- |
|**E_INVALIDARG**|Strings were **NULL**, key length was greater than 64 characters or was an invalid xml element name, or *value* length was greater than 128 characters or contained characters that were not ASCII printable characters.|
|**E_OUTOFMEMORY**|WER could not allocate a large enough heap for the data|
|**HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)**|The maximum number of registered entries (**WER_MAX_REGISTERED_ENTRIES**) or maximum amount of registered metadata (**WER_MAX_REGISTERED_METADATA**) has been reached.|
|**WER_E_INVALID_STATE**|The process state is not valid. For example, the process is in application recovery mode.|

## Remarks

This API allows apps to integrate their own app-level telemetry with system-level telemetry (WER) by associating app metadata with crash reports corresponding to their processes.

## See also

[WerUnregisterCustomMetadata](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werunregistercustommetadata), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)