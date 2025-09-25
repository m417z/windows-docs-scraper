# ITfMouseTracker::UnadviseMouseSink

## Description

Uninstalls a mouse event sink.

## Parameters

### `dwCookie` [in]

Specifies the mouse advise sink identifier. This value is obtained by a call to [ITfMouseTracker::AdviseMouseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfmousetracker-advisemousesink).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TF_E_DISCONNECTED** | The context object is not on a document stack. |
| **E_NOTIMPL** | The context owner does not support mouse event sinks. |

## See also

[ITfMouseTracker](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfmousetracker)

[ITfMouseTracker::AdviseMouseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfmousetracker-advisemousesink)