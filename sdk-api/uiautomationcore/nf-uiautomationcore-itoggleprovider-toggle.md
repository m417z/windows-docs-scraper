# IToggleProvider::Toggle

## Description

Cycles through the toggle states of a control.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A control must cycle through its [ToggleState](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-togglestate) in this order:
**ToggleState_On**, **ToggleState_Off**
and, if supported, **ToggleState_Indeterminate**.

## See also

[IToggleProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itoggleprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)