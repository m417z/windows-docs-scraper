# NDIS_RSS_HASH_INFO_FROM_TYPE_AND_FUNC macro

## Description

The **NDIS_RSS_HASH_INFO_FROM_TYPE_AND_FUNC** macro combines a hash type and hash function into hash information and sets the **HashInformation** member in the [**NDIS_RECEIVE_SCALE_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_scale_parameters) structure.

## Parameters

### `_HashType`

The hash type.

The hash type is an OR value of valid combinations of the following flags:

- NDIS_HASH_IPV4
- NDIS_HASH_TCP_IPV4
- NDIS_HASH_IPV6
- NDIS_HASH_TCP_IPV6
- NDIS_HASH_IPV6_EX
- NDIS_HASH_TCP_IPV6_EX

For more information about hash types and the valid combinations of these flags, see [RSS Hashing Types](https://learn.microsoft.com/windows-hardware/drivers/network/rss-hashing-types).

### `_HashFunction`

The hash function that is used.

The hash function can be one of the following values:

- **NdisHashFunctionToeplitz**
- **NdisHashFunctionReserved1**
- **NdisHashFunctionReserved2**
- **NdisHashFunctionReserved3**

For more information about the hashing functions, see [RSS Hashing Functions](https://learn.microsoft.com/windows-hardware/drivers/network/rss-hashing-functions).

## Return value

**NDIS_RSS_HASH_INFO_FROM_TYPE_AND_FUNC** returns the hash information that results from combining the specified hash type and hash function.

## Remarks

Use the [**NDIS_RSS_HASH_TYPE_FROM_HASH_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hashtypes/nf-hashtypes-ndis_rss_hash_type_from_hash_info) and [**NDIS_RSS_HASH_FUNC_FROM_HASH_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hashtypes/nf-hashtypes-ndis_rss_hash_func_from_hash_info) macros to get the hash type and hash function from the hash information.

A NIC (or its miniport driver) uses the receive side scaling (RSS) hash type to identify the portion of received network data that is used to calculate an RSS hash value.

For more information about the hash type, see [RSS Hashing Types](https://learn.microsoft.com/windows-hardware/drivers/network/rss-hashing-types).

A NIC (or its miniport driver) uses the RSS hashing function to calculate an RSS hash value.

For more information about the hashing functions, see [RSS Hashing Functions](https://learn.microsoft.com/windows-hardware/drivers/network/rss-hashing-functions).

## See also

[**NDIS_RECEIVE_SCALE_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_scale_parameters)

[**NDIS_RSS_HASH_FUNC_FROM_HASH_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hashtypes/nf-hashtypes-ndis_rss_hash_func_from_hash_info)

[**NDIS_RSS_HASH_TYPE_FROM_HASH_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hashtypes/nf-hashtypes-ndis_rss_hash_type_from_hash_info)