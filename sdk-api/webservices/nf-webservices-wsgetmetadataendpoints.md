# WsGetMetadataEndpoints function

## Description

Returns the "Endpoints" defined within the metadata object documents.
Calling this function with [WS_METADATA_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_metadata_state)set to **WS_METADATA_STATE_CREATED** will cause the metadata object to resolve
all references in the metadata documents. Any
additional document validation will also be done. If this process is
successful the metadata object will be set to **WS_METADATA_STATE_RESOLVED** and subsequent document additions to the metadata object are not permitted. If there is an error the metadata object
will be set to **WS_METADATA_STATE_FAULTED**.

**Note** The data returned by this function is valid until the metadata
object is released or reset. The data returned from this function
should not be modified.

## Parameters

### `metadata` [in]

A pointer to a **Metadata** object containing the desired Endpoints. This parameter must be a valid [WS_METADATA](https://learn.microsoft.com/windows/desktop/wsw/ws-metadata) object.

### `endpoints` [out]

On success this pointer parameter
is populated with information about the endpoints that were
defined in the metadata object.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property id was not supported for this object or the specified buffer was not large enough for the value. |
| **E_OUTOFMEMORY** | Insufficient memory resources. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

This property may be used in **WS_METADATA_STATE_CREATED** or **WS_METADATA_STATE_RESOLVED** state.

This function will fail if there are missing metadata documents.
Use [WsGetMissingMetadataDocumentAddress](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmissingmetadatadocumentaddress) to determine
the address of any missing documents.