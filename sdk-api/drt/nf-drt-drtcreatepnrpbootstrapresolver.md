# DrtCreatePnrpBootstrapResolver function

## Description

The **DrtCreatePnrpBootstrapResolver** function creates a bootstrap resolver based on the Peer Name Resolution Protocol (PNRP).

## Parameters

### `fPublish` [in]

If **TRUE**, the PeerName contained in *pwzPeerName* and passed with the PNRP Bootstrap Resolver is published by the local DRT using PNRP. This node will be resolvable by other nodes using the PNRP bootstrap provider, and will assist other nodes attempting to bootstrap

### `pwzPeerName` [in]

The name of the peer to search for in the PNRP cloud. This string has a maximum limit of 137 unicode characters

### `pwzCloudName` [in, optional]

The name of the cloud to search for in for the DRT corresponding to the MeshName.

This string has a maximum limit of 256 unicode characters. If left blank the PNRP Bootstrap Provider will use all PNRP clouds available.

### `pwzPublishingIdentity` [in, optional]

The PeerIdentity that is publishing into the PNRP cloud utilized for bootstrapping. This string has a maximum limit of
137 unicode characters.
It is important to note that if *fPublish* is set to **TRUE**, the *PublishingIdentity* must be allowed to publish the PeerName specified.

### `ppResolver` [out]

A pointer to the created PNRP bootstrap resolver which is used in the [DRT_SETTINGS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_settings) structure.

## Return value

This function returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | The system cannot allocate memory for the provider. |
| **E_INVALIDARG** | *pwzPeerName* is invalid. |
| **DRT_S_RETRY** | Underlying calls to [PeerPnrpStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpstartup) or [PeerIdentityGetCryptKey](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peeridentitygetcryptkey) return a transient error. Try calling this function again. |

**Note** This function may also surface errors returned by underlying calls to [PeerPnrpStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpstartup) or [PeerIdentityGetCryptKey](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peeridentitygetcryptkey).

## Remarks

The default PNRP Bootstrap Resolver created by this function is specific to the DRT it is created for. As a result it cannot be re-used across multiple DRTs.

## See also

[DRT_SETTINGS](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_settings)

[DrtDeletePnrpBootstrapResolver](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtdeletepnrpbootstrapresolver)