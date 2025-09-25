# PeerGroupSendData function

## Description

The **PeerGroupSendData** function sends data to a member over a neighbor or direct connection.

## Parameters

### `hGroup` [in]

Handle to the group that contains both members of a connection. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `ullConnectionId` [in]

Unsigned 64-bit integer that contains the ID of the connection that hosts the data transmission. A connection ID is obtained by calling [PeerGroupOpenDirectConnection](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopendirectconnection). This parameter is required.

### `pType` [in]

Pointer to a **GUID** value that uniquely identifies the data being transmitted. This parameter is required.

### `cbData` [in]

Specifies the size of the data in *pvData*, in bytes. This parameter is required.

### `pvData` [in]

Pointer to the block of data to send. The receiving application is responsible for parsing this data. This parameter is required.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **PEER_E_CONNECTION_NOT_FOUND** | A connection with the ID specified in *ullConnectionId* cannot be found. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

To receive data, the receiving peer must have registered for the **PEER_GROUP_EVENT_INCOMING_DATA** peer event.

## See also

[PeerGroupCloseDirectConnection](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupclosedirectconnection)

[PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate)

[PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin)

[PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen)

[PeerGroupOpenDirectConnection](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopendirectconnection)