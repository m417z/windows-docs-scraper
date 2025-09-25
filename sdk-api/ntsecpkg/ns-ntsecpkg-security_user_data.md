# SECURITY_USER_DATA structure

## Description

The **SecurityUserData** structure contains information about the user of a [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly)/[authentication package](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly). This structure is used by the
[SpGetUserInfo](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spgetuserinfofn) function.

## Members

### `UserName`

The name of the user.

### `LogonDomainName`

The domain the user is logged onto.

### `LogonServer`

The name of the server that logged the user on.

### `pSid`

The [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) of the user.