# IEnhancedStorageACT2::GetDeviceName

## Description

The **IEnhancedStorageACT2::GetDeviceName** method returns the device name associated with the Addressable Command Target (ACT).

## Parameters

### `ppwszDeviceName` [out]

Pointer to a string that represents the device name associated with the ACT.

## Return value

This method can return one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The associated volume was successfully returned. |
| **E_INVALIDARG** | *ppwszDeviceName* is **NULL**. |
| **E_OUTOFMEMORY** | The operation failed due to insufficient memory allocation. |

## Remarks

The memory containing the device name string is allocated by the Enhanced Storage API and must be freed by passing the returned pointer to [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## See also

[IEnhancedStorageACT2](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstorageact2)