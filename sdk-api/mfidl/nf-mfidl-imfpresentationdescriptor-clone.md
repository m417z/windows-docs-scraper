# IMFPresentationDescriptor::Clone

## Description

Creates a copy of this presentation descriptor.

## Parameters

### `ppPresentationDescriptor` [out]

Receives a pointer to the [IMFPresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationdescriptor) interface of the new presentation descriptor. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method performs a shallow copy of the presentation descriptor. The stream descriptors are not cloned. Therefore, use caution when modifying the presentation presentation descriptor or its stream descriptors.

If the original presentation descriptor is from a media source, do not modify the presentation descriptor unless the source is stopped. If you use the presentation descriptor to configure a media sink, do not modify the presentation descriptor after the sink is configured.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFPresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationdescriptor)

[Presentation Descriptors](https://learn.microsoft.com/windows/desktop/medfound/presentation-descriptors)