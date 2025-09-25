# IMFPresentationDescriptor::GetStreamDescriptorByIndex

## Description

Retrieves a stream descriptor for a stream in the presentation. The stream descriptor contains information about the stream.

## Parameters

### `dwIndex` [in]

Zero-based index of the stream. To find the number of streams in the presentation, call the [IMFPresentationDescriptor::GetStreamDescriptorCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationdescriptor-getstreamdescriptorcount) method.

### `pfSelected` [out]

Receives a Boolean value. The value is **TRUE** if the stream is currently selected, or **FALSE** if the stream is currently deselected. If a stream is selected, the media source generates data for that stream when [IMFMediaSource::Start](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-start) is called. The media source will not generated data for deselected streams. To select a stream, call [IMFPresentationDescriptor::SelectStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationdescriptor-selectstream).To deselect a stream, call [IMFPresentationDescriptor::DeselectStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationdescriptor-deselectstream).

### `ppDescriptor` [out]

Receives a pointer to the stream descriptor's [IMFStreamDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfstreamdescriptor) interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFPresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationdescriptor)

[Presentation Descriptors](https://learn.microsoft.com/windows/desktop/medfound/presentation-descriptors)