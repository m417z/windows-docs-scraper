# ITfMouseTrackerACP::UnadviseMouseSink

## Description

Called to remove a mouse event sink.

## Parameters

### `dwCookie` [in]

Specifies the mouse advise sink identifier. This value is obtained by a call to [ITfMouseTrackerACP::AdviseMouseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfmousetrackeracp-advisemousesink).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOTIMPL** | The application does not support mouse event sinks. |

## Remarks

The application must release the [ITfMouseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfmousesink) supplied in the **ITfMouseTrackerACP::AdviseMouseSink** call associated with *dwCookie*.

## See also

[ITfMouseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfmousesink)

[ITfMouseTrackerACP](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfmousetrackeracp)

[ITfMouseTrackerACP::AdviseMouseSink](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfmousetrackeracp-advisemousesink)