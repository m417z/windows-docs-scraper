# capPaletteAuto macro

## Syntax

```cpp
BOOL capPaletteAuto(
     hwnd,
     iFrames,
     iColors
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.If an error occurs and an error callback function is set using the **capSetCallbackOnError** macro, the error callback function is called.

## Description

The **capPaletteAuto** macro requests that the capture driver sample video frames and automatically create a new palette. You can use this macro or explicitly call the [WM_CAP_PAL_AUTOCREATE](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-pal-autocreate) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `iFrames`

Number of frames to sample.

### `iColors`

Number of colors in the palette. The maximum value for this parameter is 256.

## Remarks

The sampled video sequence should include all the colors you want in the palette. To obtain the best palette, you might have to sample the whole sequence rather than a portion of it.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)