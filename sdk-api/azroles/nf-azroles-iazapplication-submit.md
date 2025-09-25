# IAzApplication::Submit

## Description

The **Submit** method persists changes made to the [IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication) object.

## Parameters

### `lFlags` [in]

Flags that modify the behavior of the **Submit** method. The default value is zero. If the **AZ_SUBMIT_FLAG_ABORT** flag is specified, the changes to the object are discarded and the object is updated to match the underlying policy store.

### `varReserved` [in, optional]

Reserved for future use.

## Return value

If the method succeeds, it will return `S_OK`. Any other **HRESULT** value indicates that the operation failed.

## Remarks

Any additions or modifications to an [IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication) object are not persisted until the **Submit** method is called.

The **Submit** method does not extend to child objects; child objects must be individually persisted to the policy store. A created [IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication) object must be submitted before it can be referenced or become a parent object. The destructor for an object silently discards unsubmitted changes.

## See also

[IAzApplication](https://learn.microsoft.com/windows/win32/api/azroles/nn-azroles-iazapplication)