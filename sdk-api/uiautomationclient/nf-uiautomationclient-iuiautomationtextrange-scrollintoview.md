# IUIAutomationTextRange::ScrollIntoView

## Description

Causes the text control to scroll until the text range is visible in the viewport.

## Parameters

### `alignToTop` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if the text control should be scrolled so that the text range is flush with the top of the viewport; **FALSE** if it should be flush with the bottom of the viewport.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The method respects both hidden and visible text. If the text range is hidden, the text control will scroll only if the hidden text has an anchor in the viewport.

 A Microsoft UI Automation client can check text visibility by calling [IUIAutomationTextRange::GetAttributeValue](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationtextrange-getattributevalue) with the *attr* parameter set to [UIA_IsHiddenAttributeId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-textattribute-ids).

## See also

[IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)