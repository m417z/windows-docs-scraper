# WsFindAttribute function

## Description

Searches the attributes of the current element for an attribute with the
specified name and namespace and returns its index which may be passed
to [WsReadStartAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadstartattribute).

## Parameters

### `reader` [in]

The reader on which to find the attribute.

### `localName` [in]

The local name of the attribute to search for.

### `ns` [in]

The namespace of the attribute to search for.

### `required` [in]

If required is **TRUE** and the attribute is not found, the function will return **WS_E_INVALID_FORMAT**.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).) if required is **FALSE** and the attribute is not found, the function will return S_FALSE.

### `attributeIndex` [out]

If the attribute is found, then the index of the attribute, is returned here.
This index can then be passed to [WsReadStartAttribute](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadstartattribute).

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |

## Remarks

If the reader is not positioned on a start element then it will return **WS_E_INVALID_OPERATION**.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)

The index returned does not necessarily correspond to the position of the attribute as it appeared
in the document. It identifies the index of the matching attribute in the array of attributes of
the [WS_XML_ELEMENT_NODE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_element_node). The order of the attributes in this array may differ from the order
in which the attributes appeared in the document.