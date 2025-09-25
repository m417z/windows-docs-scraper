# ITfMouseTracker::AdviseMouseSink

## Description

Installs a mouse event sink.

## Parameters

### `range` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) interface that specifies the range of text that the mouse sink is installed for.

### `pSink` [in]

Pointer to the [ITfMouseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfmousesink) interface.

### `pdwCookie` [out]

Pointer to a DWORD value that receives a cookie that identifies the mouse event sink.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **TF_E_DISCONNECTED** | The context object is not on a document stack. |
| **E_NOTIMPL** | The context owner does not support mouse event sinks. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

When the advise sink is installed, a mouse event that occurs over the range specified by *range* will result in the mouse event sink [ITfMouseSink::OnMouseEvent](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfmousesink-onmouseevent) call.

The value placed in *pdwCookie* must be saved and passed to [ITfMouseTracker::UnadviseMouseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfmousetracker-unadvisemousesink) to remove the mouse event sink.

## See also

[ITfMouseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfmousesink)

[ITfMouseSink::OnMouseEvent](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfmousesink-onmouseevent)

[ITfMouseTracker](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfmousetracker)

[ITfMouseTracker::UnadviseMouseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfmousetracker-unadvisemousesink)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)