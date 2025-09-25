# ITfSource::UnadviseSink

## Description

Uninstalls an advise sink.

## Parameters

### `dwCookie` [in]

A DWORD that identifies the advise sink to uninstall. This value is provided by a previous call to [ITfSource::AdviseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfsource-advisesink).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | The *dwCookie* value is invalid. |
| **CONNECT_E_NOCONNECTION** | The advise sink cannot be found. |

## See also

[ITfSource](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfsource)

[ITfSource::AdviseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfsource-advisesink)