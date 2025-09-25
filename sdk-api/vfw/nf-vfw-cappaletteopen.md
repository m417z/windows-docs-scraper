# capPaletteOpen macro

## Syntax

```cpp
BOOL capPaletteOpen(
     hwnd,
     szName
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.If an error occurs and an error callback function is set using the **capSetCallbackOnError** macro, the error callback function is called.

## Description

The **capPaletteOpen** macro loads a new palette from a palette file and passes it to a capture driver. Palette files typically use the filename extension .PAL. A capture driver uses a palette when required by the specified digitized image format. You can use this macro or explicitly call the [WM_CAP_PAL_OPEN](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-pal-open) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `szName`

Pointer to a null-terminated string containing the palette filename.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)