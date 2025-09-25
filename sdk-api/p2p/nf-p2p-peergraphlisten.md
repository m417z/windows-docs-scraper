# PeerGraphListen function

## Description

The **PeerGraphListen** function indicates that a peer graph should start listening for incoming connections.

## Parameters

### `hGraph` [in]

Specifies the peer graph to listen on.

### `dwScope` [in]

Specifies the IPv6 scope to listen on. Valid values are identified in the following table. For more information about scope, see [Link-Local and Site-Local Addresses](https://learn.microsoft.com/windows/desktop/P2PSdk/graphing-reference-links).

| Value | Meaning |
| --- | --- |
| **PEER_GRAPH_SCOPE_GLOBAL** | Scope includes the Internet. |
| **PEER_GRAPH_SCOPE_SITELOCAL** | Scope is restricted to a site, for example, a corporation intranet. |
| **PEER_GRAPH_SCOPE_LINKLOCAL** | Scope is restricted to a local subnet. |

### `dwScopeId` [in]

Specifies the IPv6 scope ID to listen on. Specify zero (0) to listen on all interfaces of the specified scope.

**Note** The scope ID zero (0) is not allowed if *dwScope* is **PEER_GRAPH_SCOPE_SITELOCAL** or **PEER_GRAPH_SCOPE_LINKLOCAL**.

### `wPort` [in]

Specifies the port to listen on. Specify zero (0) to use a dynamic port. If zero (0) is specified, use [PeerGraphGetNodeInfo](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetnodeinfo) to retrieve data.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns one of the values identified in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_GRAPH_NOT_READY** | The graph has never been synchronized. An application cannot listen until the peer graph has been synchronized. |
| **PEER_E_INVALID_GRAPH** | The handle to the peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | The graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup)—before using this function. |

## Remarks

To be able to accept direct connections, a node must subscribe to the **PEER_GRAPH_EVENT_DIRECT_CONNECTION** event.

Before this function can be called, the application must call [PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate) or [PeerGraphOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen).

**Note** If this is the first time a peer graph is opened, all calls to **PeerGraphListen** fail until the node connects to and synchronizes with the peer graph.

The application can specify the same port ID for different peer graphs, if all the peer graphs are in the same process.

#### Examples

The following code snippet shows how to use the **PeerGraphListen** function.

```cpp
    // g_hGraph is a handle to the Graph obtained from a previous successful call to PeerGraphCreate or PeerGraphOpen.
    // dwScope should be set to the same scope used to create the graph.  This example assumes the graph was created in the Global scope.
    // g_usPort is the port to use for Graphing.  Use zero to obtain a port dynamically.
    HRESULT hr = PeerGraphListen(g_hGraph, PEER_GRAPH_SCOPE_GLOBAL, 0, g_usPort);

    if (FAILED(hr))
    {
        // Insert your code to handle the error here.
    }
    else
    {
        // Insert your application specific code here.
    }

```

## See also

[PeerGraphConnect](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphconnect)

[PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate)

[PeerGraphGetNodeInfo](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetnodeinfo)

[PeerGraphOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphopen)