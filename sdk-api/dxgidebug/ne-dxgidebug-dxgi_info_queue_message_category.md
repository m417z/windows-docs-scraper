# DXGI_INFO_QUEUE_MESSAGE_CATEGORY enumeration

## Description

Values that specify categories of debug messages.

## Constants

### `DXGI_INFO_QUEUE_MESSAGE_CATEGORY_UNKNOWN:0`

Unknown category.

### `DXGI_INFO_QUEUE_MESSAGE_CATEGORY_MISCELLANEOUS`

Miscellaneous category.

### `DXGI_INFO_QUEUE_MESSAGE_CATEGORY_INITIALIZATION`

Initialization category.

### `DXGI_INFO_QUEUE_MESSAGE_CATEGORY_CLEANUP`

Cleanup category.

### `DXGI_INFO_QUEUE_MESSAGE_CATEGORY_COMPILATION`

Compilation category.

### `DXGI_INFO_QUEUE_MESSAGE_CATEGORY_STATE_CREATION`

State creation category.

### `DXGI_INFO_QUEUE_MESSAGE_CATEGORY_STATE_SETTING`

State setting category.

### `DXGI_INFO_QUEUE_MESSAGE_CATEGORY_STATE_GETTING`

State getting category.

### `DXGI_INFO_QUEUE_MESSAGE_CATEGORY_RESOURCE_MANIPULATION`

Resource manipulation category.

### `DXGI_INFO_QUEUE_MESSAGE_CATEGORY_EXECUTION`

Execution category.

### `DXGI_INFO_QUEUE_MESSAGE_CATEGORY_SHADER`

Shader category.

## Remarks

Use this enumeration when you call [IDXGIInfoQueue::GetMessage](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nf-dxgidebug-idxgiinfoqueue-getmessage) to retrieve a message and when you call [IDXGIInfoQueue::AddMessage](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nf-dxgidebug-idxgiinfoqueue-addmessage) to add a message. When you create an info queue filter, you can use these values to allow or deny any categories of messages to pass through the storage and retrieval filters.

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)