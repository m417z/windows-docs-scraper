# NET_BUFFER_LIST_GET_HASH_TYPE macro

## Description

The **NET_BUFFER_LIST_GET_HASH_TYPE** macro gets the hash type information from a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

**NET_BUFFER_LIST_GET_HASH_TYPE** returns the hash type of the specified [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

The hash type is an OR value of valid combinations of the following flags:

- NDIS_HASH_IPV4
- NDIS_HASH_TCP_IPV4
- NDIS_HASH_IPV6
- NDIS_HASH_TCP_IPV6
- NDIS_HASH_IPV6_EX
- NDIS_HASH_TCP_IPV6_EX

For more information about hash types and the valid combinations of these flags, see [RSS Hashing Types](https://learn.microsoft.com/windows-hardware/drivers/network/rss-hashing-types)).

## Remarks

A NIC (or its miniport driver) uses the receive side scaling (RSS) hash type to identify the portion of received network data that is used to calculate an RSS hash value.

For more information about the hash type, see [RSS Hashing Types](https://learn.microsoft.com/windows-hardware/drivers/network/rss-hashing-types).

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)