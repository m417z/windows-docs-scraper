# ISettingsItem::GetRestriction

## Description

Gets the information for a given restriction.

## Parameters

### `RestrictionFacet` [in]

A [WcmRestrictionFacets](https://learn.microsoft.com/windows/win32/api/wcmconfig/ne-wcmconfig-wcmrestrictionfacets) value that indicates the type of restriction facet.

### `FacetData` [out]

A pointer to the facet data.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **HRESULT_FROM_WIN32 (ERROR_INVALID_OPERATION)** | Indicates that the method was called on a non-scalar setting. |
| **E_INVALIDARG** | Indicates that the requested restriction facet is not defined for this item. |

## See also

[ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem)