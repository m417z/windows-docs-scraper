# _NDIS_RECEIVE_HASH_PARAMETERS structure

## Description

The NDIS_RECEIVE_HASH_PARAMETERS structure specifies the receive hash parameters for a miniport
adapter that supports receive hash calculations.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_RECEIVE_HASH_PARAMETERS structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_RECEIVE_HASH_PARAMETERS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_RECEIVE_HASH_PARAMETERS_REVISION_1.

### `Flags`

A USHORT value that indicates what the miniport driver should do with the hash parameters. The
miniport driver can use these flags to quickly determine which parameters have changed and update the
hash settings accordingly.

In a set request, the flags are defined as follows:

#### NDIS_RECEIVE_HASH_FLAG_ENABLE_HASH

If this flag is set, enable calculating hash values on received frames and place the calculated
hash value in the **NetBufferListHashValue** OOB information in the NET_BUFFER_LIST structure.

If this flag is clear, disable the calculation of hash values on received frames.

If receive hash calculation is enabled, the miniport driver should set this flag; otherwise, this
flag should be clear.

#### NDIS_RECEIVE_HASH_FLAG_HASH_INFO_UNCHANGED

The HashInformation member has not changed. The hash information includes the hash types and hash
function.

If this flag is set, the HashInformation member of the NDIS_RECEIVE_HASH_PARAMETERS structure
should be ignored.

If this flag is cleared, the HashInformation member contains a new value that the miniport driver
must use to calculate hash values on received frames.

#### NDIS_RECEIVE_HASH_FLAG_HASH_KEY_UNCHANGED

The secret key and associated data members have not changed.

If this flag is set, the secret key and associated data members should be ignored.

If this flag is cleared, the secret key or associated data members have changed and miniport
driver must use the new information.

In a query request, the flags are defined as follows:

### `HashInformation`

In a set request, the hash type and hash function that the NIC should use to compute the hash
values for the incoming packets.

In a query request, the hash type and hash function that the NIC is using.

Overlying drivers and NDIS can use the
[NDIS_RSS_HASH_INFO_FROM_TYPE_AND_FUNC](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-rss-hash-info-from-type-and-func) macro to combine the hash type and hash function into hash
information and set the
**HashInformation** member.

Miniport drivers can use the
[NDIS_RSS_HASH_TYPE_FROM_HASH_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-rss-hash-info-from-type-and-func) macro to get the hash type from
**HashInformation** and the
[NDIS_RSS_HASH_FUNC_FROM_HASH_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-rss-hash-info-from-type-and-func) macro to get the hash function.

### `HashSecretKeySize`

The size of the secret key array of the hash function, in bytes. The size of the array is 40 bytes for NdisHashFunctionToeplitz.

### `HashSecretKeyOffset`

The offset of the secret key array of the hash function from the beginning of the
NDIS_RECEIVE_HASH_PARAMETERS structure. Use this offset to get the 320-bit (40 bytes) secret key.

In a set request, the secret key can contain any data that the overlying driver chooses.

In a query request, the secret key contains the data that the NIC is using.

## Remarks

The NDIS_RECEIVE_HASH_PARAMETERS structure defines the hash parameters for the
[OID_GEN_RECEIVE_HASH](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-hash) OID.

**Note** Protocol drivers must disable receive hash calculations before they enable RSS. If
RSS is enabled, a protocol driver disables RSS before it enables receive hash calculations. A miniport
driver should fail a request to enable receive hash calculations or RSS if the other service is currently
enabled.

**Note** The secret key is appended after the NDIS_RECEIVE_HASH_PARAMETERS structure
members.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RSS_HASH_FUNC_FROM_HASH_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-rss-hash-info-from-type-and-func)

[NDIS_RSS_HASH_INFO_FROM_TYPE_AND_FUNC](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-rss-hash-info-from-type-and-func)

[NDIS_RSS_HASH_TYPE_FROM_HASH_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-rss-hash-info-from-type-and-func)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[OID_GEN_RECEIVE_HASH](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-hash)