# WSMAN_USERNAME_PASSWORD_CREDS structure

## Description

Defines the credentials used for authentication.

## Members

### `username`

Defines the user name for a local or domain account. It cannot be **NULL**.

### `password`

Defines the password for a local or domain account. It cannot be **NULL**.

## Remarks

The client can specify the credentials to use when creating a shell on a computer. The user name should be specified in the form DOMAIN\username for a domain account or SERVERNAME\username for a local account on a server computer.

If this structure is used, it should have both the user name and password fields specified. It can be used with Basic, Digest, Negotiate, or Kerberos authentication. The client must explicitly specify the credentials when either Basic or Digest authentication is used.