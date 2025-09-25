# IEnhancedStorageACT2::IsDeviceRemovable

## Description

The **IEnhancedStorageACT2::IsDeviceRemovable** method returns information that indicates if the device associated with the ACT is removable.

## Parameters

### `pIsDeviceRemovable`

Pointer to a boolean value that indicates if the device associated with the ACT is removable.

## Return value

This method can return one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | The information was successfully retrieved. |
| **E_INVALIDARG** | *pIsDeviceRemovable* is **NULL**. |

## See also

[IEnhancedStorageACT2](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstorageact2)