# SAMPR_ENCRYPTED_USER_PASSWORD structure

## Description

The **SAMPR_ENCRYPTED_USER_PASSWORD** stores a user's encrypted password.

## Members

### `Buffer`

An array contains an encrypted password. The contents of the array are calculated using either the **NewPasswordEncryptedWithOldNtPasswordHash** or **NewPasswordEncryptedWithOldLmPasswordHash** functions as defined in [RFC 2433](https://www.ietf.org/rfc/rfc2433.txt), sections A.11 and A.15 respectively.

## See also

[MS-CHAP Password Management Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mschap/ms-chap-password-management-structures)

[MSChapSrvChangePassword2](https://learn.microsoft.com/previous-versions/windows/desktop/api/mschapp/nf-mschapp-mschapsrvchangepassword2)