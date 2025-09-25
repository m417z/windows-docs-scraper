# SEC_WINNT_AUTH_IDENTITY_A structure

## Description

The
**SEC_WINNT_AUTH_IDENTITY** structure enables passing a particular user name and password to the run-time library for the purpose of authentication. The structure is valid for Windows and Macintosh.

## Members

### `User`

String containing the user name.

### `UserLength`

Number of characters in **User**, excluding the terminating **NULL**.

### `Domain`

String containing the domain or workgroup name.

### `DomainLength`

Number of characters in **Domain**, excluding the terminating **NULL**.

### `Password`

String containing the user's password in the domain or workgroup.

### `PasswordLength`

Number of characters in **Password**, excluding the terminating **NULL**.

### `Flags`

Flags used to specify ANSI or UNICODE. Must be one of the following:

#### SEC_WINNT_AUTH_IDENTITY_ANSI

#### SEC_WINNT_AUTH_IDENTITY_UNICODE

## Remarks

This structure must remain valid for the lifetime of the binding handle unless pointed to from the [RPC_HTTP_TRANSPORT_CREDENTIALS](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_http_transport_credentials_a) or [RPC_HTTP_TRANSPORT_CREDENTIALS_V2](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_http_transport_credentials_v2_a) structure.

The strings may be ANSI or UNICODE depending on the value assigned to **Flags**.