# IMFPresentationDescriptor::SelectStream

## Description

Selects a stream in the presentation.

## Parameters

### `dwDescriptorIndex` [in]

The stream number to select, indexed from zero. To find the number of streams in the presentation, call [IMFPresentationDescriptor::GetStreamDescriptorCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationdescriptor-getstreamdescriptorcount).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *dwDescriptorIndex* is out of range. |

## Remarks

If a stream is selected, the media source will generate data for that stream. The media source will not generated data for deselected streams. To deselect a stream, call [IMFPresentationDescriptor::DeselectStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationdescriptor-deselectstream).

To query whether a stream is selected, call [IMFPresentationDescriptor::GetStreamDescriptorByIndex](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationdescriptor-getstreamdescriptorbyindex).

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFPresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationdescriptor)

[Presentation Descriptors](https://learn.microsoft.com/windows/desktop/medfound/presentation-descriptors)