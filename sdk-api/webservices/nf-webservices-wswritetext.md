# WsWriteText function

## Description

Writes the specified text to the XML writer.

To write characters to an attribute value call [WsWriteStartAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritestartattribute). Only whitespace characters may be written at the root of an xml document unless the **WS_XML_WRITER_PROPERTY_ALLOW_FRAGMENT** has been set to **TRUE**.

## Parameters

### `writer` [in]

A pointer to the [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) object to which the text is written. The pointer must reference a valid **XML Writer** object.

### `text` [in]

A pointer to the text to write.

**Note** See [WS_XML_TEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_text) and its derived classes for more information on the text object.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |

## Remarks

**WsWriteText** can be called only once between [WsWriteStartAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritestartattribute) and [WsWriteEndAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswriteendattribute)
unless the text type is one of the following:

* **WS_XML_TEXT_TYPE_UTF8**
* **WS_XML_TEXT_TYPE_UTF16**
* **WS_XML_TEXT_TYPE_BASE64**

**Note** If the text Type is set to either of the previous values WsWriteText can be called more than once. However the text Type must be the same for all calls within an attribute.