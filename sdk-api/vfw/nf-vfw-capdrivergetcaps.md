# capDriverGetCaps macro

## Syntax

```cpp
BOOL capDriverGetCaps(
     hwnd,
     s,
     wSize
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** if the capture window is not connected to a capture driver.

## Description

The **capDriverGetCaps** macro returns the hardware capabilities of the capture driver currently connected to a capture window. You can use this macro or explicitly send the [WM_CAP_DRIVER_GET_CAPS](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-driver-get-caps) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `s`

Pointer to the [CAPDRIVERCAPS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-capdrivercaps) structure to contain the hardware capabilities.

### `wSize`

Size, in bytes, of the structure referenced by *psCaps*.

## Remarks

The capabilities returned in [CAPDRIVERCAPS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-capdrivercaps) are constant for a given capture driver. Applications need to retrieve this information once when the capture driver is first connected to a capture window.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)