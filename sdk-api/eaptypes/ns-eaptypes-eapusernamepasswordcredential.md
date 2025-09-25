# EapUsernamePasswordCredential structure

## Description

The **EapUsernamePasswordCredential** structure contains the username and password that is used by the EAP method for authenticating the user.

## Members

### `username`

A NULL-terminated Unicode string that contains the username that needs authentication. The username uses the format user@domain or domain\user.

### `password`

A NULL-terminated Unicode string that contains the password to verify the user. The password is encrypted using the [CredProtect](https://learn.microsoft.com/windows/win32/api/wincred/nf-wincred-credprotectw) function. The EAP method must use the [CredUnprotect](https://learn.microsoft.com/windows/win32/api/wincred/nf-wincred-credunprotecta) function to retrieve the unencrypted password.

## See also

[EapCredential](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eapcredential)
[EapCredentialType](https://learn.microsoft.com/windows/desktop/api/eaptypes/ne-eaptypes-eapcredentialtype)