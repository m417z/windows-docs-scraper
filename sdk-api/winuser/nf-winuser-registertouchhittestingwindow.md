# RegisterTouchHitTestingWindow function

## Description

Registers a window to process the

[WM_TOUCHHITTESTING](https://learn.microsoft.com/windows/win32/inputmsg/wm-touchhittesting) notification.

## Parameters

### `hwnd` [in]

The window that receives the [WM_TOUCHHITTESTING](https://learn.microsoft.com/windows/win32/inputmsg/wm-touchhittesting) notification.

### `value` [in]

One of the following values:

* [TOUCH_HIT_TESTING_CLIENT](https://learn.microsoft.com/previous-versions/windows/desktop/input_touchhittest/hit-testing-behaviors): Send [WM_TOUCHHITTESTING](https://learn.microsoft.com/windows/win32/inputmsg/wm-touchhittesting) messages to the target window.
* [TOUCH_HIT_TESTING_DEFAULT](https://learn.microsoft.com/previous-versions/windows/desktop/input_touchhittest/hit-testing-behaviors): Don't send [WM_TOUCHHITTESTING](https://learn.microsoft.com/windows/win32/inputmsg/wm-touchhittesting) messages to the target window but continue to send the messages to child windows.
* [TOUCH_HIT_TESTING_NONE](https://learn.microsoft.com/previous-versions/windows/desktop/input_touchhittest/hit-testing-behaviors): Don't send [WM_TOUCHHITTESTING](https://learn.microsoft.com/windows/win32/inputmsg/wm-touchhittesting) messages to the target window or child windows.

## Return value

If this function succeeds, it returns TRUE.
Otherwise, it returns FALSE. To retrieve extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/input_touchhittest/functions)