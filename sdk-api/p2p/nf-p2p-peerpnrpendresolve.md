# PeerPnrpEndResolve function

## Description

The **PeerPnrpEndResolve** function closes the handle for an asynchronous PNRP resolution operation initiated with a previous call to [PeerPnrpStartResolve](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpstartresolve).

## Parameters

### `hResolve` [in]

The handle to the asynchronous peer name resolution operation returned by a previous call to [PeerPnrpStartResolve](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpstartresolve).

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |

## See also

[PeerPnrpStartResolve](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpstartresolve)