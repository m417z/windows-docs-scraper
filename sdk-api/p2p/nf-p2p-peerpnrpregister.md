# PeerPnrpRegister function

## Description

The **PeerPnrpRegister** function registers a peer with a PNRP cloud and returns a handle that can be used for registration updates.

**Note** When called, this function will block until the PNRP service has been initiated.

## Parameters

### `pcwzPeerName` [in]

Pointer to a zero-terminated Unicode string that contains the peer name to register with the PNRP service.

### `pRegistrationInfo` [in, optional]

Pointer to a [PEER_PNRP_REGISTRATION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_pnrp_registration_info) structure that contains the endpoint information for the registering peer node. If **NULL**, the API will register the peer with all known PNRP clouds, and any registered addresses are automatically selected by the infrastructure.

### `phRegistration` [out]

Handle to the PNRP registration for the calling peer node. Use this handle to update the registration or to deregister with the PNRP service.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_IDENTITY_NOT_FOUND** | The local peer is using an identity that does not exist. |

Additionally, this function can return WSA values. For a complete list of possible values, see [PNRP NSP Error Codes](https://learn.microsoft.com/windows/desktop/P2PSdk/pnrp-nsp-error-codes).

## Remarks

A handle must be registered in a process separate of the process it will be resolved in. If a handle is registered and resolved within the same process it will not be recognized.

A name cannot be registered with an endpoint more than once. When updates to a registered name are required, use [PeerPnrpUpdateRegistration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpupdateregistration).

When *pRegistrationInfo* is **NULL**, or PEER_PNRP_AUTO_ADDRESSES is specified for *cAddresses*, the infrastructure will keep the addresses registered up to date as addresses change or cloud availability changes.

## See also

[PeerPnrpUnregister](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpunregister)

[PeerPnrpUpdateRegistration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpupdateregistration)