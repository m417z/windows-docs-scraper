# PEER_SECURITY_INTERFACE structure

## Description

The **PEER_SECURITY_INTERFACE** structure specifies the security interfaces that calls to Peer Graphing APIs use to validate, secure, and free records. Additionally, it allows an application to specify the path to the .DLL that contains an implementation of a security service provider (SSP).

## Members

### `dwSize`

Specifies the size of the structure. Set the value to sizeof(**PEER_SECURITY_INTERFACE**). This member is required and has no default value.

### `pwzSspFilename`

Specifies the full path and file name of a .DLL that implements the SSP interface. See the [SSPI documentation](https://learn.microsoft.com/windows/desktop/P2PSdk/graphing-reference-links) for further information on the SSP interface.

### `pwzPackageName`

Specifies the ID of the security module in the SSP to use.

### `cbSecurityInfo`

Specifies the byte count of the **pbSecurityInfo** member. This member is not required if **pbSecurityInfo** is **NULL**. However, if **pbSecurityInfo** is not **NULL**, this member must have a value.

### `pbSecurityInfo`

Pointer to a buffer that contains the information used to create or open a peer graph. This member is optional and can be **NULL**.

The security data blob pointed to by **pbSecurityInfo** is copied and then passed to the SSPI function call of [AcquireCredentialsHandle](https://learn.microsoft.com/windows/desktop/P2PSdk/graphing-reference-links).

### `pvContext`

Pointer to the security context. This security context is then passed as the first parameter to [PFNPEER_VALIDATE_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/nc-p2p-pfnpeer_validate_record), [PFNPEER_FREE_SECURITY_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/nc-p2p-pfnpeer_free_security_data), and [PFNPEER_SECURE_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/nc-p2p-pfnpeer_secure_record). This member is optional and can be **NULL**.

### `pfnValidateRecord`

Pointer to a callback function that is called when a record requires validation. This member is optional and can be **NULL**. If **pfnSecureRecord** is **NULL**, this member must also be **NULL**.

### `pfnSecureRecord`

Pointer to a callback function that is called when a record must be secured. This member is optional and can be **NULL**. If **pfnValidateRecord** is **NULL**, this member must also be **NULL**.

### `pfnFreeSecurityData`

Pointer to a callback function used to free any data allocated by the callback pointed to by **pfnSecureRecord**. This member is optional and can be **NULL**.

### `pfnAuthFailed`

## Remarks

If you have developed your own SSP, your application must not call the Peer Graphing API to access data in the graphing database; doing so can lead to a deadlock situation. Instead, the application should look at a cached copy of the information.

## See also

[AcquireCredentialsHandle](https://learn.microsoft.com/windows/desktop/P2PSdk/graphing-reference-links)

[PFNPEER_FREE_SECURITY_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/nc-p2p-pfnpeer_free_security_data)

[PFNPEER_SECURE_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/nc-p2p-pfnpeer_secure_record)

[PFNPEER_VALIDATE_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/nc-p2p-pfnpeer_validate_record)

[PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate)

[PeerGraphOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen)