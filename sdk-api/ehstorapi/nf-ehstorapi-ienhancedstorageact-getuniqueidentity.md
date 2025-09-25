# IEnhancedStorageACT::GetUniqueIdentity

## Description

Retrieves the unique identity of the Addressable Command Target (ACT).

## Parameters

### `ppwszIdentity` [out]

Pointer to a string that represents the unique identity of the ACT.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The unique identity was retrieved successfully. |
| **E_INVALIDARG** | *ppwszIdentity* is **NULL**. |

## Remarks

The memory containing the unique identity of the ACT is allocated by the Enhanced Storage API and must be freed by passing the returned pointer to [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## See also

[IEnhancedStorageACT](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstorageact)