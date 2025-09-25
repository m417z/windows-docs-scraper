# UI_FONTUNDERLINE enumeration

## Description

Specifies values that identify the underline state of a [FontControl](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-fontcontrol).

## Constants

### `UI_FONTUNDERLINE_NOTAVAILABLE:0`

Underlining is not enabled.

### `UI_FONTUNDERLINE_NOTSET:1`

Underlining is off.

### `UI_FONTUNDERLINE_SET:2`

Underlining is on.

## Remarks

**UI_FONTUNDERLINE** is associated with the **Underline** toggle button of the [FontControl](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-fontcontrol) as shown in the following screen shot.

![Screen shot of the FontControl element with the RichFont attribute set to true.](https://learn.microsoft.com/windows/win32/api/uiribbon/images/FontControl_Underline.png)
The **Underline** toggle button is displayed by default in a [FontControl](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-fontcontrol) but can be hidden, depending on the value of the *FontType* attribute.

The **Underline** button is toggled based on the **UI_FONTUNDERLINE** value in [UI_PKEY_FontProperties_Underline](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-properties-uipkey-fontproperties-underline).

A solid single line is the only underline style supported by the [FontControl](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-fontcontrol).

## See also

[Constants and Enumerations](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-enumerations)

[UI_PKEY_FontProperties_Underline](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-properties-uipkey-fontproperties-underline)