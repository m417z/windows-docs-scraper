# IMFPresentationDescriptor::GetStreamDescriptorCount

## Description

Retrieves the number of stream descriptors in the presentation. Each stream descriptor contains information about one stream in the media source. To retrieve a stream descriptor, call the [IMFPresentationDescriptor::GetStreamDescriptorByIndex](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationdescriptor-getstreamdescriptorbyindex) method.

## Parameters

### `pdwDescriptorCount` [out]

Receives the number of stream descriptors.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFPresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationdescriptor)

[Presentation Descriptors](https://learn.microsoft.com/windows/desktop/medfound/presentation-descriptors)