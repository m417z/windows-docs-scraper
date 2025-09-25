# USERNAME_TARGET_CREDENTIAL_INFO structure

## Description

The
**USERNAME_TARGET_CREDENTIAL_INFO** structure contains a reference to a credential. This structure is used to pass a user name into the
[CredMarshalCredential](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credmarshalcredentiala) function and out of the
[CredUnmarshalCredential](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credunmarshalcredentiala). The resultant marshaled credential can be passed as the *lpszUserName* parameter of the [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) function to direct that API to get the password from the corresponding CRED_FLAGS_USERNAME_TARGET credential instead of from the *lpszPassword* parameter of the function.

## Members

### `UserName`

 User name of the USERNAME_TARGET_CREDENTIAL_INFO credential.