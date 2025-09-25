# ITfMouseTrackerACP::AdviseMouseSink

## Description

Called to install a mouse event sink.

## Parameters

### `range` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) interface that specifies the range of text that the mouse sink is installed for.

### `pSink` [in]

Pointer to the [ITfMouseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfmousesink) interface. The application must increment this object reference count and save the interface.

### `pdwCookie` [out]

Pointer to a DWORD that receives a cookie that identifies the mouse event sink.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_NOTIMPL** | The application does not support mouse event sinks. |

## Remarks

When this advise sink is installed, a mouse event that occurs over the range specified by *range* will result in the mouse event sink [ITfMouseSink::OnMouseEvent](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfmousesink-onmouseevent) method being called.

The value placed in *pdwCookie* will be saved by the caller and passed to the [ITfMouseTrackerACP::UnadviseMouseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfmousetrackeracp-unadvisemousesink) method to remove the mouse event sink.

## See also

[ITfMouseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfmousesink)

[ITfMouseSink::OnMouseEvent](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfmousesink-onmouseevent)

[ITfMouseTrackerACP](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfmousetrackeracp)

[ITfMouseTrackerACP::UnadviseMouseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfmousetrackeracp-unadvisemousesink)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)