# ITfKeyTraceEventSink::OnKeyTraceUp

## Description

Called when a key up event occurs.

## Parameters

### `wParam` [in]

The WPARAM of the key event. For more information about this parameter, see the *wParam* parameter in [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup).

### `lParam` [in]

The LPARAM of the key event. For more information about this parameter, see the *lParam* parameter in [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

- [ITfKeyTraceEventSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfkeytraceeventsink)
- [WM_KEYUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-keyup)
- [Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)