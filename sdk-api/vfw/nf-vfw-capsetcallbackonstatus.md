# capSetCallbackOnStatus macro

## Syntax

```cpp
BOOL capSetCallbackOnStatus(
     hwnd,
     fpProc
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** if streaming capture or a single-frame capture session is in progress.

## Description

The **capSetCallbackOnStatus** macro sets a status callback function in the application. AVICap calls this procedure whenever the capture window status changes. You can use this macro or explicitly call the [WM_CAP_SET_CALLBACK_STATUS](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-callback-status) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `fpProc`

Pointer to the status callback function, of type [capStatusCallback](https://learn.microsoft.com/windows/desktop/api/vfw/nc-vfw-capstatuscallbacka). Specify **NULL** for this parameter to disable a previously installed status callback function.

## Remarks

Applications can optionally set a status callback function. If set, AVICap calls this procedure in the following situations:

* A capture session is completed.
* A capture driver successfully connected to a capture window.
* An optimal palette is created.
* The number of captured frames is reported.

## See also

[Creating a Status Callback Function](https://learn.microsoft.com/windows/desktop/Multimedia/creating-a-status-callback-function)

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)