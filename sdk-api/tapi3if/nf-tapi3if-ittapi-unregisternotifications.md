# ITTAPI::UnregisterNotifications

## Description

The
**UnregisterNotifications** method removes any incoming call notification registrations that have been performed using
[ITTAPI::RegisterCallNotifications](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-registercallnotifications).

## Parameters

### `lRegister` [in]

The value returned by the
[RegisterCallNotifications](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-registercallnotifications) method in the *plRegister* parameter.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The TAPI object has not yet been initialized or the *lRegister* parameter is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITTAPI](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapi)

[RegisterCallNotifications](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-registercallnotifications)

[TAPI Object](https://learn.microsoft.com/windows/desktop/Tapi/tapi-object)