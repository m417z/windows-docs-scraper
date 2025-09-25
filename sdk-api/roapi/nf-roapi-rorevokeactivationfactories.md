# RoRevokeActivationFactories function

## Description

Removes an array of registered activation factories from the Windows Runtime.

## Parameters

### `cookie` [in]

Type: **[RO_REGISTRATION_COOKIE](https://learn.microsoft.com/windows/desktop/WinRT/ro-registration-cookie)**

## Remarks

Call the **RoRevokeActivationFactories** function remove the activation factories represented in the *cookie* array from the Windows Runtime.

## See also

[RO_REGISTRATION_COOKIE](https://learn.microsoft.com/windows/desktop/WinRT/ro-registration-cookie)

[RoInitialize](https://learn.microsoft.com/windows/desktop/api/roapi/nf-roapi-roinitialize)

[RoRegisterActivationFactories](https://learn.microsoft.com/windows/desktop/api/roapi/nf-roapi-roregisteractivationfactories)