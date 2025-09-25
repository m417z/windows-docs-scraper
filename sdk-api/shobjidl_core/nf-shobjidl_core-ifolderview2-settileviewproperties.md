# IFolderView2::SetTileViewProperties

## Description

[This method is still implemented, but should be considered deprecated as of Windows 7. It might not be implemented in future versions of Windows. It cannot be used with items in search results or library views, so consider using the item's existing properties or, if applicable, emitting properties from your namespace or property handler. See [Developing Property Handlers for Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-extidx-propertyhandlers) for more information.]

Set the list of tile properties for an item.

## Parameters

### `pidl` [in]

Type: **PCUITEMID_CHILD**

A pointer to an item identifier list (PIDL).

### `pszPropList` [in]

Type: **LPCWSTR**

A pointer to a Unicode string containing a list of properties.

## Return value

Type: **DEPRECATED_HRESULT**

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

The *pszPropList* parameter must be of the form "prop:<canonical-property-name>;<canonical-property-name>" where "<canonical-property-name>" is replaced by an actual canonical property name. The parameter can contain one or more properties delimited by semicolons.

## See also

[IFolderView2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderview2)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)

[Property Lists](https://learn.microsoft.com/windows/desktop/properties/building-property-handlers-property-lists)