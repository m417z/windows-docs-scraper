# capPaletteManual macro

## Syntax

```cpp
BOOL capPaletteManual(
     hwnd,
     fGrab,
     iColors
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.If an error occurs and an error callback function is set using the **capSetCallbackOnError** macro, the error callback function is called.

## Description

The **capPaletteManual** macro requests that the capture driver manually sample video frames and create a new palette. You can use this macro or explicitly call the [WM_CAP_PAL_MANUALCREATE](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-pal-manualcreate) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `fGrab`

Palette histogram flag. Set this parameter to **TRUE** for each frame included in creating the optimal palette. After the last frame has been collected, set this parameter to **FALSE** to calculate the optimal palette and send it to the capture driver.

### `iColors`

Number of colors in the palette. The maximum value for this parameter is 256. This value is used only during collection of the first frame in a sequence.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)