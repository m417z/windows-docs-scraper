# ldap_set_option function

## Description

The **ldap_set_option** function sets options on connection blocks. For more information about structures, see
[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/data-structures).

## Parameters

### `ld` [in]

The session handle.

### `option` [in]

The name of the option set.

### `invalue` [in]

A pointer to the value that the option is to be given. The actual type of this parameter depends on the setting of the option parameter. The constants LDAP_OPT_ON and LDAP_OPT_OFF can be given for options that have on or off settings.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

Call **ldap_set_option** to access the
[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap) structure that represents an LDAP session. Do not attempt to modify the LDAP data structure directly.

For more information and a description of optional settings that apply to an LDAP session, see
[Session Options](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/session-options). For more information about flags, see
[DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea).

It is now possible to digitally sign or encrypt all of your LDAP traffic to and from a Windows LDAP server using the Kerberos authentication protocol. This new feature provides integrity and confidentiality required by some applications. Be aware that using Secure Sockets Layer (SSL) will give you the same benefits, but requires extensive certificate enrollments for the server and, sometimes, for the client.

To enable signing and sealing, you have to turn on one of the following options prior to calling [ldap_bind_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind_s) with **LDAP_AUTH_NEGOTIATE** for the bind method.

```cpp
#define LDAP_OPT_SIGN      0x95
#define LDAP_OPT_ENCRYPT   0x96
```

To turn off signing and sealing, close the connection by calling [ldap_unbind()](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind) on the connection handle.

Multithreading: Calls to **ldap_set_option** are unsafe because it affects the connection as a whole. Use caution if threads share connections.

## See also

[DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Getting and Setting Session Options](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/getting-and-setting-session-options)

[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_get_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_option)