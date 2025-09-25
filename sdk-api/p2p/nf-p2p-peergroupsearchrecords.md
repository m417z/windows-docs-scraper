# PeerGroupSearchRecords function

## Description

The **PeerGroupSearchRecords** function searches the local peer group database for records that match the supplied criteria.

## Parameters

### `hGroup` [in]

Handle to the peer group whose local database is searched. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `pwzCriteria` [in]

Pointer to a Unicode XML string that contains the record search query. For information about formulating an XML query string to search the peer group records database, see the [Record Search Query Format](https://learn.microsoft.com/windows/desktop/P2PSdk/record-search-query-format) documentation. This parameter is required.

### `phPeerEnum` [out]

Pointer to the enumeration that contains the returned list of records. This handle is passed to
[PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem) to retrieve the items with each item represented as a pointer to a [PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record) structure. When finished, [PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration) is called to return the memory used by the enumeration. This parameter is required.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory available to complete the operation. |
| **PEER_E_INVALID_SEARCH** | The XML search query does not adhere to the [search query schema specification](https://learn.microsoft.com/windows/desktop/P2PSdk/record-search-query-format). |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## See also

[PeerEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerendenumeration)

[PeerGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergetnextitem)

[PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate)

[PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin)

[PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen)

[Record Search Query Format](https://learn.microsoft.com/windows/desktop/P2PSdk/record-search-query-format)