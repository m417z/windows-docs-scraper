# ITfKeystrokeMgr::AdviseKeyEventSink

## Description

Installs a key event sink to receive keyboard events.

## Parameters

### `tid` [in]

Identifier of the client that owns the key event sink. This value is obtained by a previous call to [ITfThreadMgr::Activate](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgr-activate).

### `pSink` [in]

Pointer to a [ITfKeyEventSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfkeyeventsink) interface.

### `fForeground` [in]

Specifies if this key event sink is made the foreground key event sink. If this is **TRUE**, this key event sink is made the foreground key event sink. Otherwise, this key event sink does not become the foreground key event sink.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **CONNECT_E_ADVISELIMIT** | The client identified by *tid* has a key event sink installed. |

## Remarks

The foreground key event sink receives all keyboard events. A non-foreground key event sink only receives preserved keys and key events that occur over text that marked owned by the client identifier.

## See also

[ITfKeyEventSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfkeyeventsink)

[ITfKeystrokeMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfkeystrokemgr)

[ITfThreadMgr::Activate](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgr-activate)