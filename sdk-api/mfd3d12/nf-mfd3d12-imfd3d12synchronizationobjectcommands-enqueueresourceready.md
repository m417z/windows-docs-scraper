## Description

Queues a fence on the specified producer command queue that will signal to a downstream consumer when the associated D3D12 resource is ready to be used. This method also signals that the resource is no longer in use and has been released by the producer.

## Parameters

### `pProducerCommandQueue`

A pointer to an [ID3D12CommandQueue](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12commandqueue) representing the producer command queue into which the fence should be inserted.

## Return value

An HRESULT including but not limited to the following values:

| Value | Description |
|-------|-------------|
| S_OK | Success |
| MF_E_OPERATION_UNSUPPORTED_AT_D3D_FEATURE_LEVEL | The attempted call or command is not supported with the DirectX version used by the component. |
| o MF_E_UNSUPPORTED_MEDIATYPE_AT_D3D_FEATURE_LEVEL | The specified media type is not supported with the DirectX version used by the component. |

## Remarks

This method will be used by a producer to signal to a down-stream consumer when all the GPU commands that the producer scheduled for the resource have been processed. The signal indicates that the resource is ready for consumption by the consumer.

## See also