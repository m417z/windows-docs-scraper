# IMFSequencerSource::UpdateTopology

## Description

Updates a topology in the queue.

## Parameters

### `dwId` [in]

Sequencer element identifier of the topology to update.

### `pTopology` [in]

Pointer to the [IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology) interface of the updated topology object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The sequencer source has been shut down. |

## Remarks

This method is asynchronous. When the operation is completed, the sequencer source sends an [MESequencerSourceTopologyUpdated](https://learn.microsoft.com/windows/desktop/medfound/mesequencersourcetopologyupdated) event.

## See also

[IMFSequencerSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsequencersource)

[Sequencer Source](https://learn.microsoft.com/windows/desktop/medfound/sequencer-source)