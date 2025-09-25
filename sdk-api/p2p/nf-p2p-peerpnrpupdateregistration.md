# PeerPnrpUpdateRegistration function

## Description

The **PeerPnrpUpdateRegistration** function updates the PNRP registration information for a name.

## Parameters

### `hRegistration` [in]

Handle to a PNRP registration for the peer node obtained by a previous call to [PeerPnrpRegister](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpregister).

### `pRegistrationInfo` [in]

Pointer to a [PEER_PNRP_REGISTRATION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_pnrp_registration_info) structure that contains the endpoint information for the registering peer node.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |

## Remarks

The **pwzCloudName** and **cAddresses** members of the [PEER_PNRP_REGISTRATION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_pnrp_registration_info) provided in the *pRegistrationInfo* parameter cannot be changed with PeerPnrpUpdateRegistration. Attempting to do so will return an **E_INVALIDARG** error.

PeerPnrpUpdateRegistration has a maximum payload of 4k.

## See also

[PeerPnrpRegister](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpregister)

[PeerPnrpUnregister](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpunregister)