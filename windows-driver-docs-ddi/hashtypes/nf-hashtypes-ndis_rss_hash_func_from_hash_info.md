# NDIS_RSS_HASH_FUNC_FROM_HASH_INFO macro

## Description

The **NDIS_RSS_HASH_FUNC_FROM_HASH_INFO** macro gets the hash function from the hash information.

## Parameters

### `_HashInfo`

The hash information.

## Return value

**NDIS_RSS_HASH_FUNC_FROM_HASH_INFO** returns the hash function from the specified hash information. For more information about the hash information, see [**NDIS_RSS_HASH_INFO_FROM_TYPE_AND_FUNC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hashtypes/nf-hashtypes-ndis_rss_hash_info_from_type_and_func).

## Remarks

A NIC (or its miniport driver) uses the receive side scaling (RSS) hashing function to calculate an RSS hash value.

For more information about the hashing functions, see [RSS Hashing Functions](https://learn.microsoft.com/windows-hardware/drivers/network/rss-hashing-functions).

## See also

[**NDIS_RSS_HASH_INFO_FROM_TYPE_AND_FUNC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hashtypes/nf-hashtypes-ndis_rss_hash_info_from_type_and_func)