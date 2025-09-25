# IEnhancedStorageACT::GetSilos

## Description

Returns an enumeration of all silos associated with the Addressable Command Target (ACT).

## Parameters

### `pppIEnhancedStorageSilos` [out]

Returns an array of one or more [IEnhancedStorageSilo](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstoragesilo) interface pointers associated with the ACT.

### `pcEnhancedStorageSilos` [out]

Count of [IEnhancedStorageSilo](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstoragesilo) pointers returned. This value indicates the dimension of the array represented by *pppIEnhancedStorageSilos*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Command was sent successfully and all associated silos have been enumerated. |
| **E_OUTOFMEMORY** | Command failed due to insufficient memory allocation. |
| **E_INVALIDARG** | *pppIEnhancedStorageSilos* or *pcEnhancedStorageSilos* is **NULL**. |

## Remarks

The memory containing the array of [IEnhancedStorageSilo](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstoragesilo) interfaces is allocated by the Enhanced Storage API and must be freed by passing the returned pointer to [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## See also

[IEnhancedStorageACT](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstorageact)

[IEnhancedStorageSilo](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstoragesilo)