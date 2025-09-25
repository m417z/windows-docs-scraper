# IEnumEnhancedStorageACT::GetACTs

## Description

Returns an enumeration of all the Addressable Command Targets (ACT) currently connected to the system. If at least one ACT is present, the Enhanced Storage API allocates an array of 1 or more [IEnumEnhancedStorageACT](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienumenhancedstorageact) pointers.

## Parameters

### `pppIEnhancedStorageACTs` [out]

Array of [IEnhancedStorageACT](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstorageact) interface pointers that represent the ACTs for all devices connected to the system. This array is allocated within the API.

### `pcEnhancedStorageACTs`

Count of [IEnhancedStorageACT](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstorageact) pointers returned. This is the dimension of the array represented by *pppIEnhancedStorageACTs*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | One or more ACTs were found. |
| **E_INVALIDARG** | pppIEnhancedStorageACTs or pcEnhancedStorageACTs is **NULL**. |
| **E_OUTOFMEMORY** | Operation failed due to insufficient memory. |

## Remarks

The memory containing the array of [IEnhancedStorageACT](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstorageact) interfaces is allocated by the Enhanced Storage API and must be freed by passing the returned pointer to the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) method.

## See also

[IEnumEnhancedStorageACT](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienumenhancedstorageact)