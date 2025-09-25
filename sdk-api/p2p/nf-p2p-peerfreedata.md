# PeerFreeData function

## Description

The **PeerFreeData** function deallocates a block of data and returns it to the memory pool. Use the **PeerFreeData** function to free data that the Peer Identity Manager, Peer Grouping, and Peer Collaboration APIs return.

## Parameters

### `pvData` [in]

Pointer to a block of data to be deallocated. This parameter must reference a valid block of memory.

## Return value

There are no return values.

## Remarks

Do not use this function to release memory that the Peer Graphing API returns. Use [PeerGraphFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphfreedata) for memory that the Peer Graphing API returns.

## See also

[Grouping API
Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/grouping-api-functions)

[Identity Manager Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/identity-manager-functions)