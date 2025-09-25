# WsGetSecurityTokenProperty function

## Description

Extracts a field or a property from a security token. If the queried property does not use the *heap* parameter, the returned data is owned by the security token and remains valid as long as the security token itself remains valid. Specifically, for security tokens extracted from a received message, the security token and fields extracted from it are valid only as long as the message is not reset or freed.

If the *heap* parameter is required by the property, then the returned data is stored on the heap, with its lifetime detached from the underlying token.

## Parameters

### `securityToken` [in]

The security token from which the property should be extracted.

### `id` [in]

The id of the property to retrieve.

### `value`

The location to store the retrieved property.
The pointer must have an alignment compatible with the type
of the property.

### `valueSize` [in]

The number of bytes allocated by the caller to
store the retrieved property.

### `heap` [in, optional]

Heap to store additional property data. This parameter must be non-**NULL** when the queried property is
[WS_SECURITY_TOKEN_PROPERTY_SYMMETRIC_KEY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_token_property_id) and must be **NULL** otherwise.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property id was not supported for this object or the specified buffer was not large enough for the value. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **Other Errors** | This function may return other errors not listed above. |