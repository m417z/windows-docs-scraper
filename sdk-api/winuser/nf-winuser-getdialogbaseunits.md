# GetDialogBaseUnits function

## Description

Retrieves the system's dialog base units, which are the average width and height of characters in the system font. For dialog boxes that use the system font, you can use these values to convert between dialog template units, as specified in dialog box templates, and pixels. For dialog boxes that do not use the system font, the conversion from dialog template units to pixels depends on the font used by the dialog box.

For either type of dialog box, it is easier to use the [MapDialogRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapdialogrect) function to perform the conversion. **MapDialogRect** takes the font into account and correctly converts a rectangle from dialog template units into pixels.

## Return value

Type: **LONG**

The function returns the dialog base units. The low-order word of the return value contains the horizontal dialog box base unit, and the high-order word contains the vertical dialog box base unit.

## Remarks

The horizontal base unit returned by **GetDialogBaseUnits** is equal to the average width, in pixels, of the characters in the system font; the vertical base unit is equal to the height, in pixels, of the font.

The system font is used only if the dialog box template fails to specify a font. Most dialog box templates specify a font; as a result, this function is not useful for most dialog boxes.

For a dialog box that does not use the system font, the base units are the average width and height, in pixels, of the characters in the dialog's font. You can use the [GetTextMetrics](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextmetrics) and [GetTextExtentPoint32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpoint32a) functions to calculate these values for a selected font. However, by using the [MapDialogRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapdialogrect) function, you can avoid errors that might result if your calculations differ from those performed by the system.

Each horizontal base unit is equal to 4 horizontal dialog template units; each vertical base unit is equal to 8 vertical dialog template units. Therefore, to convert dialog template units to pixels, use the following formulas:

```

pixelX = MulDiv(templateunitX, baseunitX, 4);
pixelY = MulDiv(templateunitY, baseunitY, 8);
```

Similarly, to convert from pixels to dialog template units, use the following formulas:

```

templateunitX = MulDiv(pixelX, 4, baseunitX);
templateunitY = MulDiv(pixelY, 8, baseunitY);
```

#### Examples

For an example, see "Creating a Combo Box Toolbar" in [Using Combo Boxes](https://learn.microsoft.com/windows/desktop/Controls/using-combo-boxes).

## See also

**Conceptual**

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[MapDialogRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapdialogrect)

**Reference**