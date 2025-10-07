# DlpIsSensitiveStream function

Checks to see is an input buffer pasted to a browser is sensitive.

> [!NOTE]
> Currently, this API only checks for text buffers. Binary or image buffers are not currently supported.

## Parameters

`cbBuffer` [in]: The input buffer to be analyzed.

`pvBuffer` [in]: The length of the input buffer, in bytes.

`url` [in]: The URL of the current browser tab (Edge only). For non-edge browsers, this must be set to NULL.

`flags` [in]: A flag denoting further information on the buffer. See Remarks for details.

`pReserved` [in]: Not currently used. Must be set to 0.

`*enforcementLevel` [out]: The enforcement level associated with the input buffer.

`traceInfoEx` [out]: A reference to a Trace structure. On successful completion, this structure contains the Policy version used for evaluation and the `PolicyRuleID` assigned to the file. This value can be NULL. The caller should call [DlpFreeArchiveFileTraceInfo](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlpfreearchivefiletraceinfo) on this structure when done.

## Return value

Returns an `HRESULT` including, but not limited to, the following values.

| `HRESULT` | Description |
|---------|-------------|
| `S_OK` | The function completed successfully |
| `HRESULT_FROM_WIN32(WAIT_TIMEOUT) 0x80070102`| Timeout. Classification took too long. The caller should treat this as a block, and show a customized message asking the user to try again. |
| `HRESULT_FROM_WIN32(RPC_S_SERVER_UNAVAILABLE) 0x800706ba`| The Windows Defender service is not running. |

## Remarks

Currently, this API supports the following flags:

`DLP_ISS_FLAG_TEXT`: Indicates that the input buffer is a null-terminated `WCHAR` string.

`DLP_ISS_FLAG_SUPPRESS_DEFENDER_UX`: The caller will supply its own text in the case of a block or warn enforcement level result.

This function can be called from multiple threads.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 11, version 22H2 (10.0; Build 22621) |
| DLL<br> | EndpointDlp.dll |