# DlpSerializedBuffer structure

Structure used to pass out a dynamically allocated string from an EndpointDlp API.

## Members

*bufferSize* `[out]`

The size of the string in buffer (excluding the null terminator).

*buffer* `[out]`

A `NULL` terminated string.

## Remarks

Must be released using [DlpReleaseBuffer](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlpreleasebuffer).

## Requirements

| Requirement | Value |
|-------------|-------|
| Minimum supported client | Windows 11, version 24H2 (Build 26100) |
| DLL | EndpointDlp.dll |