# IMFSequencerSource::UpdateTopologyFlags

## Description

Updates the flags for a topology in the queue.

## Parameters

### `dwId` [in]

Sequencer element identifier of the topology to update.

### `dwFlags` [in]

Bitwise **OR** of flags from the [MFSequencerTopologyFlags](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfsequencertopologyflags) enumeration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFSequencerSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsequencersource)

[Sequencer Source](https://learn.microsoft.com/windows/desktop/medfound/sequencer-source)