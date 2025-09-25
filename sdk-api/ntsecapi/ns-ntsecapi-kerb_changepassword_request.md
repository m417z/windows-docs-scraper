# KERB_CHANGEPASSWORD_REQUEST structure

## Description

The **KERB_CHANGEPASSWORD_REQUEST** structure contains information used to change a password.

## Members

### `MessageType`

### `DomainName`

**UNICODE_STRING** that contains the domain name of the account for which to change the password.

### `AccountName`

**UNICODE_STRING** that contains the account name of the account for which to change the password.

### `OldPassword`

**UNICODE_STRING** that contains the old password to be changed.

### `NewPassword`

**UNICODE_STRING** that contains the new password.

### `Impersonating`

TRUE if the client is impersonating another [security principal](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). Otherwise, false.