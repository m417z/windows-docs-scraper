# DXGI_INFO_QUEUE_MESSAGE structure

## Description

Describes a debug message in the information queue.

## Members

### `Producer`

A [DXGI_DEBUG_ID](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-debug-id) value that identifies the entity that produced the message.

### `Category`

A [DXGI_INFO_QUEUE_MESSAGE_CATEGORY](https://learn.microsoft.com/windows/desktop/api/dxgidebug/ne-dxgidebug-dxgi_info_queue_message_category)-typed value that specifies the category of the message.

### `Severity`

A [DXGI_INFO_QUEUE_MESSAGE_SEVERITY](https://learn.microsoft.com/windows/desktop/api/dxgidebug/ne-dxgidebug-dxgi_info_queue_message_severity)-typed value that specifies the severity of the message.

### `ID`

An integer that uniquely identifies the message.

### `pDescription`

The message string.

### `DescriptionByteLength`

The length of the message string at **pDescription**, in bytes.

## Remarks

[IDXGIInfoQueue::GetMessage](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nf-dxgidebug-idxgiinfoqueue-getmessage) returns a pointer to this structure.

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)