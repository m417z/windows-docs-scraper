# Graphics::Graphics(IN HWND,IN BOOL)

## Description

Creates a **Graphics::Graphics** object that is associated with a specified window.

## Parameters

### `hwnd` [in]

Type: **HWND**

Handle to a window that will be associated with the new **Graphics::Graphics** object.

### `icm` [in]

Type: **BOOL**

Optional. Boolean value that specifies whether the new **Graphics::Graphics** object applies color adjustment according to the ICC profile associated with the display device. **TRUE** specifies that color adjustment is applied, and **FALSE** specifies that color adjustment is not applied. The default value is **FALSE**.

## See also

[Changes in the Programming Model](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-changes-in-the-programming-model-about)

[Getting Started](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-getting-started-use)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics Constructors](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-graphics(constgraphics_))