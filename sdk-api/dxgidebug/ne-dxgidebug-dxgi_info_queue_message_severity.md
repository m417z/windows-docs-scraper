# DXGI_INFO_QUEUE_MESSAGE_SEVERITY enumeration

## Description

Values that specify debug message severity levels for an information queue.

## Constants

### `DXGI_INFO_QUEUE_MESSAGE_SEVERITY_CORRUPTION:0`

Defines some type of corruption that has occurred.

### `DXGI_INFO_QUEUE_MESSAGE_SEVERITY_ERROR`

Defines an error message.

### `DXGI_INFO_QUEUE_MESSAGE_SEVERITY_WARNING`

Defines a warning message.

### `DXGI_INFO_QUEUE_MESSAGE_SEVERITY_INFO`

Defines an information message.

### `DXGI_INFO_QUEUE_MESSAGE_SEVERITY_MESSAGE`

Defines a message other than corruption, error, warning, or information.

## Remarks

Use this enumeration when you call [IDXGIInfoQueue::GetMessage](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nf-dxgidebug-idxgiinfoqueue-getmessage) to retrieve a message and when you call [IDXGIInfoQueue::AddMessage](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nf-dxgidebug-idxgiinfoqueue-addmessage) to add a message. Also, use this enumeration with [IDXGIInfoQueue::AddApplicationMessage](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nf-dxgidebug-idxgiinfoqueue-addapplicationmessage).

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)