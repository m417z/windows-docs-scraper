# ITfKeystrokeMgr::TestKeyDown

## Description

Determines if the keystroke manager will handle a key down event.

## Parameters

### `wParam` [in]

Specifies the virtual-key code of the key. For more information about this parameter, see the *wParam* parameter in [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown).

### `lParam` [in]

Specifies the repeat count, scan code, extended-key flag, context code, previous key-state flag, and transition-state flag of the key. For more information about this parameter, see the *lParam* parameter in [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown).

### `pfEaten` [out]

Pointer to a BOOL that indicates if the key event would be handled. If this value receives **TRUE**, the key event would be handled and the event should not be forwarded to the application. If this value is **FALSE**, the key event would not be handled and the event should be forwarded to the application.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | There are no key event sinks installed. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## Remarks

An application can determine if a key event will be handled by the keystroke manager with this method. If this method is successful and *pfEaten* receives **TRUE**, the application should call [ITfKeystrokeMgr::KeyDown](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeystrokemgr-keydown). If this method does not return S_OK or *pfEaten* receives **FALSE**, the application should not call **ITfKeystrokeMgr::KeyDown** . The following is an example of how this is implemented.

``` syntax

if(msg.message == WM_KEYDOWN)
{
    if( pKeyboardMgr->TestKeyDown(msg.wParam, msg.lParam, &fEaten) == S_OK
        && fEaten
        && pKeyboardMgr->KeyDown(msg.wParam, msg.lParam, &fEaten) == S_OK
        && fEaten)
    {
        //The key was handled by the keystroke manager or a TSF text service. Do not pass the key to the application.
        continue;
    }
    else
    {
        //Let the application process the key.
    }
}

```

If the keystroke manager does not handle the key event, it passes the key event to the TSF text services by calling the text service [ITfKeyEventSink::OnTestKeyDown](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeyeventsink-ontestkeydown) method.

## See also

- [ITfKeyEventSink::OnTestKeyDown](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeyeventsink-ontestkeydown)
- [ITfKeystrokeMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfkeystrokemgr)
- [ITfKeystrokeMgr::KeyDown](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeystrokemgr-keydown)
- [ITfKeystrokeMgr::TestKeyUp](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeystrokemgr-testkeyup)
- [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown)
- [Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)