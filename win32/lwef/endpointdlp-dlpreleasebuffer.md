# DlpReleaseBuffer function

Releases a previously allocated [DlpSerializedBuffer](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlpserializedbuffer).

## Parameters

`buffer` [in]: A pointer to the [DlpSerializedBuffer](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlpserializedbuffer) to be released. This parameter must not be `NULL`.

## Return value

Returns an `HRESULT` including, but not limited to, the following values:

| `HRESULT` | Description |
|---------|-------------|
| `S_OK` | The function completed successfully. |
| `FAILED` | An unexpected error prevented the function from completing. |

## Requirements

| Requirement | Value |
|-------------|-------|
| Minimum supported client | Windows 11, version 24H2 (Build 26100) |
| DLL | EndpointDlp.dll |

## Related content

- [DlpSerializedBuffer](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlpserializedbuffer)