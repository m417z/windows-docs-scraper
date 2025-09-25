# ldap_bind_sW function

## Description

The **ldap_bind_s** function synchronously authenticates a client to the LDAP server.

## Parameters

### `ld` [in]

The session handle.

### `dn` [in]

Pointer to a null-terminated string that contains the distinguished name of the entry used to bind. This can be a DN, a UPN, a WinNT style user name, or other name that the directory server will accept as an identifier.

### `cred` [in]

Pointer to a null-terminated string that contains the credentials with which to authenticate. Arbitrary credentials can be passed using this parameter. The format and content of the credentials depends on the setting of the *method* parameter. For more information, see Remarks.

### `method` [in]

Indicates the authentication method to use. For more information and a listing of valid asynchronous authentication methods, see the Remarks section. For more information and a description of the valid asynchronous authentication method, see
[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind).

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

The introduction of User Account Control in Windows Server 2008 and Windows Vista has a very important consequence with regard to making modifications or additions in LDAP. When a user is logged on to a DC with a restricted UAC Administrator token and using **NULL** credentials, any modification or addition to the directory, or any schema change operation, will fail. This includes DirSync searches, retrieving the SACL from an object's [ntSecurityDescriptor](https://learn.microsoft.com/windows/desktop/ADSchema/a-ntsecuritydescriptor) attribute when using SecurityDescriptorFlags, and many other operations.

These will all fail with insufficient access rights.

If User Account Control is in effect when an administrator logs on to a DC, the administrator will get a restricted token in the logon session. If he or she then uses **ldap_bind_s** with **NULL** credentials, then operations that make modifications or additions will fail.

The implementation of **ldap_bind_s** supports the authentication methods listed in the following table. Calling **ldap_bind_s** with the LDAP_AUTH_SIMPLE option is equivalent to calling [ldap_simple_bind_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind_s).

| Method | Description | Credential |
| --- | --- | --- |
| **LDAP_AUTH_SIMPLE** | Authentication with a plaintext password. | A string that contains the user password. |
| **LDAP_AUTH_DIGEST** | Digest authentication package. | To log in as the current user, set the *dn* and *cred* parameters to **NULL**. To log in as another user, set the *dn* parameter to **NULL** and the *cred* parameter to a pointer to a [SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_a) structure with the appropriate user name, domain name, and password. |
| **LDAP_AUTH_DPA** | Distributed password authentication. Used by Microsoft Membership System. | To log in as the current user, set the *dn* and *cred* parameters to **NULL**. To log in as another user, set the *dn* parameter to **NULL** and the *cred* parameter to a pointer to a [SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_a) structure with the appropriate user name, domain name, and password. |
| **LDAP_AUTH_MSN** | Microsoft Network Authentication Service. | To log in as the current user, set the *dn* and *cred* parameters to **NULL**. To log in as another user, set the *dn* parameter to **NULL** and the *cred* parameter to a pointer to a [SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_a) structure with the appropriate user name, domain name, and password. |
| **LDAP_AUTH_NEGOTIATE** | Generic security services (GSS) (Snego). Does not provide authentication, but instead chooses the most appropriate authentication method from a list of available services and passes all authentication data to that service. | To log in as the current user, set the *dn* and *cred* parameters to **NULL**. To log in as another user, set the *dn* parameter to **NULL** and the *cred* parameter to a pointer to a [SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_a) or [SEC_WINNT_AUTH_IDENTITY_EX](https://learn.microsoft.com/windows/win32/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure with the appropriate user name, domain name, and password. |
| **LDAP_AUTH_NTLM** | NT LAN Manager | To log in as the current user, set the *dn* and *cred* parameters to **NULL**. To log in as another user, set the *dn* parameter to **NULL** and the *cred* parameter to a pointer to a [SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_a) or [SEC_WINNT_AUTH_IDENTITY_EX](https://learn.microsoft.com/windows/win32/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure with the appropriate user name, domain name, and password. |
| **LDAP_AUTH_SICILY** | Covers package negotiation to MSN servers. | To log in as the current user, set the *dn* and *cred* parameters to **NULL**. To log in as another user, set the *dn* parameter to **NULL** and the *cred* parameter to a pointer to a [SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_a) structure with the appropriate user name, domain name, and password. |
| **LDAP_AUTH_SSPI** | Obsolete. Included for backward compatibility. Using this constant selects GSS (Snego) negotiation service. | Same as **LDAP_AUTH_NEGOTIATE**. |

For asynchronous bind authentication, use **LDAP_AUTH_SIMPLE** with [ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind).

The bind operation identifies a client to the directory server by providing a distinguished name and some type of authentication credential, such as a password. The exact credentials are dependent on the authentication method used. If you pass in **NULL** for the credentials with **ldap_bind_s()** (non-simple), the current user or service credentials will be used. If a simple bind method (as in
[ldap_simple_bind_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind_s)) is specified, it is equivalent to a **NULL** plaintext password. For more information, see
[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind).

Be aware that LDAP 2 servers require an application to bind before attempting other operations that require authentication.

Multithreading: Bind calls are unsafe because they apply to the connection as a whole. Use caution if threads share connections and try to thread the bind operations with other operations.

**Note** The Microsoft LDAP client uses a default timeout value of 120 seconds (2 minutes) for each bind-response roundtrip. This timeout value can be changed using the **LDAP_OPT_TIMELIMIT** session option. Other operations do not have a timeout unless specified using
[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option).

When all of the operations on the session handle are completed, the session must be terminated by passing the [LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap) session handle to the [ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind) function. Also, if the **ldap_bind_s** call fails, the session handle should be freed with a call to **ldap_unbind** when no longer required for error recovery.

> [!NOTE]
> The winldap.h header defines ldap_bind_s as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Establishing an LDAP Session](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/establishing-an-ldap-session)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_a)

[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind)

[ldap_simple_bind_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind_s)

[ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind)