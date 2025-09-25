# WsResetError function

## Description

Releases the content of the *error* object parameter but does not release the resource allocated to the *error* object parameter.

**Note** The "reset" effect of this function returns the *error* object to the state set at instantiation. The object is not released consequently is available for reuse.

## Parameters

### `error` [in]

This parameter is a pointer to the [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) object to reset.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |

## Remarks

String data added to the error object using the [WsAddErrorString](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsadderrorstring) function are released.

Properties that have been set using the [WsSetErrorProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsseterrorproperty) function are released.