# PeerGroupShutdown function

## Description

The **PeerGroupShutdown** function closes a peer group created with [PeerGroupStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupstartup) and disposes of any allocated resources.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns the following value.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | The function terminated unexpectedly. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## See also

[Grouping API
Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/grouping-api-functions)

[PeerGroupStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupstartup)