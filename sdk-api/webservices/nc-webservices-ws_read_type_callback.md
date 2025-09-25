# WS_READ_TYPE_CALLBACK callback function

## Description

Reads a value when [WS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type) has been specified. This allows reading of XML constructs which do not easily
map to the core serialization model.

## Parameters

### `reader` [in]

A pointer to a [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) handle that contains the type value.

### `typeMapping` [in]

Indicates how the XML is being mapped to this type.

If a mapping does not make sense for this particular type, then the callback
should return **WS_E_INVALID_OPERATION**. (See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).) A callback implementation
should be prepared to be passed new mapping types in future versions and should return
**WS_E_INVALID_OPERATION** for those cases.

### `descriptionData` [in]

 A pointer to the value of the **descriptionData** field of a [WS_CUSTOM_TYPE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_custom_type_description) structure.
The callback can use this to gain access to any additional information about the type.

### `heap` [in, optional]

A pointer to the heap for use in allocating any additional data associated with this type such as its nested fields.

Note that this parameter may be **NULL**,
if the caller did not specify a [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap) object when deserializing
the type.

### `value`

A pointer to a buffer that holds the value that is being deserialized.
The callback is responsible for filling in the value based on the current
contents of the reader and the typeMapping.
The callback can use the supplied heap if necessary to allocate
values associated with the value.

### `valueSize` [in]

The buffer size that is being deserialized.
The buffer is allocated according to the size specified in the
[WS_CUSTOM_TYPE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_custom_type_description).

### `error` [in, optional]

A pointer to [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) data structure where additional error information should be stored if the function fails.

## Return value

This callback function does not return a value.

## Remarks

The callback will be invoked with the same calling sequence as
[WsReadType](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadtype) in the documentation for [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping).
This defines what parts of the XML that the callback should read.