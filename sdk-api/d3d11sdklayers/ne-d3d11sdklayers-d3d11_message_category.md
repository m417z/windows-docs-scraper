# D3D11_MESSAGE_CATEGORY enumeration

## Description

Categories of debug messages. This will identify the category of a message when retrieving a message with [ID3D11InfoQueue::GetMessage](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nf-d3d11sdklayers-id3d11infoqueue-getmessage) and when adding a message with [ID3D11InfoQueue::AddMessage](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nf-d3d11sdklayers-id3d11infoqueue-addmessage). When creating an [info queue filter](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ns-d3d11sdklayers-d3d11_info_queue_filter), these values can be used to allow or deny any categories of messages to pass through the storage and retrieval filters.

## Constants

### `D3D11_MESSAGE_CATEGORY_APPLICATION_DEFINED:0`

User defined message. See [ID3D11InfoQueue::AddMessage](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nf-d3d11sdklayers-id3d11infoqueue-addmessage).

### `D3D11_MESSAGE_CATEGORY_MISCELLANEOUS`

### `D3D11_MESSAGE_CATEGORY_INITIALIZATION`

### `D3D11_MESSAGE_CATEGORY_CLEANUP`

### `D3D11_MESSAGE_CATEGORY_COMPILATION`

### `D3D11_MESSAGE_CATEGORY_STATE_CREATION`

### `D3D11_MESSAGE_CATEGORY_STATE_SETTING`

### `D3D11_MESSAGE_CATEGORY_STATE_GETTING`

### `D3D11_MESSAGE_CATEGORY_RESOURCE_MANIPULATION`

### `D3D11_MESSAGE_CATEGORY_EXECUTION`

### `D3D11_MESSAGE_CATEGORY_SHADER`

**Direct3D 11:** This value is not supported until Direct3D 11.1.

## Remarks

This is part of the Information Queue feature. See [ID3D11InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nn-d3d11sdklayers-id3d11infoqueue).

## See also

[Layer Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-layer-enums)