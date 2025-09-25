# WsGetPolicyProperty function

## Description

Retrieves a property of a policy object.

## Parameters

### `policy` [in]

A pointer to the [WS_POLICY](https://learn.microsoft.com/windows/desktop/wsw/ws-policy) object from which to obtain the property.

### `id` [in]

An identifier of the policy property to retrieve.

### `value`

A pointer to the address to store the retrieved property value. The pointer must have an alignment compatible with the type
of the property.

### `valueSize` [in]

The number of bytes allocated by the caller to
store the retrieved property.

### `error` [in, optional]

A pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object where additional information about the error should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The property id was not supported for this object or the specified buffer was not large enough for the value. |
| **E_OUTOFMEMORY** | Ran out of memory. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

The data returned by this function is good until the
metadata object is freed or reset.