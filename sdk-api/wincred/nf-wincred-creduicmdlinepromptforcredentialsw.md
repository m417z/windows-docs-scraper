# CredUICmdLinePromptForCredentialsW function

## Description

The **CredUICmdLinePromptForCredentials** function prompts for and accepts credential information from a user working in a command-line (console) application. The name and password typed by the user are passed back to the calling application for verification.

## Parameters

### `pszTargetName` [in]

A pointer to a **null**-terminated string that contains the name of the target for the credentials, typically a server name. For DFS connections, this string is of the form *ServerName***\\***ShareName*. The *pszTargetName* parameter is used to identify the target information and is used to store and retrieve the credential.

### `pContext` [in]

Currently reserved and must be **NULL**.

### `dwAuthError` [in, optional]

Specifies why prompting for credentials is needed. A caller can pass this Windows error parameter, returned by another authentication call, to allow the dialog box to accommodate certain errors. For example, if the password expired status code is passed, the dialog box prompts the user to change the password on the account.

### `UserName` [in, out]

A pointer to a **null**-terminated string that contains the credential user name. If a nonzero-length string is specified for *pszUserName*, the user will be prompted only for the password. In the case of credentials other than user name/password, a marshaled format of the credential can be passed in. This string is created by calling
[CredMarshalCredential](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credmarshalcredentiala).

This function writes the user-supplied name to this buffer, copying a maximum of *ulUserNameMaxChars* characters. The string in this format can be converted to the user name/password format by calling the
[CredUIParseUsername](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduiparseusernamea) function. The string in its marshaled format can be passed directly to a [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSP).

If the CREDUI_FLAGS_DO_NOT_PERSIST flag is not specified, the value returned in this parameter is of a form that should not be inspected, printed, or persisted other than passing it to [CredUIParseUsername](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduiparseusernamea). The subsequent results of **CredUIParseUsername** can be passed only to a client-side authentication API such as [WNetAddConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnectiona) or the SSP API.

### `ulUserBufferSize` [in]

The maximum number of characters that can be copied to *pszUserName* including the terminating **null** character.

**Note** CREDUI_MAX_USERNAME_LENGTH does not include the terminating **null** character.

### `pszPassword` [in, out]

A pointer to a **null**-terminated string that contains the password for the credentials. If a nonzero-length string is specified for *pszPassword*, the password parameter will be prefilled with the string.

This function writes the user-supplied password to this buffer, copying a maximum of *ulPasswordMaxChars* characters. If the CREDUI_FLAGS_DO_NOT_PERSIST flag is not specified, the value returned in this parameter is of a form that should not be inspected, printed, or persisted other than passing it to a client-side authentication function such as [WNetAddConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnectiona) or an SSP function.

When you have finished using the password, clear the password from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information about protecting passwords, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `ulPasswordBufferSize` [in]

The maximum number of characters that can be copied to *pszPassword* including the terminating **null** character.

**Note** CREDUI_MAX_PASSWORD_LENGTH does not include the terminating **null** character.

### `pfSave` [in, out]

A pointer to a **BOOL** that specifies the initial state of the **Save** message and receives the state of the **Save** message after the user has responded to the command prompt. If *pfSave* is not **NULL** and [CredUIPromptForCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforcredentialsa) returns NO_ERROR, *pfSave* returns the state of the **Save** message. If the CREDUI_FLAGS_PERSIST flag is specified, the **Save** message is not displayed but is considered to be "y". If the CREDUI_FLAGS_DO_NOT_PERSIST flag is specified and CREDUI_FLAGS_SHOW_SAVE_CHECK_BOX is not specified, the **Save** message is not displayed but is considered to be "n".

### `dwFlags` [in]

A **DWORD** value that specifies special behavior for this function. This value can be a bitwise-**OR** combination of zero or more of the following values.

| Value | Meaning |
| --- | --- |
| **CREDUI_FLAGS_ALWAYS_SHOW_UI** | Display a user interface if the credentials can be returned from an existing credential in credential manager. This flag is permitted only if CREDUI_FLAGS_GENERIC_CREDENTIALS is also specified and is used only in conjunction with CREDUI_FLAGS_GENERIC_CREDENTIALS. |
| **CREDUI_FLAGS_DO_NOT_PERSIST** | Do not display the save message or store credentials.<br><br>CREDUI_FLAGS_SHOW_SAVE_CHECK_BOX can also be passed to display the save message only and return the result in *pfSave*. |
| **CREDUI_FLAGS_EXCLUDE_CERTIFICATES** | Prompt for user name/password. If the *pszUserName* parameter is specified, the user name is omitted. If the credential is persisted, store the passed-in user name with the credential. |
| **CREDUI_FLAGS_EXPECT_CONFIRMATION** | Specifies that the caller will call [CredUIConfirmCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduiconfirmcredentialsa) to determine whether the returned credentials are actually valid. This ensures that credentials that are not valid are not saved to the credential manager. Specify this flag unless CREDUI_FLAGS_DO_NOT_PERSIST is specified. |
| **CREDUI_FLAGS_GENERIC_CREDENTIALS** | Consider the credentials entered by the user a generic credential. |
| **CREDUI_FLAGS_INCORRECT_PASSWORD** | Silently ignore this flag. |
| **CREDUI_FLAGS_PERSIST** | Do not show the save message, but save the credential as though the user answered "y". |
| **CREDUI_FLAGS_REQUEST_ADMINISTRATOR** | Silently ignore this flag. |
| **CREDUI_FLAGS_REQUIRE_CERTIFICATE** | Reserved for future use; do not pass this flag. |
| **CREDUI_FLAGS_REQUIRE_SMARTCARD** | Use a smart card and prompt for a PIN. If more than one smart card is available, select one of them. If the *pszUserName* parameter passes a string that is not empty, the string must match the UPN associated with the certificate on one of the smart cards. A UPN matches if the string matches the whole UPN on the certificate or the string matches the part to the left of the at sign (@) in the UPN of the certificate. If there is a match, the matching smart card is selected. |
| **CREDUI_FLAGS_SERVER_CREDENTIAL** | This flag is meaningful only in locating a matching credential to prefill the dialog box, should authentication fail. When this flag is specified, wildcard credentials will not be matched. It has no effect when writing a credential. CredUI does not create credentials that contain wildcard characters. Any found were either created explicitly by the user or created programmatically, as happens when a RAS connection is made. |
| **CREDUI_FLAGS_SHOW_SAVE_CHECK_BOX** | Display the save message and return **TRUE** in the *pfSave* out parameter if the user answers "y", **FALSE** if the user answers "n". CREDUI_FLAGS_DO_NOT_PERSIST must be specified to use this flag. |
| **CREDUI_FLAGS_USERNAME_TARGET_CREDENTIALS** | The credential is a run-as credential. The *pszTargetName* parameter specifies the name of the command or program being run. It is used for prompting purposes only. |

## Return value

The return value is a **DWORD** and can be one of the following values.

| Value | Description |
| --- | --- |
| **ERROR_INVALID_FLAGS** | This status is returned for any of the flag combinations that are not valid. |
| **ERROR_INVALID_PARAMETER** | Either *pszTargetName* is **NULL**, the empty string, or longer than CREDUI_MAX_DOMAIN_LENGTH, or *pUiInfo* is not **NULL** and the [CredUI_INFO](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credui_infoa) structure pointed to did not meet one of the following requirements: <br><br>* The **cbSize** member must be one.<br>* If the **hbmBanner** member is not **NULL**, it must be of type OBJ_BITMAP.<br>* If the **pszMessageText** member is not **NULL**, it must not be greater than CREDUI_MAX_MESSAGE_LENGTH.<br>* If the **pszCaptionText** member is not **NULL**, it must not be greater than CREDUI_MAX_CAPTION_LENGTH. |
| **ERROR_NO_SUCH_LOGON_SESSION** | The credential manager cannot be used. Typically, this error is handled by calling [CredUICmdLinePromptForCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduicmdlinepromptforcredentialsa) and passing in the CREDUI_FLAGS_DO_NOT_PERSIST flag. |
| **NO_ERROR** | User chose **OK**. The *pszUserName*, *pszPassword*, and *pfSave* variables will return the values documented earlier. |

## Remarks

The CREDUI_FLAGS_REQUIRE_SMARTCARD, CREDUI_FLAGS_REQUIRE_CERTIFICATE, and CREDUI_FLAGS_EXCLUDE_CERTIFICATE flags are mutually exclusive.

If CREDUI_FLAGS_DO_NOT_PERSIST is specified, either *pszTargetName* must be specified or *uiInfo->pszMessageText* and *uiInfo->pszCaption* must be specified.

The CREDUI_FLAG_USERNAME_TARGET_CREDENTIALS and CREDUI_FLAGS_GENERIC_CREDENTIALS flags are mutually exclusive. If neither is specified, the credential is a domain credential.

If CREDUI_FLAGS_GENERIC_CREDENTIALS is not specified or CREDUI_FLAGS_COMPLETE_USERNAME is specified, the typed name is *syntax checked*. Syntax checked means that the same rules are used as are implied by [CredUIParseUserName](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduiparseusernamea). If the typed name is not valid, the user is prompted for a valid one. If the domain portion of the typed name is missing, one will be supplied based on the target name.

If CREDUI_FLAGS_GENERIC_CREDENTIALS is specified and CREDUI_FLAGS_VALIDATE_USERNAME is also specified, the typed name is syntax checked. If the typed name is not valid, the user is prompted for a valid one.

If CREDUI_FLAGS_GENERIC_CREDENTIALS is specified and neither CREDUI_FLAGS_COMPLETE_USERNAME nor CREDUI_FLAGS_VALIDATE_USERNAME is specified, the typed name is not syntax checked in any way.

If neither CREDUI_FLAGS_PERSIST nor CREDUI_FLAGS_DO_NOT_PERSIST are set, the save message is shown, and it controls whether the credential is saved or not.

If CREDUI_FLAGS_PROMPT_FOR_SAVE is specified, the *pfSave* parameter must not be **NULL**.

The CREDUI_FLAGS_REQUIRE_SMARTCARD and CREDUI_FLAGS_EXCLUDE_CERTIFICATES flags are mutually exclusive. **CredUICmdLinePromptForCredentials** supports prompting for a smart card certificate or a password-based credential. It does not support certificates that are not smart card certificates or prompting for both on a single call.

Calling Modes

* The caller will attempt to access the target resource, call credui (passing a description of the target resource and the failure status), call [CredUIParseUserName](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduiparseusernamea), access the target resource again, and then call [CredUIConfirmCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduiconfirmcredentialsa).
* The caller can prompt for credentials without accessing any resources by passing CREDUI_FLAGS_DO_NOT_PERSIST.

Target Information

Target Information is information about the location of the resource to be accessed. For a list of all potential target names for a resource, call
[CredGetTargetInfo](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credgettargetinfoa). **CredGetTargetInfo** returns information that was cached by the Negotiate, NTLM, or Kerberos authentication package when one of those packages was used to authenticate to the named target. **CredGetTargetInfo** returns some or all of the following names for the target:

* NetBIOS server name of the computer
* DNS server name of the computer
* NetBIOS domain name of the domain the computer belongs to
* DNS domain name of the domain the computer belongs to
* DNS tree name of the tree the computer belongs to
* Name of the package that collected the information

Any piece of this information can be missing if the information does not apply to the target computer. For instance, a computer that is a member of a workgroup does not have a NetBIOS domain name. A computer that is a member of a Windows domain does not have a DNS domain name or DNS tree name.

Credentials are stored in the credential manager based on target name. Each target name is stored as generally as possible without colliding with credentials already stored in the credential manager. An important effect of storing credentials by target name is that a particular user can have only one credential per target stored in the credential manager.

> [!NOTE]
> The wincred.h header defines CredUICmdLinePromptForCredentials as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CredGetTargetInfo](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credgettargetinfoa)

[CredMarshalCredential](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credmarshalcredentiala)

[CredUIConfirmCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduiconfirmcredentialsa)

[CredUIParseUserName](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduiparseusernamea)

[CredUI_INFO](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credui_infoa)

[WNetAddConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnectiona)