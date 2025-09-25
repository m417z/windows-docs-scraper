## Description

Queues a wait command on the specified consumer command queue, starting a wait for the
resource ready signal from the producer command queue.

## Parameters

### `pConsumerCommandQueue`

A pointer to an [ID3D12CommandQueue](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandqueue) representing the consumer command queue into which the wait should be queued.

## Return value

An HRESULT including but not limited to the following values:

| Value | Description |
|-------|-------------|
| S_OK | Success |
| MF_E_OPERATION_UNSUPPORTED_AT_D3D_FEATURE_LEVEL | The attempted call or command is not supported with the DirectX version used by the component. |
| o MF_E_UNSUPPORTED_MEDIATYPE_AT_D3D_FEATURE_LEVEL | The specified media type is not supported with the DirectX version used by the component. |

## Remarks

This function allows the consumer to immediately start scheduling commands for its GPU engine. The wait will ensure that the commands scheduled after the wait are not executed until the corresponding ready signal is fired by the producer GPU engine.

## See also