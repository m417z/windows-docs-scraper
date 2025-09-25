# WsReadEndElement function

## Description

This function ensures that the current Reader [node](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_node) is an **End element** and advances the reader to the next **node**.
If the Reader is not positioned on an **End element** when the function is called it will skip whitespace attempting to find one. If after skipping whitespace it is not positioned on an **End element** it returns a **WS_E_INVALID_FORMAT** exception.

(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)

## Parameters

### `reader` [in]

A pointer to the **XML Reader** that is reads the **End element**. The pointer must reference a valid [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) object.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |

## Remarks

This function can fail for any of the reasons listed in [WsReadNode](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadnode).