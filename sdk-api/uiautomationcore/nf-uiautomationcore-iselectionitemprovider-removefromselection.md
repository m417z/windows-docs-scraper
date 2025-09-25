# ISelectionItemProvider::RemoveFromSelection

## Description

Removes the current element from the collection of selected items.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Send an [UIA_SelectionItem_ElementRemovedFromSelectionEventId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids) event as appropriate.

**Note** This rule does not depend on whether the container allows single or multiple selection,
or on what method was used to change the selection. Only the result matters.

## See also

[ISelectionItemProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iselectionitemprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)