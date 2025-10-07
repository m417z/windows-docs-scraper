# CredUIParseUserNameA function

## Description

The **CredUIParseUserName** function extracts the domain and user account name from a fully qualified user name.

## Parameters

### `userName` [in]

Pointer to a **null**-terminated string that contains the user name to be parsed. The name must be in UPN or down-level format, or a certificate. Typically, *pszUserName* is received from the
[CredUIPromptForCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforcredentialsa) or
[CredUICmdLinePromptForCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduicmdlinepromptforcredentialsa).

### `user` [out]

Pointer to a **null**-terminated string that receives the user account name.

### `userBufferSize` [in]

Maximum number of characters to write to the *pszUser* string including the terminating **null** character.

**Note** CREDUI_MAX_USERNAME_LENGTH does NOT include the terminating **null** character.

### `domain` [out]

Pointer to a **null**-terminated string that receives the domain name. If *pszUserName* specifies a certificate, *pszDomain* will be **NULL**.

### `domainBufferSize` [in]

Maximum number of characters to write to the *pszDomain* string including the terminating **null** character.

**Note** CREDUI_MAX_DOMAIN_TARGET_LENGTH does NOT include the terminating **null** character.

## Return value

This function returns the following:

* NO_ERROR

  The user name is valid.
* ERROR_INVALID_ACCOUNT_NAME

  The user name is not valid.
* ERROR_INSUFFICIENT_BUFFER

  One of the buffers is too small.
* ERROR_INVALID_PARAMETER

  + *ulUserMaxChars* or *ulDomainMaxChars* is zero.
  + *pszUserName*, *pszUser*, or *pszDomain* is **NULL**.

## Remarks

This function parses the user name information returned by the
[CredUIPromptForCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforcredentialsa) and
[CredUICmdLinePromptForCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduicmdlinepromptforcredentialsa) functions so that the resulting credentials can be passed to functions, such as [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera), that require the user name and domain as separate strings.

The following formats are supported:

* \<MarshalledCredentialReference>

  Marshaled credential reference as defined by
  [CredIsMarshaledCredential](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credismarshaledcredentiala). Such a credential is returned in the *User* parameter. The *Domain* parameter is set to an empty string.
* \<DomainName>\<UserName>

  \<UserName> is returned in the *User* parameter and the \<DomainName> is returned is the *Domain* parameter. The name is considered to have this syntax if the *UserName* contains a backslash (\\).
* \<UserName>@\<DNSDomainName>

  The entire string is returned in the *User* parameter. The *Domain* parameter is set to an empty string. For this syntax, the last @ in the string is used because \<UserName> can contain an @ but \<DNSDomainName> cannot.

> [!NOTE]
> The wincred.h header defines CredUIParseUserName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CredIsMarshaledCredential](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credismarshaledcredentiala)

[CredUICmdLinePromptForCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduicmdlinepromptforcredentialsa)

[CredUIPromptForCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforcredentialsa)

[LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera)