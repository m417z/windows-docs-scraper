# CryptUIWizFreeDigitalSignContext function

## Description

The **CryptUIWizFreeDigitalSignContext** function frees the [CRYPTUI_WIZ_DIGITAL_SIGN_CONTEXT](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_digital_sign_context) structure allocated by the [CryptUIWizDigitalSign](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizdigitalsign) function.

## Parameters

### `pSignContext` [in]

A pointer to the [CRYPTUI_WIZ_DIGITAL_SIGN_CONTEXT](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_digital_sign_context) structure to be freed.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero.

## See also

[CRYPTUI_WIZ_DIGITAL_SIGN_CONTEXT](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_digital_sign_context)

[CryptUIWizDigitalSign](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizdigitalsign)