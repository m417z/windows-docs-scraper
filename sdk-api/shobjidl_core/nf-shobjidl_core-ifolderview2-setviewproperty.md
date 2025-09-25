# IFolderView2::SetViewProperty

## Description

[This method is still implemented, but should be considered deprecated as of Windows 7. It might not be implemented in future versions of Windows. It cannot be used with items in search results or library views, so consider using the item's existing properties or, if applicable, emitting properties from your namespace or property handler. See [Developing Property Handlers for Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-extidx-propertyhandlers) for more information.]

Caches a property for an item in the view's property cache.

## Parameters

### `pidl` [in]

Type: **PCUITEMID_CHILD**

A PIDL that identifies the item.

### `propkey` [in]

Type: **REFPROPERTYKEY**

The [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) which is to be stored.

### `propvar` [in]

Type: **const [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

A pointer to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure in which the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) is stored.

## Return value

Type: **DEPRECATED_HRESULT**

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

The property is displayed in the view, but not written to the underlying item.

## See also

[IFolderView2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderview2)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)

[Property Lists](https://learn.microsoft.com/windows/desktop/properties/building-property-handlers-property-lists)