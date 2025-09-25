# IUIAutomationTextEditPattern::GetActiveComposition

## Description

Returns the active composition.

## Parameters

### `range` [out, retval]

Type: **[IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange)****

Pointer to the range of the current conversion (none if there is no conversion).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Active composition is relevant to Input Method Editors (IMEs).

## See also

[IUIAutomationTextEditPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtexteditpattern)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)