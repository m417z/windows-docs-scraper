# WsReadToStartElement function

## Description

Advances the reader to the next start element skipping whitespace and comments if necessary. Optionally,
it may also verify the localName and namespace of the element.

## Parameters

### `reader` [in]

The reader which is to read to the start element.

### `localName` [in, optional]

The localName name that the element should be. If **NULL**, any localName is permitted.

### `ns` [in, optional]

The namespace that the element should be. If **NULL**, any namespace is permitted.

### `found`

If specified then this will indicate whether an element is found and the localName and namespace, if also specified, match.
If not specified, and an element is not found or the localName and namespace don't match, then it will return
**WS_E_INVALID_FORMAT**. (See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |

## Remarks

Consider the following XML:

``` syntax
<!-- A purchase order -->
        <PurchaseOrder xmlns='http://tempuri.org'>
            <Item>
                Pencil
            </Item>
        </PurchaseOrder>

```

The following examples illustrates the behaviors of **WsReadToStartElement** when the reader is
positioned in various places in the document.

``` syntax
WS_XML_STRING purchaseOrder = WS_XML_STRING_VALUE("PurchaseOrder");
WS_XML_STRING item = WS_XML_STRING_VALUE("Item");
WS_XML_STRING ns = WS_XML_STRING("http://tempuri.org");
WS_ERROR* error = NULL;

// Example 1: Reader on comment, element has specified name and namespace, found argument is not provided
HRESULT hr = WsReadToStartElement(reader, &purchaseOrder, &ns, NULL, error);
// hr = NOERROR, the reader is positioned on <PurchaseOrder>

// Example 2: Reader on comment, element has specified name and namespace, found argument is provided
BOOL found;
HRESULT hr = WsReadToStartElement(reader, &purchaseOrder, &ns, found, error);
// hr = NOERROR, found = TRUE, the reader is positioned on <PurchaseOrder>

// Example 3: Reader on comment, element does not have specified name and namespace, found argument is not provided
HRESULT hr = WsReadToStartElement(reader, &item, &ns, NULL, error);
// hr = WS_E_INVALID_FORMAT, the reader is faulted

// Example 4: Reader on comment, element does not have specified name and namespace, found argument is provided
BOOL found;
HRESULT hr = WsReadToStartElement(reader, &item, &ns, &found, error);
// hr = NOERROR, found = FALSE, the reader is positioned on <PurchaseOrder>

// Example 5: Reader on comment, name and namespace not specified, found argument is provided
BOOL found;
HRESULT hr = WsReadToStartElement(reader, NULL, NULL, &found, error);
// hr = NOERROR, found = TRUE, the reader is positioned on <PurchaseOrder>

// Example 6: Reader on </Item>, name and namespace not specified, found argument is not provided
HRESULT hr = WsReadToStartElement(reader, NULL, NULL, NULL, error);
// hr = WS_E_INVALID_FORMAT, the reader is faulted

// Example 7: Reader on </Item>, name and namespace not specified, found argument is provided
BOOL found;
HRESULT hr = WsReadToStartElement(reader, NULL, NULL, &found, error);
// hr = NOERROR, found = FALSE, the reader is positioned on </Item>

```

If **WsReadToStartElement** indicates an element has been found, then [WsReadStartElement](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadstartelement)
or [WsReadNode](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadnode) may be used to move the reader past the start element into the content of the element.

[WsSkipNode](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsskipnode) may be used to skip the element and all its children leaving the reader positioned on
the [WS_XML_NODE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_node) following the corresponding end element.

This function can fail for any of the reasons listed in [WsReadNode](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadnode).