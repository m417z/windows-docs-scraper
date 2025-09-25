# ITfKeyTraceEventSink::OnKeyTraceDown

## Description

Called when a key down event occurs.

## Parameters

### `wParam` [in]

The WPARAM of the key event. For more information about this parameter, see the *wParam* parameter in [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown).

### `lParam` [in]

The LPARAM of the key event. For more information about this parameter, see the *lParam* parameter in [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITfKeyTraceEventSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfkeytraceeventsink)
[WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown)
[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)