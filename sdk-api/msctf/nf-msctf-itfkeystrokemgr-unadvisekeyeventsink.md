# ITfKeystrokeMgr::UnadviseKeyEventSink

## Description

Removes a key event sink.

## Parameters

### `tid` [in]

Identifier of the client that owns the key event sink. This value was passed when the advise sink was installed using [ITfKeystrokeMgr::AdviseKeyEventSink](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeystrokemgr-advisekeyeventsink).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | The *tid* parameter is invalid. |
| **CONNECT_E_NOCONNECTION** | The advise sink identified by *tid* was not found. |

## See also

[ITfKeystrokeMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfkeystrokemgr)

[ITfKeystrokeMgr::AdviseKeyEventSink](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeystrokemgr-advisekeyeventsink)