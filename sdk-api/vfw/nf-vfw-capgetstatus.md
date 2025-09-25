# capGetStatus macro

## Syntax

```cpp
BOOL capGetStatus(
     hwnd,
     s,
     wSize
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** if the capture window is not connected to a capture driver.

## Description

The **capGetStatus** macro retrieves the status of the capture window. You can use this macro or explicitly call the [WM_CAP_GET_STATUS](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-get-status) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `s`

Pointer to a [CAPSTATUS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-capstatus) structure.

### `wSize`

Size, in bytes, of the structure referenced by *s*.

## Remarks

The [CAPSTATUS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-capstatus) structure contains the current state of the capture window. Since this state is dynamic and changes in response to various messages, the application should initialize this structure after sending the [capDlgVideoFormat](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capdlgvideoformat) macro and whenever it needs to enable menu items or determine the actual state of the window.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)