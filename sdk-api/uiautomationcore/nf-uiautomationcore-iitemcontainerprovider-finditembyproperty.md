# IItemContainerProvider::FindItemByProperty

## Description

Retrieves an element within a containing element, based on a specified property value.

## Parameters

### `pStartAfter` [in]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)***

The UI Automation provider of the element after which the search begins, or **NULL** to search all elements.

### `propertyId` [in]

Type: **PROPERTYID**

The property identifier. For a list of property IDs, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids).

### `value` [in]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)**

The value of the property.

### `pFound` [out]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)****

Receives a pointer to the UI Automation provider of the element.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For virtual lists, the element returned may be a placeholder. [IVirtualizedItemProvider::Realize](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-ivirtualizeditemprovider-realize) can then be used to make the item fully available.

The method returns E_INVALIDARG if searching by the specified property is not supported. Most containers should support [UIA_NamePropertyId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-automation-element-propids) and, if appropriate, [UIA_AutomationIdPropertyId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-automation-element-propids) and [UIA_SelectionItemIsSelectedPropertyId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-control-pattern-propids).

If *propertyId* is 0, all items are a match. This value can be used
with *pStartAfter* equalling **NULL** to get the first item, and then to get successive
items. In this case, *value* should be VT_EMPTY.

## See also

**Conceptual**

[IItemContainerProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iitemcontainerprovider)

[Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids)

**Reference**