# ITTAPI::RegisterRequestRecipient

## Description

The
**RegisterRequestRecipient** method registers an application instance as being the proper one to handle assisted telephony requests.

## Parameters

### `lRegistrationInstance` [in]

Pointer to registration instance.

### `lRequestMode` [in]

Request mode.

### `fEnable` [in]

VARIANT_TRUE indicates that the caller wants to register as the handler; VARIANT_FALSE that it wants to unregister as the handler.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The TAPI object has not been initialized. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITRequest](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itrequest)

[ITRequestEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itrequestevent)

[ITTAPI](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapi)

[MakeCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itrequest-makecall)

[TAPI Object](https://learn.microsoft.com/windows/desktop/Tapi/tapi-object)