# capCaptureSetSetup macro

## Syntax

```cpp
BOOL capCaptureSetSetup(
     hwnd,
     s,
     wSize
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capCaptureSetSetup** macro sets the configuration parameters used with streaming capture. You can use this macro or explicitly send the [WM_CAP_SET_SEQUENCE_SETUP](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-sequence-setup) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `s`

Pointer to a CAPTUREPARMS structure.

### `wSize`

Size, in bytes, of the structure referenced by s.

## Remarks

For information about the parameters used to control streaming capture, see the [CAPTUREPARMS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-captureparms) structure.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)