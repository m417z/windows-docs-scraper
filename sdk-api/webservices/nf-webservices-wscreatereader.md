# WsCreateReader function

## Description

Creates an [XML reader](https://learn.microsoft.com/windows/desktop/wsw/xml-reader) with the specified properties.

## Parameters

### `properties`

An array of [WS_XML_READER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_property) structures containing optional properties for the XML reader.

The value of this parameter may be **NULL**, in which case, the *propertyCount* parameter must be 0 (zero).

For the properties that tiy can use to configure the XML reader, see the [WS_XML_READER_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_reader_property_id) enumeration.

### `propertyCount` [in]

The number of properties in the *properties* array.

### `reader`

On success, a pointer that receives the address of the [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) structure representing the new XML reader.
When you no longer need this structure, you must free it by calling [WsFreeReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreereader).

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

## Remarks

Use [WsSetInput](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetinput) or [WsSetInputToBuffer](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetinputtobuffer) functions to choose the encoding for the XML reader and to indicate the source of the input.

If [WS_READ_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_read_callback) is specified in the [WS_XML_READER_INPUT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_input) structure passed to the [WsSetInput](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetinput) function, the XML reader reads
additional data only when [WsFillReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfillreader) is called. This allows the caller to determine
at what granularity to read data and whether to read that data asynchronously.

A [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) structure can be reused by calling [WsSetInput](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetinput) or [WsSetInputToBuffer](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetinputtobuffer) again.

If any API operation that operates on an [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) fails the XML reader is left in a faulted state
and further function calls return **WS_E_OBJECT_FAULTED**. (See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).) The only possible function calls for the XML reader
if this occurs are [WsSetInput](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetinput) and [WsSetInputToBuffer](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetinputtobuffer) for returning the XML reader to a usable state,
or [WsFreeReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreereader) for releasing the XML reader object.