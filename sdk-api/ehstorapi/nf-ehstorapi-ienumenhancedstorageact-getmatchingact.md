# IEnumEnhancedStorageACT::GetMatchingACT

## Description

Returns the Addressable Command Target (ACT) associated with the volume specified via the string supplied by the client.

## Parameters

### `szVolume` [in]

A string that specifies the volume for which a matching ACT is searched for.

### `ppIEnhancedStorageACT` [out]

Pointer to an **IEnhancedStorageACT** interface pointer that represents the matching ACT. If no matching ACT is found the error **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** is returned.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | A matching ACT was successfully found. |
| **E_INVALIDARG** | *szVolume* or *ppIEnhancedStorageACT* is **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | A matching ACT wasn't found. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | Enhanced storage is not supported on the device containing *szVolume*. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_FUNCTION)** | Enhanced storage is not supported on the device containing *szVolume*. |

## Remarks

This method can also be utilized by the client to determine if the specified volume resides on, and is represented by an IEEE 1667 ACT.

## See also

[IEnumEnhancedStorageACT](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienumenhancedstorageact)