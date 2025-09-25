# IUIAutomationDragPattern::GetCachedGrabbedItems

## Description

Retrieves a cached collection of elements that represent the full set of items that the user is dragging as part of a drag operation.

## Parameters

### `retVal` [out, retval, optional]

Type: **[IAutomationElementArray](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelementarray)****

The cached collection of elements that the user is dragging. This property is **NULL** or an empty array if only a single item is being dragged. The default value is an empty array.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the user is dragging multiple items, the items are represented by a single master element with an associated set of grabbed elements. The master item fires the appropriate events, to avoid having a large set of duplicate events. The client can query the GrabbedItems property to get the full list of grabbed items.

## See also

[IUIAutomationDragPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationdragpattern)