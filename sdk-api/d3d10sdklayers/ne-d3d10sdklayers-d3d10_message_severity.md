# D3D10_MESSAGE_SEVERITY enumeration

## Description

Debug message severity levels for an information queue.

## Constants

### `D3D10_MESSAGE_SEVERITY_CORRUPTION:0`

Defines some type of corruption which has occurred.

### `D3D10_MESSAGE_SEVERITY_ERROR`

Defines an error message.

### `D3D10_MESSAGE_SEVERITY_WARNING`

Defines a warning message.

### `D3D10_MESSAGE_SEVERITY_INFO`

Defines an information message.

### `D3D10_MESSAGE_SEVERITY_MESSAGE`

## Remarks

Use these values to allow or deny message categories to pass through the storage and retrieval filters for an information queue (see [D3D10_INFO_QUEUE_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ns-d3d10sdklayers-d3d10_info_queue_filter)). This API is used by [ID3D10InfoQueue::AddApplicationMessage](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nf-d3d10sdklayers-id3d10infoqueue-addapplicationmessage).

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-enums)