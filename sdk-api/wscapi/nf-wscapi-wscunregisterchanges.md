# WscUnRegisterChanges function

## Description

Cancels a callback registration that was made by a call to the [WscRegisterForChanges](https://learn.microsoft.com/windows/desktop/api/wscapi/nf-wscapi-wscregisterforchanges) function.

## Parameters

### `hRegistrationHandle` [in]

The handle to the registration context returned as the *phCallbackRegistration* of the [WscRegisterForChanges](https://learn.microsoft.com/windows/desktop/api/wscapi/nf-wscapi-wscregisterforchanges) function.

## Return value

Returns **S_OK** if the function succeeds, otherwise returns an error code.

## See also

[WscRegisterForChanges](https://learn.microsoft.com/windows/desktop/api/wscapi/nf-wscapi-wscregisterforchanges)