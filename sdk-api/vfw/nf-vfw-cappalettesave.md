# capPaletteSave macro

## Syntax

```cpp
BOOL capPaletteSave(
     hwnd,
     szName
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.If an error occurs and an error callback function is set using the **capSetCallbackOnError** macro, the error callback function is called.

## Description

The **capPaletteSave** macro saves the current palette to a palette file. Palette files typically use the filename extension .PAL. You can use this macro or explicitly send the [WM_CAP_PAL_SAVE](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-pal-save) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `szName`

Pointer to a null-terminated string containing the palette filename.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)