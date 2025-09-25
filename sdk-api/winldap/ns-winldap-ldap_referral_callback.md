# LDAP_REFERRAL_CALLBACK structure

## Description

The **LDAP_REFERRAL_CALLBACK** structure is used to implement external caching of connections. This structure is used only when tracking referrals.

## Members

### `SizeOfCallbacks`

The amount of memory required for the callback. Set this field to `sizeof(LDAP_REFERRAL_CALLBACK)`.

### `QueryForConnection`

A pointer to a callback function to determine whether there is a cached connection cached available. For more information, see Remarks.

### `NotifyRoutine`

A pointer to a callback function that determines whether a new connection will be cached or destroyed after the operation completes. For more information, see Remarks.

### `DereferenceRoutine`

A pointer to a callback function to dereference a connection that is not in use. For more information, see Remarks.

## Remarks

Use the **LDAP_REFERRAL_CALLBACK** structure to implement a mechanism for caching connections. The structure contains three callback functions which you implement in your client code.

**QUERYFORCONNECTION**: If a connection is available, this function should return a pointer to the connection to use in *ConnectionToUse*. If no connection is available, the function should set *ConnectionToUse* to **NULL**. The signature for this callback function is as follows.

```cpp
typedef ULONG (_cdecl QUERYFORCONNECTION)(
    PLDAP       PrimaryConnection,
    PLDAP       ReferralFromConnection,
    PWCHAR      NewDN,
    PCHAR       HostName,
    ULONG       PortNumber,
    PVOID       SecAuthIdentity,    // If NULL, use CurrentUser below
    PVOID       CurrentUserToken,   // pointer to current user LUID.
    PLDAP       *ConnectionToUse
);
```

**NOTIFYOFNEWCONNECTION**: The run time calls this function if a new connection was created in the course of chasing a referral. This function should return **FALSE** if not required to cache the connection. When **FALSE** is returned, the connection is destroyed when the operation completes. The function should return **TRUE** if it has taken ownership of the connection and the connection will be cached. Be aware that any new connections so created inherit the current callbacks from the primary connection on which the request was initiated. The signature for this function is.

```cpp
typedef BOOLEAN (_cdecl NOTIFYOFNEWCONNECTION)
    (
    PLDAP       PrimaryConnection,
    PLDAP       ReferralFromConnection,
    PWCHAR      NewDN,
    PCHAR       HostName,
    PLDAP       NewConnection,
    ULONG       PortNumber,
    PVOID       SecAuthIdentity,    // If null, use CurrentUser below.
    PVOID       CurrentUser,        // Pointer to current user LUID.
    ULONG       ErrorCodeFromBind   // If nonzero, bind to server failed.
    );
```

**DEREFERENCECONNECTION**: The LDAP run time calls this function to dereference a connection that is no longer required. The connection may have come from a successful call to **QueryForConnection** or from **NotifyOfNewConnection**. The function should return LDAP_SUCCESS if the call succeeds; currently, however, the run time ignores the return value. The signature for this function is as follows.

```cpp
typedef ULONG (_cdecl DEREFERENCECONNECTION)
    (
    PLDAP       PrimaryConnection,
    PLDAP       ConnectionToDereference
    );
```

To configure a session to use callbacks to obtain a cached connection, call
[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option) (conn, LDAP_OPT_REFERRAL_CALLBACK, &referralRoutines), where *referralRoutines* is the address of the **LDAP_REFERRAL_CALLBACK** structure that contains your routines. The addresses may be **NULL**, in which case the LDAP run time will not make the calls.

The parameter descriptions for the preceding three functions are as follows:

* *PrimaryConnection*

  The LDAP connection handle on which the operation was originally performed. For example, the handle passed in to a call to [ldap_search](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search), [ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result), [ldap_add](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add), and so on.
* *ReferralFromConnection*

  The connection which sent the referral currently tracked. Referrals can be tracked across multiple "hops". For example, the referral can be from the original server to a second server, then the second server can refer the operation to a third server, and so on. If *ReferralFromConnection* equates to *PrimaryConnection*, the first "hop" is being tracked (a referral sent from the original server).
* *NewDN*

  Pointer to a wide, null-terminated string that contains the DN of the referred-to object.
* *HostName*

  Pointer to a null-terminated string that contains the name of the referred-to server; that is the server to which a connection must be made.
* *PortNumber* Port on the referred-to server, to which a connection must be made.
* *SecAuthIdentity*

  The **SEC_WINNT_AUTH_IDENTITY** or **SEC_WINNT_AUTH_IDENTITY_EX** for the credentials used when tracking the referral, or a **NULL** if the user's default credentials are used.
* *CurrentUserToken/CurrentUser*

  The AuthenticationID LUID of the user for which a connection is required. If *SecAuthIdentity* is **NULL**, use this parameter to identify the user.
* *NewConnection*

  Used to announce the existence of the new connection.
* *ErrorCodeFromBind*

  Error code returned from [ldap_bind_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind_s) when an attempt is made to bind to the newly created connection (*NewConnection*).
* *ConnectionToDereference*

  The connection to be dereferenced.

## See also

[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/data-structures)

[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option)