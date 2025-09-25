# IMFMediaSourcePresentationProvider::ForceEndOfPresentation

## Description

Notifies the source when playback has reached the end of a segment. For timelines, this corresponds to reaching a mark-out point.

## Parameters

### `pPresentationDescriptor` [in]

Pointer to the [IMFPresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationdescriptor) interface of the presentation descriptor for the segment that has ended.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFMediaSourcePresentationProvider](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasourcepresentationprovider)