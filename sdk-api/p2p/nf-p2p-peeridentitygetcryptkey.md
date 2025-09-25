# PeerIdentityGetCryptKey function

## Description

The **PeerIdentityGetCryptKey** function retrieves a handle to a cryptographic service provider (CSP).

## Parameters

### `pwzIdentity` [in]

Specifies the peer identity to retrieve the key pair for.

### `phCryptProv` [out]

Receives a pointer to the handle of the cryptographic service provider (CSP) that contains an AT_KEYEXCHANGE RSA key pair.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_NO_KEY_ACCESS** | Access to the peer identity or peer group keys is denied. Typically, this is caused by an incorrect access control list (ACL) for the folder that contains the user or computer keys. This can happen when the ACL has been manually reset. |
| **PEER_E_NOT_FOUND** | An identity that matches the specified name cannot be found. |

## Remarks

The key can be retrieved by calling [CryptGetUserKey](https://learn.microsoft.com/windows/desktop/P2PSdk/identity-manager-reference-links).

When the handle is not required anymore, the application is responsible for releasing the handle by using [CryptReleaseContext](https://learn.microsoft.com/windows/desktop/P2PSdk/identity-manager-reference-links).

## See also

[CryptGetUserKey](https://learn.microsoft.com/windows/desktop/P2PSdk/identity-manager-reference-links)

CryptReleaseContext