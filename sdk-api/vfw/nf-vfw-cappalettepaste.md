# capPalettePaste macro

## Syntax

```cpp
BOOL capPalettePaste(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.If an error occurs and an error callback function is set using the **capSetCallbackOnError** macro, the error callback function is called.

## Description

The **capPalettePaste** macro copies the palette from the clipboard and passes it to a capture driver. You can use this macro or explicitly call the [WM_CAP_PAL_PASTE](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-pal-paste) message.

## Parameters

### `hwnd`

Handle to a capture window.

## Remarks

A capture driver uses a palette when required by the specified digitized video format.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)