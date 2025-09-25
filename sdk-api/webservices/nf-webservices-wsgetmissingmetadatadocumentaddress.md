# WsGetMissingMetadataDocumentAddress function

## Description

This function returns the address of a missing document that is referenced by the metadata object.

Each document that is added to the metadata object may contain references to other documents. After a document has been added back to the Metadata the function can be used to find the next missing document.

**Note** This function will fail if the host name of the URL of the missing address being returned cannot be verified as being one of the host names expected. The expected host names are a union of the following:

* The host name of any URL previously passed to [WsReadMetadata](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmetadata).
* The list of host names specified using the [WS_METADATA_PROPERTY_HOST_NAMES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_metadata_property_id) property.

## Parameters

### `metadata` [in]

This parameter is a pointer to a **Metadata** object that should have the document.

### `address`

On success this parameter is populated with either a pointer to the address of a missing metadata document, or **NULL** if there are no missing metadata documents.
The returned address URL is fully qualified.

**Note** The data returned by this function is valid until the metadata object is freed or reset. The data should not be modified.

### `error` [in, optional]

This parameter is a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) pointer to where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

Whether or not this function will verify host names of URLs returned can be
controlled using the **WS_METADATA_PROPERTY_VERIFY_HOST_NAMES** enumerator value.

The purpose of the host name verification is to ensure that an application
does not use the address without knowing that it is from a host that it
is willing to accept metadata from.