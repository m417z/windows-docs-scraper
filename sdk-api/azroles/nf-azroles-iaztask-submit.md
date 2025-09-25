# IAzTask::Submit

## Description

The **Submit** method persists changes made to the [IAzTask](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iaztask) object.

## Parameters

### `lFlags` [in, optional]

Flags that modify the behavior of the **Submit** method. The default value is zero. If the **AZ_SUBMIT_FLAG_ABORT** flag is specified, the changes to the object are discarded and the object is updated to match the underlying policy store.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

Any additions or modifications to an [IAzTask](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iaztask) object are not persisted until the **Submit** method is called.

## See also

[IAzTask](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iaztask)