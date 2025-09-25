# IMFTopoLoader::Load

## Description

Creates a fully loaded topology from the input partial topology.

## Parameters

### `pInputTopo` [in]

A pointer to the [IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology) interface of the partial topology to be resolved.

### `ppOutputTopo` [out]

Receives a pointer to the [IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology) interface of the completed topology. The caller must release the interface.

### `pCurrentTopo` [in]

A pointer to the [IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology) interface of the previous full topology. The topology loader can re-use objects from this topology in the new topology. This parameter can be **NULL**. See Remarks.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_TOPO_SINK_ACTIVATES_UNSUPPORTED** | One or more output nodes contain [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) pointers. The caller must bind the output nodes to media sinks. See [Binding Output Nodes to Media Sinks](https://learn.microsoft.com/windows/desktop/medfound/binding-output-nodes-to-media-sinks). |

## Remarks

This method creates any intermediate transforms that are needed to complete the topology. It also sets the input and output media types on all of the objects in the topology. If the method succeeds, the full topology is returned in the *ppOutputTopo* parameter.

You can use the *pCurrentTopo* parameter to provide a full topology that was previously loaded. If this topology contains objects that are needed in the new topology, the topology loader can re-use them without creating them again. This caching can potentially make the process faster. The objects from *pCurrentTopo* will not be reconfigured, so you can specify a topology that is actively streaming data. For example, while a topology is still running, you can pre-load the next topology.

Before calling this method, you must ensure that the output nodes in the partial topology have valid [IMFStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfstreamsink) pointers, not [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) pointers. The Media Session automatically performs this action inside the [IMFMediaSession::SetTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-settopology) method. However, if you call **Load** before calling **SetTopology**, you must bind the output nodes manually. For more information, see [Binding Output Nodes to Media Sinks](https://learn.microsoft.com/windows/desktop/medfound/binding-output-nodes-to-media-sinks).

## See also

[Advanced Topology Building](https://learn.microsoft.com/windows/desktop/medfound/advanced-topology-building)

[IMFTopoLoader](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopoloader)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)