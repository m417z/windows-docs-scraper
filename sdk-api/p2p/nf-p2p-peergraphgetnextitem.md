# PeerGraphGetNextItem function

## Description

The **PeerGraphGetNextItem** function obtains the next item or items in an enumeration created by a call to the following functions, which return a peer enumeration handle:

* [PeerGraphEnumConnections](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumconnections)
* [PeerGraphEnumNodes](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumnodes)
* [PeerGraphEnumRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumrecords)
* [PeerGraphSearchRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphsearchrecords)

## Parameters

### `hPeerEnum` [in]

Handle to an enumeration.

### `pCount` [in, out]

Input specifies the number of items to obtain.

Output receives the actual number of items obtained.

**Note** If *pCount* is a zero (0) output, the end of the enumeration is reached.

### `pppvItems` [out]

Receives an array of pointers to the requested items. The number of pointers contained in an array is specified by the output value of *pCount*. The actual data returned depends on the type of enumeration. The types of structures that are returned are the following: [PEER_CONNECTION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_connection_info), [PEER_NODE_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_node_info), and [PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record)

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One parameter is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform a specified operation. |
| **PEER_E_NOT_INITIALIZED** | The graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## Remarks

 Free *ppvItems* by calling [PeerGraphFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphfreedata) when the data is no longer required.

The application can request a range of items to obtain. The function returns *pCount* or fewer items.

#### Examples

The following code snippet shows you how to use **PeerGraphGetNextItem** to enumerate objects, and end an enumeration after you finish processing the enumeration.

```cpp
//PeerGraphGetNextItem snippet
    // hPeerEnum is a handle to the enumeration obtained from a successful call to PeerGraphEnumConnections,
    // PeerGraphEnumNodes, PeerGraphEnumRecords, or PeerGraphSearchRecords.
    // Set count equal to the maximum number of items you want returned. To obtain a count of all the items
    // in the enumeration, call PeerGraphGetItemCount.
    // ppRecord is an array of pointers to PEER_RECORD objects.  PEER_CONNECTION_INFO and PEER_NODE_INFO structures
    // are also supported.
    HRESULT hr = PeerGraphGetNextItem(hPeerEnum, &count, (PVOID *)&ppRecord);
    if (FAILED(hr))
    {
        // Insert your code to handle the error here.
    }
    else
    {
        // Free the data obtained by PeerGraphGetNextItem.
        PeerGraphFreeData(ppRecord);
    }

    // If you are done with the enumeration, free the handle to the enumeration.
    PeerGraphEndEnumeration(hPeerEnum);

```

## See also

[PEER_CONNECTION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_connection_info)

[PEER_NODE_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_node_info)

[PEER_RECORD](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_record)

[PeerGraphEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphendenumeration)

[PeerGraphEnumConnections](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumconnections)

[PeerGraphEnumNodes](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumnodes)

[PeerGraphEnumRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumrecords)

[PeerGraphFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphfreedata)

[PeerGraphSearchRecords](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphsearchrecords)