# WTS_USER_CREDENTIAL structure

## Description

Contains credential information for a user. This structure is used by the [GetUserCredentials](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocolconnection-getusercredentials) method.

## Members

### `UserName`

A string that contains the name of the user.

### `Password`

A string that contains the user password.

### `Domain`

A string that contains the domain name for the user.

## Remarks

The user name and password are plaintext.