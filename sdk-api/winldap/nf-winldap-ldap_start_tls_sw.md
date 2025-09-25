# ldap_start_tls_sW function

## Description

The **ldap_start_tls_s** function is used in an active LDAP session to begin using TLS encryption.

## Parameters

### `ExternalHandle` [in]

A pointer to an **LDAP** structure that represents the current session.

### `ServerReturnValue` [out]

Optional. A pointer to a **ULONG** that may contain a server error code. This parameter should be consulted if **LDAP_OTHER** is returned in the return value. Pass in **NULL** if you do not wish to use it.

### `result` [out]

Optional. A pointer to a pointer for an [LDAPMessage](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldapmessage) structure that may contain a server referral message. Pass in **NULL** if you do not wish to use it.

### `ServerControls` [in]

Optional. A NULL-terminated array of pointers to [LDAPControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapcontrola) structures that represent server controls. Pass in **NULL** if you do not want to specify server controls.

### `ClientControls` [in]

Optional. A NULL-terminated array of pointers to [LDAPControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapcontrola) structures that represent client controls. Pass in **NULL** if you do not want to specify client controls.

## Return value

If the function call succeeds, **LDAP_SUCCESS** is returned. **LDAP_UNWILLING_TO_PERFORM** is returned if a TLD/SSL session is already in progress, or if a bind is currently in progress, or if there is an outstanding LDAP request on the connection. If the server rejects the extended operation, **LDAP_OTHER** is returned and the *ServerReturnValue* parameter should be checked for the server error code.

## Remarks

The **ldap_start_tls_s** function is called on an existing LDAP session to initiate the use of TLS (SSL) encryption. The connection must not already have TLS (SSL) encryption enabled, and neither signing nor sealing can already be enabled. Also, a bind cannot be currently in progress on the connection, nor can there be any outstanding LDAP requests on the connection. If these conditions are not met, **LDAP_UNWILLING_TO_PERFORM** is returned. If these conditions are met, the function will send the appropriate extended operation to the server to initiate TLS (SSL), and then negotiate the encryption with the server. If the server rejects the extended operation, **LDAP_OTHER** will be returned, and the *ServerReturnValue* should be checked to retrieve the server error code.

It is possible that the server will return a referral in response to this call. For security reasons, the referral will not be automatically chased. A pointer to the referral message is returned in the *result* parameter.

After **ldap_start_tls_s** is called, automatic referral chasing and autoreconnect are disabled on the connection. They will be restored to their previous settings upon successful completion of the [ldap_stop_tls_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_stop_tls_s) operation.

This function has a default timeout of about thirty seconds. That timeout is used in waiting for responses from the server for the Start TLS extended operation and during the TLS (SSL) negotiation.

For more information about start-stop TLS encryption, see [Using Start-Stop TLS Encryption](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/using-start-stop-tls-encryption).

> [!NOTE]
> The winldap.h header defines ldap_start_tls_s as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Using Start-Stop TLS Encryption](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/using-start-stop-tls-encryption)

[ldap_stop_tls_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_stop_tls_s)