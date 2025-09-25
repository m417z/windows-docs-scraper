# NDIS_RSS_HASH_TYPE_FROM_HASH_INFO macro

## Description

The **NDIS_RSS_HASH_TYPE_FROM_HASH_INFO** macro gets the hash type from the hash information.

## Parameters

### `_HashInfo`

The hash information. For more information about the hash information, see [**NDIS_RSS_HASH_INFO_FROM_TYPE_AND_FUNC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hashtypes/nf-hashtypes-ndis_rss_hash_info_from_type_and_func).

## Return value

NDIS_RSS_HASH_TYPE_FROM_HASH_INFO returns the hash type from the specified hash information. For more information about the hash type, see [RSS Hashing Types](https://learn.microsoft.com/windows-hardware/drivers/network/rss-hashing-types).

## Remarks

A NIC (or its miniport driver) uses the receive side scaling (RSS) hash type to identify the portion of received network data that is used to calculate an RSS hash value.

For more information about the hash type, see [RSS Hashing Types](https://learn.microsoft.com/windows-hardware/drivers/network/rss-hashing-types).

## See also

[**NDIS_RSS_HASH_INFO_FROM_TYPE_AND_FUNC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hashtypes/nf-hashtypes-ndis_rss_hash_info_from_type_and_func)