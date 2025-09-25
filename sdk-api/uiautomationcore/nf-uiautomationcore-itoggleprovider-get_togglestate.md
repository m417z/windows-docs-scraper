# IToggleProvider::get_ToggleState

## Description

Specifies the toggle state of the control.

This property is read-only.

## Parameters

## Remarks

A control must cycle through its [ToggleState](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-togglestate) in this order:
**ToggleState_On**, **ToggleState_Off**
and, if supported, **ToggleState_Indeterminate**.

## See also

[IToggleProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itoggleprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)