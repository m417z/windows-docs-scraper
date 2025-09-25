# capSetCallbackOnCapControl macro

## Syntax

```cpp
BOOL capSetCallbackOnCapControl(
     hwnd,
     fpProc
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** if streaming capture or a single-frame capture session is in progress.

## Description

The **capSetCallbackOnCapControl** macro sets a callback function in the application giving it precise recording control. You can use this macro or explicitly call the [WM_CAP_SET_CALLBACK_CAPCONTROL](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-callback-capcontrol) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `fpProc`

Pointer to the callback function, of type capControlCallback . Specify **NULL** for this parameter to disable a previously installed callback function.

## Remarks

A single callback function is used to give the application precise control over the moments that streaming capture begins and completes. The capture window first calls the procedure with *nState* set to CONTROLCALLBACK_PREROLL after all buffers have been allocated and all other capture preparations have finished. This gives the application the ability to preroll video sources, returning from the callback function at the exact moment recording is to begin. A return value of **TRUE** from the callback function continues capture, and a return value of **FALSE** aborts capture. After capture begins, this callback function will be called frequently with *nState* set to CONTROLCALLBACK_CAPTURING to allow the application to end capture by returning **FALSE**.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)

[WM_CAP_SET_CALLBACK_CAPCONTROL](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-callback-capcontrol)

[capControlCallback](https://learn.microsoft.com/windows/desktop/api/vfw/nc-vfw-capcontrolcallback)