## Description

Queues a fence into the specified command queue that will signal to the synchronization object when GPU is finished processing the consumer commands. This method signals when the resource is no longer in use and has been released by the consumer.

## Parameters

### `pConsumerCommandQueue`

A pointer to an [ID3D12CommandQueue](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandqueue) representing the consumer command queue onto which the fence should be queued.

## Return value

| Value | Description |
|-------|-------------|
| S_OK | Success |
| MF_E_OPERATION_UNSUPPORTED_AT_D3D_FEATURE_LEVEL | The attempted call or command is not supported with the DirectX version used by the component. |
| o MF_E_UNSUPPORTED_MEDIATYPE_AT_D3D_FEATURE_LEVEL | The specified media type is not supported with the DirectX version used by the component. |

## Remarks

## See also