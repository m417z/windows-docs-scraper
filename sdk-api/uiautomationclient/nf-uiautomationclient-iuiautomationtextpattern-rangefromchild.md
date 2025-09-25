# IUIAutomationTextPattern::RangeFromChild

## Description

Retrieves a text range enclosing a child element such as an image, hyperlink, Microsoft Excel spreadsheet, or other embedded object.

## Parameters

### `child` [in]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)***

A pointer to the child element to be enclosed in the text range.

### `range` [out, retval]

Type: **[IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange)****

Receives a pointer to a text range that encloses the child element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If there is no text in the range that encloses the child element, a degenerate (empty) range is returned.

The *child* parameter is either a child of the element associated with a [IUIAutomationTextPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextpattern) or from the array of children of a [IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange).

## See also

[IUIAutomationTextPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextpattern)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)