# KERB_PROTOCOL_MESSAGE_TYPE enumeration

## Description

The **KERB_PROTOCOL_MESSAGE_TYPE** enumeration lists the types of messages that can be sent to the [Kerberos](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) authentication package by calling
the [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) function.

Each message corresponds to a dispatch routine and causes the Kerberos authentication package to perform a different task.

## Constants

### `KerbDebugRequestMessage:0`

Reserved.

### `KerbQueryTicketCacheMessage`

This dispatch routine returns information about all of the cached tickets for the specified user [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly).

### `KerbChangeMachinePasswordMessage`

This constant is reserved.

### `KerbVerifyPacMessage`

This constant is reserved.

### `KerbRetrieveTicketMessage`

This dispatch routine retrieves the ticket-granting ticket from the ticket cache of the specified user logon session.

### `KerbUpdateAddressesMessage`

This constant is reserved.

### `KerbPurgeTicketCacheMessage`

This dispatch routine allows selected tickets to be removed from the user logon session's ticket cache. It can also remove all cached tickets.

### `KerbChangePasswordMessage`

This message causes the use of Kerberos Password Change Protocol to change the user's password in a Windows domain or configured non-Windows Kerberos realm that supports this service. The caller must know the current password to change the password for an account.

When changing the password of an account in a non-Windows Kerberos realm, the local computer's registry is consulted to locate the Kerberos password service for the requested domain name.

### `KerbRetrieveEncodedTicketMessage`

This message retrieves the specified ticket, either from the cache, if it is already there, or by requesting it from the Kerberos key distribution center (KDC).

### `KerbDecryptDataMessage`

This constant is reserved.

### `KerbAddBindingCacheEntryMessage`

This constant is reserved.

### `KerbSetPasswordMessage`

This message uses a modified Kerberos Password Change Protocol to change the user's password in the domain or configured non-Windows Kerberos realm that supports this service. The caller must have permission to set the password for the target account. The caller does not need to know the current password for the account.

When changing the password for an account in a non-Windows Kerberos realm, the local computer registry is used to locate the Kerberos password service for the requested domain name.

### `KerbSetPasswordExMessage`

This message extends **KerbSetPasswordMessage** by specifying the client name and realm.

### `KerbAddExtraCredentialsMessage:17`

This message is to add, remove, or replace an extra credential. The **SeTcbPrivilege** is required to alter another logon account's credentials.

### `KerbQueryTicketCacheExMessage`

This message extends **KerbQueryTicketCacheMessage** by specifying the client name and realm.

### `KerbPurgeTicketCacheExMessage`

This message extends **KerbPurgeTicketCacheMessage** by specifying the client name and realm.

### `KerbRefreshSmartcardCredentialsMessage`

This message is a request to refresh the smart card credentials.

### `KerbQuerySupplementalCredentialsMessage`

This constant is reserved.

### `KerbTransferCredentialsMessage`

The dispatch routine transfers credentials from one [LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid) to another **LUID**. The **SeTcbPrivilege** is required.

**Windows Server 2003 and Windows XP:** This constant is not supported.

### `KerbQueryTicketCacheEx2Message`

The dispatch routine queries the Kerberos ticket cache for the specified logon session. The session key type and branch ID are returned in addition to the other information returned when using the **KerbQueryTicketCacheMessage** message type. The **SeTcbPrivilege** is required.

**Windows Server 2003 and Windows XP:** This constant is not supported.

### `KerbSubmitTicketMessage`

The dispatch routine gets the tickets from the KDC and updates the ticket cache. The **SeTcbPrivilege** is required to access another logon account's ticket cache.

**Windows Server 2003 and Windows XP:** This constant is not supported.

### `KerbAddExtraCredentialsExMessage`

The dispatch routine adds, modifies, or deletes an extra credential in one or more [service principal names](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SPNs). The **SeTcbPrivilege** is required to change extra credentials in another user's logon session.

**Windows Server 2003 and Windows XP:** This constant is not supported.

### `KerbQueryKdcProxyCacheMessage`

This message returned information about the KDC proxy cached tickets.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This constant is not supported.

### `KerbPurgeKdcProxyCacheMessage`

This message allows selected KDC proxy tickets to be removed.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This constant is not supported.

### `KerbQueryTicketCacheEx3Message`

The dispatch routine queries the Kerberos ticket cache for the specified logon session. The number of tickets information is returned in addition to the other information returned when using the **KerbQueryTicketCacheEx2Message** message type. The **SeTcbPrivilege** is required.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This constant is not supported.

### `KerbCleanupMachinePkinitCredsMessage`

This message is to clean up and remove any PKINIT device credentials from the computer.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This constant is not supported.

### `KerbAddBindingCacheEntryExMessage`

This message is for adding a binding cache entry. The **SeTcbPrivilege** is required.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This constant is not supported.

### `KerbQueryBindingCacheMessage`

This message queries the binding cache for the number of entries and their data.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This constant is not supported.

### `KerbPurgeBindingCacheMessage`

This message is to clean up entries in the binding cache.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This constant is not supported.

### `KerbPinKdcMessage`

### `KerbUnpinAllKdcsMessage`

### `KerbQueryDomainExtendedPoliciesMessage`

This message queries for a list of the extended domain policies.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This constant is not supported.

### `KerbQueryS4U2ProxyCacheMessage`

This message queries the proxy cache for the information about a service for user (S4U) logon.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This constant is not supported.

#### - KerbVerifyCredentialsMessage

This constant is reserved.