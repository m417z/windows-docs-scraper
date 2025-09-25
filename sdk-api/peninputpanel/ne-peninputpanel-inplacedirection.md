# InPlaceDirection enumeration

## Description

Specifies the preferred direction of the In-Place Input Panel relative to the text entry field.

## Constants

### `InPlaceDirection_Auto:0`

Restores the system default.

### `InPlaceDirection_Bottom:1`

The preferred direction is above the text entry field.

### `InPlaceDirection_Top:2`

The preferred direction is below the text entry field.

## Remarks

An application can specify whether the In-Place Input Panel defaults appear above or below a text entry field by setting the [ITextInputPanel::PreferredInPlaceDirection Property](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-get_preferredinplacedirection) to **InPlaceDirection_Bottom** or **InPlaceDirection_Top**. **ITextInputPanel::PreferredInPlaceDirection Property** is a preference because the In-Place Input Panel overrides the preference set by the application when necessary to keep Input Panel on the screen. The system default is to position the In-Place Input Panel below a text field when possible; otherwise it is positioned above. Setting the **ITextInputPanel::PreferredInPlaceDirection Property** to **InPlaceDirection_Auto** restores the system default.

## See also

[ITextInputPanel::PreferredInPlaceDirection Property](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-get_preferredinplacedirection)