# MFCreateStreamDescriptor function

## Description

Creates a stream descriptor.

## Parameters

### `dwStreamIdentifier`

Stream identifier.

### `cMediaTypes`

Number of elements in the *apMediaTypes* array.

### `apMediaTypes`

Pointer to an array of [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface pointers. These pointers are used to initialize the media type handler for the stream descriptor.

### `ppDescriptor`

Receives a pointer to the [IMFStreamDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfstreamdescriptor) interface of the new stream descriptor. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If you are writing a custom media source, you can use this function to create stream descriptors for the source. This function automatically creates the stream descriptor media type handler and initializes it with the list of types given in *apMediaTypes*. The function does not set the current media type on the handler, however. To set the type, call [IMFMediaTypeHandler::SetCurrentMediaType](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediatypehandler-setcurrentmediatype).

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Presentation Descriptors](https://learn.microsoft.com/windows/desktop/medfound/presentation-descriptors)