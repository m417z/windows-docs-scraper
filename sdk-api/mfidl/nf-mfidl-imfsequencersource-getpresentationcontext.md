# IMFSequencerSource::GetPresentationContext

## Description

Maps a presentation descriptor to its associated sequencer element identifier and the topology it represents.

## Parameters

### `pPD` [in]

Pointer to the [IMFPresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationdescriptor) interface of the presentation descriptor.

### `pId` [out]

Receives the sequencer element identifier. This value is assigned by the sequencer source when the application calls [IMFSequencerSource::AppendTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsequencersource-appendtopology). This parameter is optional and can be **NULL**.

### `ppTopology` [out]

Receives a pointer to the [IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology) interface of the original topology that the application added to the sequencer source. The caller must release the interface. This parameter can receive the value **NULL** if the sequencer source has switched to the next presentation. This parameter is optional and can be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The presentation descriptor is not valid. |
| **MF_S_SEQUENCER_CONTEXT_CANCELED** | This segment was canceled. |

## Remarks

The topology returned in *ppTopology* is the original topology that the application specified in [AppendTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsequencersource-appendtopology). The source nodes in this topology contain pointers to the native sources. Do not queue this topology on the Media Session. Instead, call [IMFMediaSourceTopologyProvider::GetMediaSourceTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasourcetopologyprovider-getmediasourcetopology) to get the sequencer source's modified topology. The source nodes in the modified topology contain pointers to the sequencer source, rather than the native sources.

## See also

[IMFSequencerSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsequencersource)

[Sequencer Source](https://learn.microsoft.com/windows/desktop/medfound/sequencer-source)