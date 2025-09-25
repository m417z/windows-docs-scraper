# ITfSourceSingle::UnadviseSingleSink

## Description

Uninstalls an advise sink.

## Parameters

### `tid` [in]

Contains a **TfClientId** value that identifies the client.

### `riid` [in]

Identifies the type of advise sink to uninstall. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **IID_ITfCleanupContextDurationSink** | Uninstalls the [ITfCleanupContextDurationSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcleanupcontextdurationsink) advise sink. Applies to: Text service |
| **IID_ITfCleanupContextSink** | Uninstalls the [ITfCleanupContextSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcleanupcontextsink) advise sink. Applies to: Text service |
| **IID_ITfFunctionProvider** | Unregisters the client as a function provider. Applies to: Text Service and Application |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The advise sink was successfully uninstalled. |
| **E_INVALIDARG** | *tid* is invalid. |
| **CONNECT_E_NOCONNECTION** | The advise sink is not installed. |