# WsGetMetadataProperty function

## Description

Retrieves a specified [WS_METADATA](https://learn.microsoft.com/windows/desktop/wsw/ws-metadata) object property. The property to retrieve is identified by a [WS_METADATA_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_metadata_property_id) input parameter.

**Note** The data returned by this function is valid until the metadata
object is released or reset. The data should not be modified.

## Parameters

### `metadata` [in]

A pointer to a **Metadata** object containing the desired property. This parameter must be a valid [WS_METADATA](https://learn.microsoft.com/windows/desktop/wsw/ws-metadata) object.

### `id` [in]

Identifier value of the property to retrieve.

### `value`

A reference to a location for storing the retrieved property value.
The pointer must have an alignment compatible with the type
of the property.

### `valueSize` [in]

The byte-length buffer size allocated by the caller to store the retrieved property value.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property Id was not supported for this object or the specified buffer was not large enough for the value. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **Other Errors** | This function may return other errors not listed above. |