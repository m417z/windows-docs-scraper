# ITfContextKeyEventSink::OnKeyUp

## Description

Called when a key up event occurs.

## Parameters

### `wParam` [in]

Specifies the virtual-key code of the key. For more information about this parameter, see the *wParam* parameter in [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup).

### `lParam` [in]

Specifies the repeat count, scan code, extended-key flag, context code, previous key-state flag, and transition-state flag of the key. For more information about this parameter, see the *lParam* parameter in [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup).

### `pfEaten` [out]

Pointer to a BOOL value that, on exit, indicates if the key event is handled. If this value receives **TRUE**, the key event is handled. If this value receives **FALSE**, the key event is not handled.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[ITfContextKeyEventSink interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontextkeyeventsink), [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup), [Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)