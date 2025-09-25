# capSetCallbackOnYield macro

## Syntax

```cpp
BOOL capSetCallbackOnYield(
     hwnd,
     fpProc
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** if streaming capture or a single-frame capture session is in progress.

## Description

The **capSetCallbackOnYield** macro sets a callback function in the application. AVICap calls this procedure when the capture window yields during streaming capture. You can use this macro or explicitly call the [WM_CAP_SET_CALLBACK_YIELD](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-callback-yield) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `fpProc`

Pointer to the yield callback function, of type [capYieldCallback](https://learn.microsoft.com/windows/desktop/api/vfw/nc-vfw-capyieldcallback). Specify **NULL** for this parameter to disable a previously installed yield callback function.

## Remarks

Applications can optionally set a yield callback function. The yield callback function is called at least once for each video frame captured during streaming capture. If a yield callback function is installed, it will be called regardless of the state of the **fYield** member of the [CAPTUREPARMS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-captureparms) structure.

If the yield callback function is used, it must be installed before starting the capture session and it must remain enabled for the duration of the session. It can be disabled after streaming capture ends.

Applications typically perform some type of message processing in the callback function consisting of a [PeekMessage](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-peekmessagea), [TranslateMessage](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-translatemessage), [DispatchMessage](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-dispatchmessage) loop, as in the message loop of a [WinMain](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-winmain) function. The yield callback function must also filter and remove messages that can cause reentrancy problems.

An application typically returns **TRUE** in the yield procedure to continue streaming capture. If a yield callback function returns **FALSE**, the capture window stops the capture process.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)