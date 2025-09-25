# WsSetOutputToBuffer function

## Description

This operation positions the Writer at the end of the specified buffer.
When an XML Writer has an XML Buffer set as output the Writer can be used in a "random access" fashion and the functions [WsGetWriterPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetwriterposition), [WsSetWriterPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetwriterposition) and [WsMoveWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmovewriter) can be used.

Properties specified for this function override those specified with the `WsCreateWriter` function.

**Note** See [WsCreateWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatewriter) for the default values of the properties of the writer.

## Parameters

### `writer` [in]

A pointer to the [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) object for which the output is set. The pointer must reference a valid **XML Writer** object.

### `buffer` [in]

A pointer to the buffer where the Writer sends the data.

### `properties`

A WS_XML_WRITER_PROPERTY pointer that references an "array" of optional Writer properties.

### `propertyCount` [in]

The number of properties.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |

## Remarks

See [WsCreateWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatewriter) for the default values of the properties of the writer.