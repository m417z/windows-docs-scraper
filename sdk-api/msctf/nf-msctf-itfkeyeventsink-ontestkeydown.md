# ITfKeyEventSink::OnTestKeyDown

## Description

Called to determine if a text service will handle a key down event.

## Parameters

### `pic` [in]

Pointer to the input context that receives the key event.

### `wParam` [in]

Specifies the virtual-key code of the key. For more information about this parameter, see the *wParam* parameter in [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown).

### `lParam` [in]

Specifies the repeat count, scan code, extended-key flag, context code, previous key-state flag, and transition-state flag of the key. For more information about this parameter, see the *lParam* parameter in [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown).

### `pfEaten` [out]

Pointer to a BOOL that, on exit, indicates if the key event would be handled. If this value receives **TRUE**, the key event would be handled. If this value is **FALSE**, the key event would not be handled.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[ITfKeyEventSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfkeyeventsink), [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown), [Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)