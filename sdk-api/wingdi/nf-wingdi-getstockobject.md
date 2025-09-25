# GetStockObject function

## Description

The **GetStockObject** function retrieves a handle to one of the stock pens, brushes, fonts, or palettes.

## Parameters

### `i` [in]

The type of stock object. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **BLACK_BRUSH** | Black brush. |
| **DKGRAY_BRUSH** | Dark gray brush. |
| **DC_BRUSH** | Solid color brush. The default color is white. The color can be changed by using the [SetDCBrushColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdcbrushcolor) function. For more information, see the Remarks section. |
| **GRAY_BRUSH** | Gray brush. |
| **HOLLOW_BRUSH** | Hollow brush (equivalent to NULL_BRUSH). |
| **LTGRAY_BRUSH** | Light gray brush. |
| **NULL_BRUSH** | Null brush (equivalent to HOLLOW_BRUSH). |
| **WHITE_BRUSH** | White brush. |
| **BLACK_PEN** | Black pen. |
| **DC_PEN** | Solid pen color. The default color is black. The color can be changed by using the [SetDCPenColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdcpencolor) function. For more information, see the Remarks section. |
| **NULL_PEN** | Null pen. The null pen draws nothing. |
| **WHITE_PEN** | White pen. |
| **ANSI_FIXED_FONT** | Windows fixed-pitch (monospace) system font. |
| **ANSI_VAR_FONT** | Windows variable-pitch (proportional space) system font. |
| **DEVICE_DEFAULT_FONT** | Device-dependent font. |
| **DEFAULT_GUI_FONT** | Default font for user interface objects such as menus and dialog boxes. It is not recommended that you use DEFAULT_GUI_FONT or SYSTEM_FONT to obtain the font used by dialogs and windows; for more information, see the remarks section.<br><br>The default font is Tahoma. |
| **OEM_FIXED_FONT** | Original equipment manufacturer (OEM) dependent fixed-pitch (monospace) font. |
| **SYSTEM_FONT** | System font. By default, the system uses the system font to draw menus, dialog box controls, and text. It is not recommended that you use DEFAULT_GUI_FONT or SYSTEM_FONT to obtain the font used by dialogs and windows; for more information, see the remarks section. <br><br>The default system font is Tahoma. |
| **SYSTEM_FIXED_FONT** | Fixed-pitch (monospace) system font. This stock object is provided only for compatibility with 16-bit Windows versions earlier than 3.0. |
| **DEFAULT_PALETTE** | Default palette. This palette consists of the static colors in the system palette. |

## Return value

If the function succeeds, the return value is a handle to the requested logical object.

If the function fails, the return value is **NULL**.

## Remarks

It is not recommended that you employ this method to obtain the current font used by dialogs and windows. Instead, use the [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) function with the SPI_GETNONCLIENTMETRICS parameter to retrieve the current font. [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) will take into account the current theme and provides font information for captions, menus, and message dialogs.

Use the DKGRAY_BRUSH, GRAY_BRUSH, and LTGRAY_BRUSH stock objects only in windows with the CS_HREDRAW and CS_VREDRAW styles. Using a gray stock brush in any other style of window can lead to misalignment of brush patterns after a window is moved or sized. The origins of stock brushes cannot be adjusted.

The HOLLOW_BRUSH and NULL_BRUSH stock objects are equivalent.

It is not necessary (but it is not harmful) to delete stock objects by calling [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject).

Both DC_BRUSH and DC_PEN can be used interchangeably with other stock objects like BLACK_BRUSH and BLACK_PEN. For information on retrieving the current pen or brush color, see [GetDCBrushColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdcbrushcolor) and [GetDCPenColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdcpencolor). See [Setting the Pen or Brush Color](https://learn.microsoft.com/windows/desktop/gdi/setting-the-pen-or-brush-color) for an example of setting colors. The **GetStockObject** function with an argument of DC_BRUSH or DC_PEN can be used interchangeably with the [SetDCPenColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdcpencolor) and [SetDCBrushColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdcbrushcolor) functions.

#### Examples

For an example, see [Setting the Pen or Brush Color](https://learn.microsoft.com/windows/desktop/gdi/setting-the-pen-or-brush-color).

## See also

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)