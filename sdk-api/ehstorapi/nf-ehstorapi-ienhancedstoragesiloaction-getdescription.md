# IEnhancedStorageSiloAction::GetDescription

## Description

Returns a descriptive string for the action specified by the [IEnhancedStorageSiloAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstoragesiloaction) object.

## Parameters

### `ppwszActionDescription` [out]

Pointer to a string that describes the silo action.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The descriptive string was retrieved successfully. |
| **E_INVALIDARG** | The *ppwszDescription* parameter is **NULL**. |

## Remarks

The description string is brief, consisting of one or two short sentences, and is suitable for display in a UI element such as tooltip or small static text box.

When the caller no longer requires access to the string, this buffer must be freed by passing this pointer to [CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree).

## See also

[IEnhancedStorageSiloAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstoragesiloaction)