# NET_BUFFER_LIST_SET_HASH_VALUE macro

## Description

The **NET_BUFFER_LIST_SET_HASH_VALUE** macro sets the hash value information in a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

### `_HashValue`

The hash value, which is formatted as a ULONG.

## Remarks

For more information about the hash value, see [RSS Hashing Functions](https://learn.microsoft.com/windows-hardware/drivers/network/rss-hashing-functions)

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)