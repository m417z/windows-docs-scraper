# D3D12_MESSAGE_CATEGORY enumeration

## Description

Specifies categories of debug messages. This will identify the category of a message when retrieving a message with [ID3D12InfoQueue::GetMessage](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12infoqueue-getmessage) and when adding a message with [ID3D12InfoQueue::AddMessage](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12infoqueue-addmessage). When creating an info queue filter, these values can be used to allow or deny any categories of messages to pass through the storage and retrieval filters.

## Constants

### `D3D12_MESSAGE_CATEGORY_APPLICATION_DEFINED:0`

Indicates a user defined message, see [ID3D12InfoQueue::AddMessage](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12infoqueue-addmessage).

### `D3D12_MESSAGE_CATEGORY_MISCELLANEOUS`

### `D3D12_MESSAGE_CATEGORY_INITIALIZATION`

### `D3D12_MESSAGE_CATEGORY_CLEANUP`

### `D3D12_MESSAGE_CATEGORY_COMPILATION`

### `D3D12_MESSAGE_CATEGORY_STATE_CREATION`

### `D3D12_MESSAGE_CATEGORY_STATE_SETTING`

### `D3D12_MESSAGE_CATEGORY_STATE_GETTING`

### `D3D12_MESSAGE_CATEGORY_RESOURCE_MANIPULATION`

### `D3D12_MESSAGE_CATEGORY_EXECUTION`

### `D3D12_MESSAGE_CATEGORY_SHADER`

## Remarks

This is part of the Information Queue feature, refer to the [ID3D12InfoQueue](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12infoqueue) Interface.

## See also

[Debug Layer Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-sdklayers-enumerations)