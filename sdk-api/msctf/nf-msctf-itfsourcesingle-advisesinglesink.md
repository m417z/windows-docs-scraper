# ITfSourceSingle::AdviseSingleSink

## Description

Installs an advise sink.

## Parameters

### `tid` [in]

Contains a **TfClientId** value that identifies the client.

### `riid` [in]

Identifies the type of advise sink to install.

This parameter can be one of the following values when the [ITfSourceSingle](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfsourcesingle) object is obtained from an [ITfThreadMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr) object.

This parameter can be one of the following values when the **ITfSourceSingle** object is obtained from an [ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext) object.

| Value | Meaning |
| --- | --- |
| **IID_ITfCleanupContextDurationSink** | Installs a [ITfCleanupContextDurationSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcleanupcontextdurationsink) advise sink. |
| **IID_ITfFunctionProvider** | Registers the client as a function provider. The *punk* parameter is an [ITfFunctionProvider](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itffunctionprovider) interface pointer. |

### `punk` [in]

Pointer to the advise sink **IUnknown** pointer.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **CONNECT_E_CANNOTCONNECT** | The advise sink cannot be installed. |
| **CONNECT_E_ADVISELIMIT** | The maximum number of advise sinks has been reached. |
| **E_FAIL** | An unspecified error occurred. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[ITfCleanupContextSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcleanupcontextsink)

[ITfFunctionProvider](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itffunctionprovider)

[ITfSourceSingle](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfsourcesingle)