# IUIAutomationTextPattern2::RangeFromAnnotation

## Description

Retrieves a text range containing the text that is the target of the annotation associated with the specified annotation element.

## Parameters

### `annotation` [in]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)***

The annotation element for which to retrieve the target text. This element is a sibling of the element that implements [IUIAutomationTextPattern2](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextpattern2) for the document.

### `range` [out, retval]

Type: **[IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange)****

Receives a text range that contains the target text of the annotation.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUIAutomationTextPattern2](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextpattern2)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)

[Working with Text-based Controls](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithtextbasedcontrols)