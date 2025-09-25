# IUIAutomationElement3::get_CurrentIsPeripheral

## Description

Retrieves the current peripheral UI indicator for the element.

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

When client applications that are assistive technologies handle one of these events, the client should check the value of **CurrentIsPeripheral**. If the value is **TRUE**, the client may need to provide an alternative representation of the peripheral UI that the user can reach with a single action, because the client can't use changed focus as an indicator of new UI or a UI of interest. The peripheral UI won't otherwise exist in the control view, tab sequence and so on. A client is guaranteed that only one peripheral UI item exists in the overall tree at any one time, opening another would close the first one automatically.

## See also

[IUIAutomationElement3](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement3)

**Reference**