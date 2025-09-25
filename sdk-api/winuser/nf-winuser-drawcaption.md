# DrawCaption function

## Description

The **DrawCaption** function draws a window caption.

## Parameters

### `hwnd` [in]

A handle to a window that supplies text and an icon for the window caption.

### `hdc` [in]

A handle to a device context. The function draws the window caption into this device context.

### `lprect` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the bounding rectangle for the window caption in logical coordinates.

### `flags` [in]

The drawing options. This parameter can be zero or more of the following values.

| Value | Meaning |
| --- | --- |
| **DC_ACTIVE** | The function uses the colors that denote an active caption. |
| **DC_BUTTONS** | If set, the function draws the buttons in the caption bar (to minimize, restore, or close an application). |
| **DC_GRADIENT** | When this flag is set, the function uses COLOR_GRADIENTACTIVECAPTION (if the DC_ACTIVE flag was set) or COLOR_GRADIENTINACTIVECAPTION for the title-bar color.<br><br>If this flag is not set, the function uses COLOR_ACTIVECAPTION or COLOR_INACTIVECAPTION for both colors. |
| **DC_ICON** | The function draws the icon when drawing the caption text. |
| **DC_INBUTTON** | The function draws the caption as a button. |
| **DC_SMALLCAP** | The function draws a small caption, using the current small caption font. |
| **DC_TEXT** | The function draws the caption text when drawing the caption. |

If DC_SMALLCAP is specified, the function draws a normal window caption.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## See also

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)