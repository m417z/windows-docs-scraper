# GetBrowserExtensionConfiguration function

Returns whether DLP/IRM is enabled upon the browser.

## Parameters

`browserConfiguration` [out]: The status of DLP/IRM on the browser.

## Return value

Returns an `HRESULT` including, but not limited to, the following values.

| `HRESULT` | Description |
|---------|-------------|
| `S_OK` | The function completed successfully. |
| `ERROR_DLL_INIT_FAILED` | The function was called before [DlpInitialize](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlpinitialize) was called. |

## Remarks

This function can be called from multiple threads.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 11, version 22H2 (10.0; Build 22621) |
| DLL<br> | EndpointDlp.dll |