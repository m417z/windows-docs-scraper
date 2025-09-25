# NET_BUFFER_LIST_GET_HASH_FUNCTION macro

## Description

The **NET_BUFFER_LIST_GET_HASH_FUNCTION** macro gets the hash function information from a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

**NET_BUFFER_LIST_GET_HASH_FUNCTION** returns the hash function used. For more information, see [RSS Hashing Functions](https://learn.microsoft.com/windows-hardware/drivers/network/rss-hashing-functions).

The hash function can be one of the following values:

- **NdisHashFunctionToeplitz**
- **NdisHashFunctionReserved1**
- **NdisHashFunctionReserved2**
- **NdisHashFunctionReserved3**

## Remarks

A NIC (or its miniport driver) uses the receive side scaling (RSS) hashing function to calculate an RSS hash value.

For more information about the hashing functions, see [RSS Hashing Functions](https://learn.microsoft.com/windows-hardware/drivers/network/rss-hashing-functions).

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)