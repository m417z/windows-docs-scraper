# IUIAutomationItemContainerPattern::FindItemByProperty

## Description

Retrieves an element within a containing element, based on a specified property value.

## Parameters

### `pStartAfter` [in]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)***

A pointer to the element after which the search begins, or **NULL** to search all elements.

### `propertyId` [in]

Type: **PROPERTYID**

The property identifier. For a list of property IDs, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids).

### `value` [in]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant)**

The property value.

### `pFound` [out, retval]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)****

Receives a pointer to the matching element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The provider may return an actual [IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement) interface or a placeholder if the matching element is virtualized.

This method returns E_INVALIDARG if the property requested is not one that the container supports searching over. It is expected that most containers will support Name property, and if appropriate for the container, AutomationId and IsSelected.

This method can be slow, because it may need to traverse multiple objects to find a matching one. When used in a loop to return multiple items, no specific order is defined so long as each item is returned only once (that is, the loop should terminate). This method is also item-centric, not UI-centric, so items with multiple UI representations need to be hit only once.

When the *propertyId* parameter is specified as 0 (zero), the provider is expected to return the next item after *pStartAfter*. If *pStartAfter* is specified as **NULL** with a *propertyId* of 0, the provider should return the first item in the container. When *propertyId* is specified as 0, the *value* parameter should be VT_EMPTY.

## See also

[IUIAutomationItemContainerPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationitemcontainerpattern)

[Realize](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationvirtualizeditempattern-realize)

**Reference**