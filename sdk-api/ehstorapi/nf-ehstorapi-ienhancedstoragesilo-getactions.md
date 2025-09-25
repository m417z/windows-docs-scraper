# IEnhancedStorageSilo::GetActions

## Description

Returns an enumeration of all actions available to the silo object.

## Parameters

### `pppIEnhancedStorageSiloActions` [out]

Array of pointers to [IEnhancedStorageAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstoragesiloaction) interface objects that represent the actions available for the silo object. This array is allocated within the API when at least one action is available to the silo.

### `pcEnhancedStorageSiloActions` [out]

Count of [IEnhancedStorageAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstoragesiloaction) pointers returned. This value indicates the dimension of the array represented by *pppIEnhancedStorageSilos*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | One or more ACTs were found. |
| **E_INVALIDARG** | *pppIEnhancedStorageSiloActions* or *pcEnhancedStorageSiloActions* is **NULL**. |

## Remarks

The memory containing the [IEnhancedStorageAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstoragesiloaction) interface pointers is allocated by the Enhanced Storage API and must be freed by passing the returned pointer to [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## See also

[IEnhancedStorageSilo](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstoragesilo)