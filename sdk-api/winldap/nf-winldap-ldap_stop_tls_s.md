# ldap_stop_tls_s function

## Description

The **ldap_stop_tls_s** function stops the encryption operation started by a call to [ldap_start_tls_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_start_tls_sa).

## Parameters

### `ExternalHandle` [in]

A pointer to an **LDAP** structure that represents the current session.

## Return value

Returns **TRUE** if the function call succeeds. Returns **FALSE** if a bind is currently in progress on the connection, if the connection is not actively connected to the server, or if TLS (SSL) negotiation is in progress on the connection.

## Remarks

The **ldap_stop_tls_s** function should only be called on a connection for which TLS (SSL) was established by using [ldap_start_tls_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_start_tls_sa). It should not be called on a TLS (SSL) connection established by some other function, such as [ldap_sslinit](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_sslinit). Any outstanding requests on the connection will be abandoned before TLS encryption is terminated. If this function fails, that is, returns **FALSE**, close the connection by using [ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind) or [ldap_unbind_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind_s) because the connection can be left in an indeterminate state.

## See also

[Using Start-stop TLS Encryption](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/using-start-stop-tls-encryption)

[ldap_start_tls_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_start_tls_sa)