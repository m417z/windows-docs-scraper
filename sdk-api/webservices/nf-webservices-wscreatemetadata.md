# WsCreateMetadata function

## Description

Creates a metadata object that is used to collect and process metadata documents.

## Parameters

### `properties`

An array of [WS_METADATA_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_metadata_property) structures containing optional properties for the metadata.

The value of this parameter may be **NULL**, in which case, the *propertyCount* parameter must be 0 (zero).

### `propertyCount` [in]

The number of properties in the *properties* array.

### `metadata`

On success, a pointer that receives the address of the [WS_METADATA](https://learn.microsoft.com/windows/desktop/wsw/ws-metadata) structure representing the new message.
When you no longer need this structure, you must free it by calling [WsFreeMetadata](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreemetadata).

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **Other Errors** | This function may return other errors not listed above. |