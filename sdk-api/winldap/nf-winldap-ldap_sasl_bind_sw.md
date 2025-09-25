# ldap_sasl_bind_sW function

## Description

The **ldap_sasl_bind_s** function is a synchronous function that authenticates a client to the LDAP server using SASL.

## Parameters

### `ExternalHandle` [in]

The session handle.

### `DistName` [in]

The distinguished name of the entry used to bind.

### `AuthMechanism` [in]

Indicates the authentication method to use.

### `cred` [in]

The credentials to use for authentication. Arbitrary credentials can be passed using this parameter. The format and content of the credentials depend on the value of the *AuthMechanism* argument passed. For more information, see Remarks.

### `ServerCtrls` [in]

A list of LDAP server controls.

### `ClientCtrls` [in]

A list of LDAP client controls.

### `ServerData` [out]

Authentication data returned by the server in response to the bind request.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

The **ldap_sasl_bind_s** function binds to an LDAP server using the Simple Authentication and Security Layer (SASL) protocol. The bind operation identifies a client to the directory server by providing a distinguished name and some type of authentication credentials. The authentication method being used determines the particular type of credential, and is specified by the *AuthMechanism* argument. This is passed as a string in the form of "**GSSAPI**", "**GSS-SPNEGO**", "**DIGEST-MD5**", and so on. This function can be used to pass arbitrary credentials to the server, so the application must be ready to interpret the response sent back from the server.

**Note** The Microsoft LDAP client uses a default timeout value of 120 seconds (2 minutes) for each bind-response roundtrip. This timeout value can be changed using the **LDAP_OPT_TIMELIMIT** session option. Other operations do not have a timeout unless specified using
[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option).

> [!NOTE]
> The winldap.h header defines ldap_sasl_bind_s as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_a)

[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind)

[ldap_bind_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind_s)

[ldap_sasl_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_sasl_binda)

[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind)

[ldap_simple_bind_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind_s)