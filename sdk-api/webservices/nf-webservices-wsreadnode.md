# WsReadNode function

## Description

This operation advances the Reader to the next [node](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_node) in the input stream.
If there is an error parsing the input the function will return **WS_E_INVALID_FORMAT**.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)

## Parameters

### `reader` [in]

A pointer to the **XML Reader** object to advance.
The pointer must reference a valid [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) and it may not be **NULL**.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format, or did not have the expected value, or multiple top-level elements were found and **WS_XML_READER_PROPERTY_ALLOW_FRAGMENT** is **FALSE**. |
| **WS_E_QUOTA_EXCEEDED** | An element was read that exceeded some limit such as **WS_XML_READER_PROPERTY_MAX_DEPTH** or **WS_XML_READER_PROPERTY_MAX_ATTRIBUTES**. |

## Remarks

Other exception conditions include:

* If an XML declaration is found and **WS_XML_READER_PROPERTY_READ_DECLARATION** is **FALSE**,
  **WS_E_INVALID_FORMAT** is returned.
* If the Reader is using [WS_XML_READER_STREAM_INPUT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_stream_input) and there was insufficient data buffered the reader will return
  **WS_E_QUOTA_EXCEEDED**.