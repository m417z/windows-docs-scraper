# ISelectionItemProvider::AddToSelection

## Description

Adds the current element to the collection of selected items.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the result of a call to **ISelectionItemProvider::AddToSelection** is that a single item is selected, then
send an [UIA_SelectionItem_ElementSelectedEventId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids) event for that element; otherwise send an [UIA_SelectionItem_ElementAddedToSelectionEventId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids) or
[UIA_SelectionItem_ElementRemovedFromSelectionEventId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids) event as appropriate.

**Note** This rule does not depend on whether the container allows single or multiple selection,
or on what method was used to change the selection. Only the result matters.

## See also

[ISelectionItemProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iselectionitemprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)