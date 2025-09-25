# IMFMediaSourceTopologyProvider::GetMediaSourceTopology

## Description

Returns a topology for a media source that builds an internal topology.

## Parameters

### `pPresentationDescriptor` [in]

A pointer to the [IMFPresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationdescriptor) interface of the media source's presentation descriptor. To get this pointer, either call [IMFMediaSource::CreatePresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-createpresentationdescriptor) on the media source, or get the pointer from the [MENewPresentation](https://learn.microsoft.com/windows/desktop/medfound/menewpresentation) event.

### `ppTopology` [out]

Receives a pointer to the topology's [IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology) interface. The caller must release the interface.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. For example, a **NULL** input parameter, or the presentation descriptor is not valid. |

## See also

[IMFMediaSourceTopologyProvider](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasourcetopologyprovider)

[Sequencer Source](https://learn.microsoft.com/windows/desktop/medfound/sequencer-source)