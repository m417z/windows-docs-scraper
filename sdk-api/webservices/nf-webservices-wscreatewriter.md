# WsCreateWriter function

## Description

creates an [XML Writer](https://learn.microsoft.com/windows/desktop/wsw/xml-writer) with the specified properties.

## Parameters

### `properties`

An array of [WS_XML_WRITER_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_writer_property) structures containing optional properties for the XML writer.

The value of this parameter may be **NULL**, in which case, the *propertyCount* parameter must be 0 (zero).

### `propertyCount` [in]

The number of properties in the *properties* array.

### `writer`

On success, a pointer that receives the address of the [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) structure representing the created XML writer.
When you no longer need this structure, you must free it by calling [WsFreeWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreewriter).

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |

## Remarks

Use the [WsSetOutput](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetoutput) or [WsSetOutputToBuffer](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetoutputtobuffer) functions to choose the encoding of the XML writer and to indicate where to direct the output.

A [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) can be reused by calling [WsSetOutput](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetoutput) or [WsSetOutputToBuffer](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetoutputtobuffer) again.

See [WS_XML_WRITER_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_writer_property_id) for the properties that can be used to configure the writer.

The XML writer buffers all data until [WsFlushWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsflushwriter) is called. This allows the caller to determine at what granularity to write data and to whether to write that data asynchronously. Data is not written until **WsFlushWriter** is called.

If an operation on a [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) fails the writer is left in a faulted state and further calls to the Writer return **WS_E_OBJECT_FAULTED**. (See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)The only possible function calls for the XML writer if this occurs are [WsSetOutput](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetoutput) and [WsSetOutputToBuffer](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetoutputtobuffer) to return the XML writer to a usable state, or [WsFreeWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreewriter) to free the XML writer.