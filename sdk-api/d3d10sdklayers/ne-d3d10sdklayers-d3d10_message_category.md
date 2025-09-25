# D3D10_MESSAGE_CATEGORY enumeration

## Description

Categories of debug messages. This will identify the category of a message when retrieving a message with [ID3D10InfoQueue::GetMessage](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nf-d3d10sdklayers-id3d10infoqueue-getmessage) and when adding a message with [ID3D10InfoQueue::AddMessage](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nf-d3d10sdklayers-id3d10infoqueue-addmessage). When creating an [info queue filter](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ns-d3d10sdklayers-d3d10_info_queue_filter), these values can be used to allow or deny any categories of messages to pass through the storage and retrieval filters.

## Constants

### `D3D10_MESSAGE_CATEGORY_APPLICATION_DEFINED:0`

User defined message. See [ID3D10InfoQueue::AddMessage](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nf-d3d10sdklayers-id3d10infoqueue-addmessage).

### `D3D10_MESSAGE_CATEGORY_MISCELLANEOUS`

### `D3D10_MESSAGE_CATEGORY_INITIALIZATION`

### `D3D10_MESSAGE_CATEGORY_CLEANUP`

### `D3D10_MESSAGE_CATEGORY_COMPILATION`

### `D3D10_MESSAGE_CATEGORY_STATE_CREATION`

### `D3D10_MESSAGE_CATEGORY_STATE_SETTING`

### `D3D10_MESSAGE_CATEGORY_STATE_GETTING`

### `D3D10_MESSAGE_CATEGORY_RESOURCE_MANIPULATION`

### `D3D10_MESSAGE_CATEGORY_EXECUTION`

### `D3D10_MESSAGE_CATEGORY_SHADER`

## Remarks

This is part of the Information Queue feature. See [ID3D10InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10infoqueue).

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-enums)