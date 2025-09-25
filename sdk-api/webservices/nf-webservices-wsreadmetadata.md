# WsReadMetadata function

## Description

Reads a Metadata element and adds it to the Metadata documents of the Metadata object.
The Metadata object state must be set to **WS_METADATA_STATE_CREATED**.

On error the Metadata object state is reset to **WS_METADATA_STATE_FAULTED**.

**Note** The function will consume an element if the element contains metadata. If the element is not recognized as containing metadata, or the particular type of metadata is not needed, the element it is not read.

## Parameters

### `metadata` [in]

A pointer to the **Metadata** object for storing the metadata read. The pointer must reference a valid [WS_METADATA](https://learn.microsoft.com/windows/desktop/wsw/ws-metadata) object.

### `reader` [in]

A pointer to the **XML Reader** object used to read the metadata. The pointer must reference a valid [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) object and the reader must be positioned on the element containing the desired metadata.

### `url` [in]

A pointer to a [WS_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_string) object referencing the retrieved metadata URL. The URL is used to track the metadata documents for resolving URL-based links between documents.

**Note** The URL MUST be fully qualified. The URL can have a fragment identifier.

The following URL schemes are supported:

* **WS_URL_HTTP_SCHEME_TYPE**
* **WS_URL_HTTPS_SCHEME_TYPE**
* **WS_URL_NETTCP_SCHEME_TYPE**

Each URL specified using this function must have a unique base URL. The base URL is computed by removing any fragment identifier from the URL specified.

For example if the following URLs were specified:

``` syntax

http://example.com/document1#fragment
http://example.com/document2

```

The two base URLs would be:

``` syntax

http://example.com/document1
http://example.com/document2

```

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_FORMAT** | The input data was not in the expected format or did not have the expected value. |
| **WS_E_INVALID_OPERATION** | The operation is not allowed due to the current state of the object. |
| **WS_E_QUOTA_EXCEEDED** | A quota was exceeded. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **S_FALSE** | The element was not consumed. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

This function recognizes the following types of metadata:

* WSDL 1.1 documents
* WS-Policy 1.2 documents