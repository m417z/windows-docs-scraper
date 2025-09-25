# D3D12_MESSAGE structure

## Description

A debug message in the Information Queue.

## Members

### `Category`

The category of the message. See [D3D12_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_message_category).

### `Severity`

The severity of the message. See [D3D12_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_message_severity).

### `ID`

The ID of the message. See [D3D12_MESSAGE_ID](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_message_id).

### `pDescription`

The message string.

### `DescriptionByteLength`

The length of *pDescription*, in bytes.

## Remarks

This structure is returned from [ID3D12InfoQueue::GetMessage](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12infoqueue-getmessage) as part of the Information Queue feature (see [ID3D12InfoQueue](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12infoqueue)).

## See also

[Debug Layer Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-sdklayers-structures)