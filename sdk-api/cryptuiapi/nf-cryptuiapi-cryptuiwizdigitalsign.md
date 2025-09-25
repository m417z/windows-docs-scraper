# CryptUIWizDigitalSign function

## Description

[The **CryptUIWizDigitalSign** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CryptUIWizDigitalSign** function digitally signs a document or [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly). The document or BLOB can be signed with or without user interaction.

## Parameters

### `dwFlags` [in]

Contains flags that modify the behavior of the function. This can be zero or the following value.

| Value | Meaning |
| --- | --- |
| **CRYPTUI_WIZ_NO_UI**<br><br>0x0001 | This function will sign the document based on the information in the [CRYPTUI_WIZ_DIGITAL_SIGN_INFO](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_digital_sign_info) structure pointed to by the *pDigitalSignInfo* parameter without displaying any user interface. If this flag is not specified, this function will display a wizard to guide the user through the signing process. |

### `hwndParent` [in, optional]

The handle of the window to use as the parent of the dialog box that this function creates. This parameter is ignored if the **CRYPTUI_WIZ_NO_UI** flag is set in *dwFlags*.

### `pwszWizardTitle` [in, optional]

A pointer to a null-terminated Unicode string that contains the title to use in the dialog box that this function creates. This parameter is ignored if the **CRYPT_WIZ_NO_UI** flag is set in *dwFlags*. If this parameter is **NULL**, a default title is used.

### `pDigitalSignInfo` [in]

A pointer to a [CRYPTUI_WIZ_DIGITAL_SIGN_INFO](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_digital_sign_info) structure that contains information about the signing process.

### `ppSignContext` [out, optional]

A pointer to a [CRYPTUI_WIZ_DIGITAL_SIGN_CONTEXT](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_digital_sign_context) structure pointer that receives the signed BLOB. When you have finished using this structure, you must free the memory by passing this pointer to the [CryptUIWizFreeDigitalSignContext](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizfreedigitalsigncontext) function. This parameter can be **NULL** if the signed BLOB is not needed.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CRYPTUI_WIZ_DIGITAL_SIGN_CONTEXT](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_digital_sign_context)

[CRYPTUI_WIZ_DIGITAL_SIGN_INFO](https://learn.microsoft.com/windows/win32/api/cryptuiapi/ns-cryptuiapi-cryptui_wiz_digital_sign_info)

[CryptUIWizFreeDigitalSignContext](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-cryptuiwizfreedigitalsigncontext)