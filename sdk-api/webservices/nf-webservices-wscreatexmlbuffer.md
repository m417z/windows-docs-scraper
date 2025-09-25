# WsCreateXmlBuffer function

## Description

Creates an [XML Buffer](https://learn.microsoft.com/windows/desktop/wsw/xml-buffer) which can be used to process XML data .

## Parameters

### `heap` [in]

Pointer to the [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap) structure representing the [heap](https://learn.microsoft.com/windows/desktop/wsw/heap) from which to allocate memory for the returned XML buffer.

### `properties`

An array of [WS_XML_BUFFER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_buffer_property) structures containing optional properties for the XML buffer.

The value of this parameter may be **NULL**, in which case, the *propertyCount* parameter must be 0 (zero).

### `propertyCount` [in]

The number of properties in the *properties* array.

### `buffer`

On success, a pointer that receives the address of the [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer) structure representing the created XML buffer. The memory for this buffer is released when its heap is reset or released.

The XML buffer is initially empty.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_INVALIDARG** | One or more arguments are invalid. |