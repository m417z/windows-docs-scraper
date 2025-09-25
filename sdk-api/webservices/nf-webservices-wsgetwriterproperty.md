# WsGetWriterProperty function

## Description

Retrieves a specified XML Writer property. The property to retrieve is identified by a [WS_XML WRITER_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_writer_property_id) input parameter.

## Parameters

### `writer` [in]

A pointer to a WS_XML_WRITER structure that contains the property value to retrieve.

### `id` [in]

This is a **WS_XML_WRITER_PROPERTY_ID** enumerator that identifies the property to retrieve.

### `value`

A void pointer to a location for storing the retrieved property value.

### `valueSize` [in]

The byte-length buffer size allocated by the caller to store the retrieved property value.
The pointer must have an alignment compatible with the type
of the property.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property id was not supported for this object or the specified buffer was not large enough for the value. |