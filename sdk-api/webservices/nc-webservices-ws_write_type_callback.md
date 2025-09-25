# WS_WRITE_TYPE_CALLBACK callback function

## Description

Invoked to write an element when [WS_CUSTOM_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type) has been specified. This allows writing of XML constructs which do not easily
map to the core serialization model.

## Parameters

### `writer` [in]

A **WS_XML_WRITER** pointer to the writer that the value should be written to.

### `typeMapping` [in]

Indicates how the XML is being mapped to this type. See [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) for more information.

If a mapping does not make sense for this particular type, the callback
should return **WS_E_INVALID_OPERATION**. (See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).) A callback implementation
should be prepared to be passed new mapping types in future versions and should return
**WS_E_INVALID_OPERATION** for those cases.

### `descriptionData` [in]

This is the value of the **descriptionData** field of the [WS_CUSTOM_TYPE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_custom_type_description) structure.
The callback uses this field to access any additional information about the type.

### `value`

A **void** pointer to a value to serialize.

### `valueSize` [in]

The size, in bytes, of the value being serialized.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) data structure where additional error information should be stored if the function fails.

## Return value

This callback function does not return a value.

## Remarks

The callback will be invoked with the same calling sequence as
[WsWriteType](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritetype) in the documentation for [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping).
This defines what parts of the XML that the callback should write.