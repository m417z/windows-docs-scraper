# PeerPnrpUnregister function

## Description

The **PeerPnrpUnregister** function deregisters a peer from a PNRP cloud.

## Parameters

### `hRegistration` [in]

Handle to a PNRP registration for the peer node obtained by a previous call to [PeerPnrpRegister](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpregister).

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |

## See also

[PeerPnrpRegister](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpregister)

[PeerPnrpUpdateRegistration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpupdateregistration)