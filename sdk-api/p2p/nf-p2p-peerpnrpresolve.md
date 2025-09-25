# PeerPnrpResolve function

## Description

The **PeerPnrpResolve** function obtains the endpoint address(es) registered for a specific peer name.

## Parameters

### `pcwzPeerName` [in]

Pointer to a zero-terminated string that contains the peer name for which endpoint addresses will be obtained.

### `pcwzCloudName` [in, optional]

Pointer to a zero-terminated string that contains the name of the PNRP cloud under which to resolve the peer name. If **NULL**, the resolve is performed in all clouds. If PEER_PNRP_ALL_LINK_CLOUDS, the resolve is performed in all link local clouds. When "GLOBAL_", resolve will only take place in the global cloud.

### `pcEndpoints` [in, out]

The maximum number of endpoints to return in *ppEndpoints*. Upon return, this parameter contains the actual number of endpoints in *ppEndpoints*.

### `ppEndpoints` [out]

Pointer to a list of [PEER_PNRP_ENDPOINT_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_pnrp_endpoint_info) structures that contain the endpoints for which the peer name successfully resolved. Each endpoint contains one or more IP addresses at which the peer node can be reached.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |

## Remarks

This call is synchronous and will block until completed. For asynchronous peer name resolution, call [PeerPnrpStartResolve](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpstartresolve) and obtain the resolved endpoint address when the supplied event is raised.

A handle must be resolved in a process separate of the process it was registered in. If a handle is registered and resolved within the same process it will not be recognized.

When resolution is performed for all clouds, it is issued to each cloud simultaneously. The method will return as soon as it has received enough results from any combination of clouds.

The default resolve timeout used internally by this method is 30 seconds. If a specific timeout is required,the asynchronous [PeerPnrpStartResolve](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpstartresolve) function should be used.

## See also

[PeerPnrpStartResolve](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpstartresolve)