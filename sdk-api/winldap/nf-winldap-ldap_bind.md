# ldap_bind function

## Description

The **ldap_bind** function asynchronously authenticates a client with the LDAP server. The bind operation identifies a client to the directory server by providing a distinguished name and some type of authentication credential, such as a password. The authentication method used determines the type of required credential.

**Caution** Unless a TLS (SSL) encrypted session is established, do not use this function. This function sends the name and password in plaintext. An unauthorized user, monitoring network traffic, could read the password. For more information about how to establish an encrypted session, see [Initializing a Session](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/initializing-a-session).

## Parameters

### `ld` [in]

The session handle.

### `dn` [in]

A pointer to a null-terminated string that contains the distinguished name of the entry used to bind.

### `cred` [in]

A pointer to a null-terminated string that contains the credentials to use for authentication. Arbitrary credentials can be passed using this parameter. The format and content of the credentials depend on the setting of the method parameter. For more information, see the Remarks section.

### `method` [in]

The authentication method to use.

## Return value

If the function succeeds, the return value is the message ID of the initiated operation.

If the function fails, it returns –1 and sets the session error parameters in the LDAP structure.

## Remarks

This implementation of **ldap_bind** supports the following authentication method.

| Authentication method | Description | Credential |
| --- | --- | --- |
| **LDAP_AUTH_SIMPLE** | Authentication with a plaintext password. | A string that contains the user password. |

**LDAP_AUTH_SIMPLE** is the only authentication method compatible with the asynchronous version of binding; **ldap_bind**. Using any other authentication method with **ldap_bind** will fail and return **LDAP_PARAM_ERROR**. Calling **ldap_bind** with the **LDAP_AUTH_SIMPLE** method is equivalent to calling [ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind). All other authentication methods require synchronous binding as provided by [ldap_bind_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind_s).

Be aware that LDAP 2 servers require an application to bind before attempting any other operations that require authentication.

Multithreading: Bind calls are not safe because they apply to the connection as a whole. Use caution if threads share connections and, when possible, thread the bind operations with other operations.

**Note** The Microsoft LDAP client uses a default timeout value of 120 seconds for each bind-response roundtrip. This timeout value can be changed using the **LDAP_OPT_TIMELIMIT** session option. Other operations do not have a timeout unless specified by using
[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option).

When all of the operations on the session handle are completed, terminate the session by passing the [LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap) session handle to the [ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind) function. Also, if the **ldap_bind** call fails, the session handle should be freed with a call to **ldap_unbind** when no longer required for error recovery.

## See also

[Establishing an LDAP Session](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/establishing-an-ldap-session)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_a)

[ldap_bind_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind_s)

[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind)

[ldap_simple_bind_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind_s)

[ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind)