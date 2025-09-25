# WscRegisterForChanges function

## Description

Registers a callback function to be run when Windows Security Center (WSC) detects a change that could affect the health of one of the security providers.

## Parameters

### `Reserved` [in]

Reserved. Must be **NULL**.

### `phCallbackRegistration` [out]

A pointer to a handle to the callback registration. When you are finished using the callback function, unregister it by calling the [WscUnRegisterChanges](https://learn.microsoft.com/windows/desktop/api/wscapi/nf-wscapi-wscunregisterchanges) function.

### `lpCallbackAddress` [in]

A pointer to the application-defined function to be called when a change to the WSC service occurs. This function is also called when the WSC service is started or stopped.

### `pContext` [in]

A pointer to a variable to be passed as the *lpParameter* parameter to the function pointed to by the *lpCallbackAddress* parameter.

## Return value

Returns S_OK if the function succeeds, otherwise returns an error code.

## Remarks

When you want to cease receiving notification to your callback method, you can unregister it by calling the [WscUnRegisterChanges](https://learn.microsoft.com/windows/desktop/api/wscapi/nf-wscapi-wscunregisterchanges) function.

## See also

[WscUnRegisterChanges](https://learn.microsoft.com/windows/desktop/api/wscapi/nf-wscapi-wscunregisterchanges)