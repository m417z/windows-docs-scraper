# ISelectionProvider::get_IsSelectionRequired

## Description

Indicates whether the Microsoft UI Automation provider requires at least one child element to be selected.

This property is read-only.

## Parameters

## Remarks

This property can be dynamic. For example, the initial state of a control might
not have any items selected by default, meaning that **ISelectionProvider::IsSelectionRequired** is **FALSE**.
However, after an item is selected the control must always have at least one item selected.

## See also

[ISelectionProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iselectionprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)