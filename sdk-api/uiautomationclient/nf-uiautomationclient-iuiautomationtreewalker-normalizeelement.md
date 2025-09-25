# IUIAutomationTreeWalker::NormalizeElement

## Description

Retrieves the ancestor element nearest to the specified Microsoft UI Automation element in the tree view.

## Parameters

### `element` [in]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)***

A pointer to the element from which to start the normalization.

### `normalized` [out, retval]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)****

Receives a pointer to the ancestor element nearest to the specified element in the tree view.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The element is normalized by navigating up the ancestor chain in the tree until an element that satisfies the view condition (specified by a previous call to [IUIAutomationTreeWalker::Condition](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationtreewalker-get_condition)) is reached. But first, the passed element is tested to see if it matches a normalization condition. If so, the passed element is returned, even though it is not an ancestor.

 The method returns **UIA_E_ELEMENTNOTAVAILABLE** if no matching element has been found.

This method is useful for applications that obtain references to UI Automation elements by hit-testing. The application might want to work only with specific types of elements, and can use **IUIAutomationTreeWalker::Normalize** to make sure that no matter what element is initially retrieved (for example, when a scroll bar gets the input focus), only the element of interest (such as a content element) is ultimately retrieved.