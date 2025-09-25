# ITRequestEvent::get_RegistrationInstance

## Description

The
**get_RegistrationInstance** method gets the registration instance.

## Parameters

### `plRegistrationInstance` [out]

Pointer to the registration instance.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plRegistrationInstance* is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITRequestEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itrequestevent)