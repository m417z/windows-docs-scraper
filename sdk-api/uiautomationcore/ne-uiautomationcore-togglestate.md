# ToggleState enumeration

## Description

Contains values that specify the toggle state of a Microsoft UI Automation element that implements the
[Toggle](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-implementingtoggle) *control pattern*.

## Constants

### `ToggleState_Off:0`

The UI Automation element is not selected, checked, marked or otherwise activated.

### `ToggleState_On:1`

The UI Automation element is selected, checked, marked or otherwise activated.

### `ToggleState_Indeterminate:2`

The UI Automation element is in an indeterminate state.

The Indeterminate property can be used to indicate whether the user has acted
on a control. For example, a check box can appear checked and dimmed, indicating an indeterminate state.

Creating an indeterminate state is different from disabling the control.
Consequently, a check box in the indeterminate state can still receive the focus.
When the user clicks an indeterminate control the ToggleState cycles to its next value.

## See also

[Toggle](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-itoggleprovider-toggle)