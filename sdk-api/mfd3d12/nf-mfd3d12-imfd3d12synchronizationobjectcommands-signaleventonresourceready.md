## Description

Stores an event handle that will be set when the D3D12 resource is ready. This event can be used by a CPU thread to wait until the resource producer GPU tasks have finished executing, and the producer fires the resource ready signal.

## Parameters

### `hEvent`

A handle to the event that will be set when the resource is ready.

## Return value

| Value | Description |
|-------|-------------|
| S_OK | Success |
| MF_E_OPERATION_UNSUPPORTED_AT_D3D_FEATURE_LEVEL | The attempted call or command is not supported with the DirectX version used by the component. |
| o MF_E_UNSUPPORTED_MEDIATYPE_AT_D3D_FEATURE_LEVEL | The specified media type is not supported with the DirectX version used by the component. |

## Remarks

If the event handle has restricted access rights, the handle must have at least the [EVENT_MODIFY_STATE](https://learn.microsoft.com/windows/win32/sync/synchronization-object-security-and-access-rights) right. It is the caller's responsibility to close the handle.

## See also