# NET_BUFFER_LIST_GET_HASH_VALUE macro

## Description

The **NET_BUFFER_LIST_GET_HASH_VALUE** macro gets the hash value information from a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

**NET_BUFFER_LIST_GET_HASH_VALUE** returns the hash value formatted as a ULONG.

## Remarks

For more information about the hash value, see [RSS Hashing Functions](https://learn.microsoft.com/windows-hardware/drivers/network/rss-hashing-functions).

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)