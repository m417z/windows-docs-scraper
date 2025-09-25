# ISettingsItem::GetRestrictionFacets

## Description

Gets the restrictions defined for this item.

## Parameters

### `RestrictionFacets` [out]

A bitmask of the [WcmRestrictionFacets](https://learn.microsoft.com/windows/win32/api/wcmconfig/ne-wcmconfig-wcmrestrictionfacets) values that are defined for this item.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **HRESULT_FROM_WIN32 (ERROR_INVALID_OPERATION)** | Indicates that the item is not a scalar setting. |
| **S_FALSE** | Indicates that there is no value for the item. |

## See also

[ISettingsItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsitem)