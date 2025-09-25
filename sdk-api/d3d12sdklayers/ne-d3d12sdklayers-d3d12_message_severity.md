# D3D12_MESSAGE_SEVERITY enumeration

## Description

Debug message severity levels for an information queue.

## Constants

### `D3D12_MESSAGE_SEVERITY_CORRUPTION:0`

Indicates a corruption error.

### `D3D12_MESSAGE_SEVERITY_ERROR`

Indicates an error.

### `D3D12_MESSAGE_SEVERITY_WARNING`

Indicates a warning.

### `D3D12_MESSAGE_SEVERITY_INFO`

Indicates an information message.

### `D3D12_MESSAGE_SEVERITY_MESSAGE`

Indicates a message other than corruption, error, warning or information.

## Remarks

Use these values to allow or deny message categories to pass through the storage and retrieval filters for an information queue (see [D3D12_INFO_QUEUE_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ns-d3d12sdklayers-d3d12_info_queue_filter)). This API is used by [AddApplicationMessage](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12infoqueue-addapplicationmessage) and [AddMessage](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12infoqueue-addmessage).

## See also

[Debug Layer Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-sdklayers-enumerations)