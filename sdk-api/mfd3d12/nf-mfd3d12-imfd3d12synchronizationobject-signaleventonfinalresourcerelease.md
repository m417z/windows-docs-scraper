## Description

Stores an event handle that will be set when the associated D3D12 resource is free and can be recycled, reused, or destroyed.

## Parameters

### `hEvent`

Handle to the event that will be set when the resource is freed.

## Return value

An HRESULT including but not limited to the following values:

| Value | Description |
|-------|-------------|
| S_OK | Success |
| MF_E_OPERATION_UNSUPPORTED_AT_D3D_FEATURE_LEVEL | The attempted call or command is not supported with the DirectX version used by the component. |
| o MF_E_UNSUPPORTED_MEDIATYPE_AT_D3D_FEATURE_LEVEL | The specified media type is not supported with the DirectX version used by the component. |

## Remarks

The handle is signaled when there are no longer any pending resource release or resource ready signals for the current resource. If the event handle has restricted access rights, the handle must have at least the [EVENT_MODIFY_STATE](https://learn.microsoft.com/windows/win32/sync/synchronization-object-security-and-access-rights) right.

## See also