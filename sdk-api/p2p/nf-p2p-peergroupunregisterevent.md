# PeerGroupUnregisterEvent function

## Description

The **PeerGroupUnregisterEvent** function unregisters a peer from notification of peer events associated with the supplied event handle.

## Parameters

### `hPeerEvent` [in]

Handle returned by a previous call to [PeerGroupRegisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupregisterevent). This parameter is required.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns the following value.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The parameter is not valid. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

This function must be called before the HPEEREVENT handle is closed.

## See also

[PeerGroupRegisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupregisterevent)