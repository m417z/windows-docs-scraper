# UI_FONTVERTICALPOSITION enumeration

## Description

Specifies values that identify the vertical-alignment state of a [FontControl](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-fontcontrol).

## Constants

### `UI_FONTVERTICALPOSITION_NOTAVAILABLE:0`

Vertical positioning is not enabled.

### `UI_FONTVERTICALPOSITION_NOTSET:1`

Vertical positioning is enabled but not toggled.

### `UI_FONTVERTICALPOSITION_SUPERSCRIPT:2`

Vertical positioning is enabled and toggled for superscript.

### `UI_FONTVERTICALPOSITION_SUBSCRIPT:3`

Vertical positioning is enabled and toggled for subscript.

## Remarks

**UI_FONTVERTICALPOSITION** is associated with the **Subscript** and **Superscript** toggle buttons of the *RichFont* [FontControl](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-fontcontrol) as shown in the following screen shot.

![Screen shot of the FontControl element with the RichFont attribute set to true.](https://learn.microsoft.com/windows/win32/api/uiribbon/images/FontControl_SubSuper.png)
The **Subscript** and **Superscript** toggle buttons are displayed by default in a [FontControl](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-fontcontrol), depending on the value of the *FontType* attribute.

The **Subscript** and **Superscript** buttons are toggled based on the **UI_FONTVERTICALPOSITION** value in [UI_PKEY_FontProperties_VerticalPositioning](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-properties-uipkey-fontproperties-verticalpositioning).

## See also

[Constants and Enumerations](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-enumerations)

[UI_PKEY_FontProperties_VerticalPositioning](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-properties-uipkey-fontproperties-verticalpositioning)