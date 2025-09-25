# UI_SWATCHCOLORTYPE enumeration

## Description

Specifies the values that identify how a color swatch in a [DropDownColorPicker](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-dropdowncolorpicker) or a [FontControl](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-fontcontrol) color picker (**Text color** or **Text highlight**) is filled.

**Note** These are recommendations only. The application can associate any fill type with these values.

## Constants

### `UI_SWATCHCOLORTYPE_NOCOLOR:0`

The swatch is transparent.

### `UI_SWATCHCOLORTYPE_AUTOMATIC:1`

The swatch is filled with a solid RGB color bound to [GetSysColor(COLOR_WINDOWTEXT)](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getsyscolor).

### `UI_SWATCHCOLORTYPE_RGB:2`

The swatch is filled with a solid RGB color.

## See also

[Constants and Enumerations](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-enumerations)