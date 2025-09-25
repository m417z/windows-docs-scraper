# D3D11_MESSAGE_SEVERITY enumeration

## Description

Debug message severity levels for an information queue.

## Constants

### `D3D11_MESSAGE_SEVERITY_CORRUPTION:0`

Defines some type of corruption which has occurred.

### `D3D11_MESSAGE_SEVERITY_ERROR`

Defines an error message.

### `D3D11_MESSAGE_SEVERITY_WARNING`

Defines a warning message.

### `D3D11_MESSAGE_SEVERITY_INFO`

Defines an information message.

### `D3D11_MESSAGE_SEVERITY_MESSAGE`

Defines a message other than corruption, error, warning, or information.

**Direct3D 11:** This value is not supported until Direct3D 11.1.

## Remarks

Use these values to allow or deny message categories to pass through the storage and retrieval filters for an information queue (see [D3D11_INFO_QUEUE_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ns-d3d11sdklayers-d3d11_info_queue_filter)). This API is used by [ID3D11InfoQueue::AddApplicationMessage](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nf-d3d11sdklayers-id3d11infoqueue-addapplicationmessage).

## See also

[Layer Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-layer-enums)