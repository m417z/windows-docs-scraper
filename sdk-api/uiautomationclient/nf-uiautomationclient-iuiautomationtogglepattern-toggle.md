# IUIAutomationTogglePattern::Toggle

## Description

Cycles through the toggle states of the control.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A control cycles through its states in this order: [ToggleState_On](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-togglestate), [ToggleState_Off](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-togglestate) and, if supported, [ToggleState_Indeterminate](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-togglestate).