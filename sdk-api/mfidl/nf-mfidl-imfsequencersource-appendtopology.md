# IMFSequencerSource::AppendTopology

## Description

Adds a topology to the end of the queue.

## Parameters

### `pTopology` [in]

Pointer to the [IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology) interface of the topology. This pointer cannot be **NULL**. If an application passes **NULL**, the call fails with an E_INVALIDARG error code.

### `dwFlags` [in]

A combination of flags from the [MFSequencerTopologyFlags](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfsequencertopologyflags) enumeration.

### `pdwId` [out]

Receives the sequencer element identifier for this topology.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_ATTRIBUTENOTFOUND** | The source topology node is missing one of the following attributes:<br><br>* [MF_TOPONODE_STREAM_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/medfound/mf-toponode-stream-descriptor-attribute)<br>* [MF_TOPONODE_PRESENTATION_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/medfound/mf-toponode-presentation-descriptor-attribute)<br>* [MF_TOPONODE_SOURCE](https://learn.microsoft.com/windows/desktop/medfound/mf-toponode-source-attribute) |

## Remarks

The sequencer plays topologies in the order they are queued. You can queue as many topologies as you want to preroll.

The application must indicate to the sequencer when it has queued the last topology on the Media Session. To specify the last topology, set the SequencerTopologyFlags_Last flag in the *dwFlags* parameter when you append the topology. The sequencer uses this information to end playback with the pipeline. Otherwise, the sequencer waits indefinitely for a new topology to be queued.

## See also

[About the Sequencer Source](https://learn.microsoft.com/windows/desktop/medfound/about-the-sequencer-source)

[IMFSequencerSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsequencersource)

[MFCreateTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatetopologynode)