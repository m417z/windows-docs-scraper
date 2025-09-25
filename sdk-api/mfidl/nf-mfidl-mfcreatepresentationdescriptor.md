# MFCreatePresentationDescriptor function

## Description

Creates a presentation descriptor.

## Parameters

### `cStreamDescriptors`

Number of elements in the *apStreamDescriptors* array.

### `apStreamDescriptors`

Array of [IMFStreamDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfstreamdescriptor) interface pointers. Each pointer represents a stream descriptor for one stream in the presentation.

### `ppPresentationDescriptor`

Receives a pointer to an [IMFPresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationdescriptor) interface of the presentation descriptor. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If you are writing a custom media source, you can use this function to create the source presentation descriptor. The presentation descriptor is created with no streams selected. Generally, a media source should select at least one stream by default. To select a stream, call [IMFPresentationDescriptor::SelectStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationdescriptor-selectstream).

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Presentation Descriptors](https://learn.microsoft.com/windows/desktop/medfound/presentation-descriptors)