# PeerPnrpGetCloudInfo function

## Description

The **PeerPnrpCloudInfo** function retrieves information on the Peer Name Resolution Protocol (PNRP) clouds in which the calling peer is participating.

## Parameters

### `pcNumClouds` [out]

The number of PNRP clouds returned in *ppCloudInfo*.

### `ppCloudInfo` [out]

Pointer to a list of [PEER_PNRP_CLOUD_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_pnrp_cloud_info) structures that contain information about the PNRP clouds in which the calling peer is participating.

This data returned by this parameter must be freed by calling [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |

## See also

[PEER_PNRP_CLOUD_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_pnrp_cloud_info)