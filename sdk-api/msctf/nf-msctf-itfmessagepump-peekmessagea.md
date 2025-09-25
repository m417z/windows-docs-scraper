# ITfMessagePump::PeekMessageA

## Description

Obtains a message from the message queue and returns if no message is obtained. This is the ANSI version of this method.

## Parameters

### `pMsg` [out]

Pointer to a [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure that receives message data.

### `hwnd` [in]

Handle to the window whose messages are obtained. The window must belong to the current thread. If this value is **NULL**, this method obtains messages for any window owned by the calling thread.

### `wMsgFilterMin` [in]

Specifies the lowest message value to obtain.

### `wMsgFilterMax` [in]

Specifies the highest message value to obtain.

### `wRemoveMsg` [in]

Specifies how messages are handled. For more information, see the **PeekMessage** function.

### `pfResult` [out]

Pointer to a BOOL that receives the return value from the **PeekMessage** function.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## Remarks

If *wMsgFilterMin* and *wMsgFilterMax* are both zero, this method returns all available messages; that is, no range filtering is performed.

## See also

[ITfMessagePump](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfmessagepump)

[MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)

[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea)