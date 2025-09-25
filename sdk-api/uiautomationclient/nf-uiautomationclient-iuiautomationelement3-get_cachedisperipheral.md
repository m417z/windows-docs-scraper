# IUIAutomationElement3::get_CachedIsPeripheral

## Description

Retrieves the cached peripheral UI indicator for the element. Peripheral UI appears and supports user interaction, but does not take keyboard focus when it appears. Examples of peripheral UI includes popups, flyouts, context menus, or floating notifications.

This property is read-only.

## Parameters

## Remarks

When the **IsPeripheral** property is **TRUE**, a client application can't assume that focus was taken by the element even if it's currently keyboard-interactive.

This property is relevant for these control types:

* **UIA_GroupControlTypeId**
* **UIA_MenuControlTypeId**
* **UIA_PaneControlTypeId**
* **UIA_ToolBarControlTypeId**
* **UIA_ToolTipControlTypeId**
* **UIA_WindowControlTypeId**
* **UIA_CustomControlTypeId**

The appearance of peripheral UI often triggers one of these events, if the peripheral UI supports one of the relevant patterns:

* **WindowOpened** (**UIA_Window_WindowOpenedEventId**)
* **MenuOpened** (**UIA_MenuOpenedEventId**)
* **ToolTipOpened** (**UIA_ToolTipOpenedEventId**)

## See also

[IUIAutomationElement3](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement3)

**Reference**