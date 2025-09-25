# IEnhancedStorageSiloAction::GetName

## Description

Returns a string for the name of the action specified by the [IEnhancedStorageSiloAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstoragesiloaction) object.

## Parameters

### `ppwszActionName` [out]

Pointer to a string that represents the silo action by name.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The action name was retrieved successfully. |
| **E_INVALIDARG** | The *ppwszActionName* parameter is **NULL**. |

## Remarks

A name string is short, consisting of one or two words, and is suitable for display in a UI element such as a menu item or button label.

When the caller no longer requires access to the string, this buffer must be freed by passing this pointer to [CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree).

## See also

[IEnhancedStorageSiloAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstoragesiloaction)