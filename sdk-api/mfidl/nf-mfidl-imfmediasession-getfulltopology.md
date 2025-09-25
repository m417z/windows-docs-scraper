# IMFMediaSession::GetFullTopology

## Description

Gets a topology from the Media Session.

This method can get the current topology or a queued topology.

## Parameters

### `dwGetFullTopologyFlags` [in]

Bitwise **OR** of zero or more flags from the [MFSESSION_GETFULLTOPOLOGY_FLAGS](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfsession_getfulltopology_flags) enumeration.

### `TopoId` [in]

The identifier of the topology. This parameter is ignored if the *dwGetFullTopologyFlags* parameter contains the **MFSESSION_GETFULLTOPOLOGY_CURRENT** flag. To get the identifier of a topology, call [IMFTopology::GetTopologyID](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftopology-gettopologyid).

### `ppFullTopology` [out]

Receives a pointer to the [IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology) interface of the topology. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The Media Session has been shut down. |

## Remarks

If the **MFSESSION_GETFULLTOPOLOGY_CURRENT** flag is specified in the *dwGetFullTopologyFlags* parameter, the method returns the topology for the current presentation. Otherwise, the method searches all of the queued topologies for one that matches the identifier given in the *TopoId* parameter.

This method can be used to retrieve the topology for the current presentation or any pending presentations. It cannot be used to retrieve a topology that has already ended.

The topology returned in *ppFullTopo* is a full topology, not a partial topology.

## See also

[IMFMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasession)

[TOPOID](https://learn.microsoft.com/windows/desktop/medfound/topoid)