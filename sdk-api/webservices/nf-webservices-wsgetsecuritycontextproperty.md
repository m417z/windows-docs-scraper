# WsGetSecurityContextProperty function

## Description

Gets a property of the specified security context.

## Parameters

### `securityContext` [in]

The security context that is queried for its property.

### `id` [in]

The id of the property (one of [WS_SECURITY_CONTEXT_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_context_property_id)).

### `value`

The address to place the retrieved value. The pointer must have an alignment compatible with the type of the property.

### `valueSize` [in]

The size of the buffer that the caller has allocated for the retrieved value.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property id was not supported for this object or the specified buffer was not large enough for the value. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **Other Errors** | This function may return other errors not listed above. |