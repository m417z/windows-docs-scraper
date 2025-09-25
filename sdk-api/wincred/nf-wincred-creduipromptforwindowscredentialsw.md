# CredUIPromptForWindowsCredentialsW function

## Description

The **CredUIPromptForWindowsCredentials** function creates and displays a configurable dialog box that allows users to supply credential information by using any credential provider installed on the local computer.

## Parameters

### `pUiInfo` [in, optional]

A pointer to a [CREDUI_INFO](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credui_infoa) structure that contains information for customizing the appearance of the dialog box that this function displays.

If the **hwndParent** member of the [CREDUI_INFO](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credui_infoa) structure is not **NULL**, this function displays a modal dialog box centered on the parent window.

If the **hwndParent** member of the [CREDUI_INFO](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credui_infoa) structure is **NULL**, the function displays a dialog box centered on the screen.

This function ignores the **hbmBanner** member of the **CREDUI_INFO** structure.

### `dwAuthError` [in]

A Windows error code, defined in Winerror.h, that is displayed in the dialog box. If credentials previously collected were not valid, the caller uses this parameter to pass the error message from the API that collected the credentials (for example, Winlogon) to this function. The corresponding error message is formatted and displayed in the dialog box. Set the value of this parameter to zero to display no error message.

### `pulAuthPackage` [in, out]

On input, the value of this parameter is used to specify the authentication package for which the credentials in the *pvInAuthBuffer* buffer are serialized. If the value of *pvInAuthBuffer* is **NULL** and the **CREDUIWIN_AUTHPACKAGE_ONLY** flag is set in the *dwFlags* parameter, only credential providers capable of serializing credentials for the specified authentication package are to be enumerated.

To get the appropriate value to use for this parameter on input, call the [LsaLookupAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalookupauthenticationpackage) function and use the value of the *AuthenticationPackage* parameter of that function.

On output, this parameter specifies the authentication package for which the credentials in the *ppvOutAuthBuffer* buffer are serialized.

### `pvInAuthBuffer` [in, optional]

A pointer to a credential BLOB that is used to populate the credential fields in the dialog box. Set the value of this parameter to **NULL** to leave the credential fields empty.

### `ulInAuthBufferSize` [in]

The size, in bytes, of the *pvInAuthBuffer* buffer.

### `ppvOutAuthBuffer` [out]

The address of a pointer that, on output, specifies the credential BLOB. For Kerberos, NTLM, or Negotiate credentials, call the [CredUnPackAuthenticationBuffer](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credunpackauthenticationbuffera) function to convert this BLOB to string representations of the credentials.

When you have finished using the credential BLOB, clear it from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function, and free it by calling the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

### `pulOutAuthBufferSize` [out]

The size, in bytes, of the *ppvOutAuthBuffer* buffer.

### `pfSave` [in, out, optional]

A pointer to a Boolean value that, on input, specifies whether the **Save** check box is selected in the dialog box that this function displays. On output, the value of this parameter specifies whether the **Save** check box was selected when the user clicks the **Submit** button in the dialog box. Set this parameter to **NULL** to ignore the **Save** check box.

This parameter is ignored if the **CREDUIWIN_CHECKBOX** flag is not set in the *dwFlags* parameter.

### `dwFlags` [in]

A value that specifies behavior for this function. This value can be a bitwise-**OR** combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CREDUIWIN_GENERIC**<br><br>0x1 | The caller is requesting that the credential provider return the user name and password in plain text.<br><br>This value cannot be combined with **SECURE_PROMPT**. |
| **CREDUIWIN_CHECKBOX**<br><br>0x2 | The **Save** check box is displayed in the dialog box. |
| **CREDUIWIN_AUTHPACKAGE_ONLY**<br><br>0x10 | Only credential providers that support the authentication package specified by the *pulAuthPackage* parameter should be enumerated.<br><br>This value cannot be combined with **CREDUIWIN_IN_CRED_ONLY**. |
| **CREDUIWIN_IN_CRED_ONLY**<br><br>0x20 | Only the credentials specified by the *pvInAuthBuffer* parameter for the authentication package specified by the *pulAuthPackage* parameter should be enumerated.<br><br>If this flag is set, and the *pvInAuthBuffer* parameter is **NULL**, the function fails.<br><br>This value cannot be combined with **CREDUIWIN_AUTHPACKAGE_ONLY**. |
| **CREDUIWIN_ENUMERATE_ADMINS**<br><br>0x100 | Credential providers should enumerate only administrators. This value is intended for User Account Control (UAC) purposes only. We recommend that external callers not set this flag. |
| **CREDUIWIN_ENUMERATE_CURRENT_USER**<br><br>0x200 | Only the incoming credentials for the authentication package specified by the *pulAuthPackage* parameter should be enumerated. |
| **CREDUIWIN_SECURE_PROMPT**<br><br>0x1000 | The credential dialog box should be displayed on the secure desktop. This value cannot be combined with **CREDUIWIN_GENERIC**.<br><br>**Windows Vista:** This value is supported beginning with Windows Vista with SP1. |
| **CREDUIWIN_PREPROMPTING**<br><br>0x2000 | The credential dialog box is invoked by the [SspiPromptForCredentials](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspipromptforcredentialsa) function, and the client is prompted before a prior handshake. If SSPIPFC_NO_CHECKBOX is passed in the *pvInAuthBuffer* parameter, then the credential provider should not display the check box.<br><br>**Windows Vista:** This value is supported beginning with Windows Vista with SP1. |
| 0x40000 | The credential provider will not pack the AAD authority name. This is only applied to Azure AD joined devices.<br><br>**Windows 10, version 1607:** This value is supported beginning with Windows 10, version 1607. |
| **CREDUIWIN_PACK_32_WOW**<br><br>0x10000000 | The credential provider should align the credential BLOB pointed to by the *ppvOutAuthBuffer* parameter to a 32-bit boundary, even if the provider is running on a 64-bit system. |
| 0x80000000 | Windows Hello credentials will be packed in a smart card auth buffer. This only applies to the face, fingerprint, and PIN credential providers. <br><br>**Windows 10, version 1809:** This value is supported beginning with Windows 10, version 1809. |

## Return value

If the function succeeds, the function returns **ERROR_SUCCESS**. If the function is canceled by the user, it returns **ERROR_CANCELLED**. Any other return value indicates that the function failed to load.

## Remarks

This function does not save credentials.

Applications that use [SSPI](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi) to authenticate users should not call this function. Instead, call [SspiPromptForCredentials](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspipromptforcredentialsa).

> [!NOTE]
> The wincred.h header defines CredUIPromptForWindowsCredentials as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).