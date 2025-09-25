# ITfKeystrokeMgr::KeyUp

## Description

Passes a key up event to the keystroke manager.

## Parameters

### `wParam` [in]

Specifies the virtual-key code of the key. For more information about this parameter, see the *wParam* parameter in [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup).

### `lParam` [in]

Specifies the repeat count, scan code, extended-key flag, context code, previous key-state flag, and transition-state flag of the key. For more information about this parameter, see the *lParam* parameter in [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup).

### `pfEaten` [out]

Pointer to a BOOL that, on exit, indicates if the key event will be handled. If this value receives **TRUE**, the key event would be handled and the event should not be forwarded to the application. If this value is **FALSE**, the key event would not be handled and the event should be forwarded to the application.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | No key event sinks are installed. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## Remarks

If this method is successful and *pfEaten* receives **TRUE**, the application should not process the key down event. If this method does not return S_OK or *pfEaten* receives **FALSE**, the application should process the key down event. The following is an example of how this is implemented.

``` syntax

if(msg.message == WM_KEYUP)
{
    if( pKeyboardMgr->TestKeyUp(msg.wParam, msg.lParam, &fEaten) == S_OK
        && fEaten
        && pKeyboardMgr->KeyUp(msg.wParam, msg.lParam, &fEaten) == S_OK
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

If the keystroke manager does not handle the key event, it passes the key event to the text services by a call to the text service [ITfKeyEventSink::OnKeyUp](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeyeventsink-onkeyup) method.

## See also

- [ITfKeyEventSink::OnKeyUp](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeyeventsink-onkeyup)
- [ITfKeystrokeMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfkeystrokemgr)
- [ITfKeystrokeMgr::KeyDown](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeystrokemgr-keydown)
- [ITfKeystrokeMgr::TestKeyUp](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfkeystrokemgr-testkeyup)
- [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup)
- [Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)