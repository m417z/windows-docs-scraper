# IKsDataTypeCompletion::KsCompleteMediaType

## Description

The **KsCompleteMediaType** method completes a partially-specified media type that was first presented to the **IAMStreamConfig::SetFormat** method.

## Parameters

### `FilterHandle` [in]

Handle to the underlying KS filter.

### `PinFactoryId` [in]

Identifier of the pin factory against which the media type is being completed.

### `AmMediaType` [in, out]

Pointer to a AM_MEDIA_TYPE structure that describes the format of the media samples. **KsCompleteMediaType** receives partially specified media samples, completes the specification, and returns.

## Return value

Returns NOERROR if successful and the media type was completed; otherwise, returns an error code.

## Remarks

The **KsCompleteMediaType** method is primarily used for video media types, in which the **biSizeImage** member of the [KS_BITMAPINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_bitmapinfoheader) structure is known only to the driver, because of the private compression formats supported. If required, the data type handler can query the underlying KS filter in order to complete the given media type.

When the proxy creates an instance of the data type handler for purposes of completing a media type, the proxy passes the media type to the [IKsDataTypeHandler::KsSetMediaType](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksdatatypehandler-kssetmediatype) method to first initialize this data type handler to the particular media type.

For more information about **IAMStreamConfig::SetFormat** and AM_MEDIA_TYPE, see the Microsoft Windows SDK documentation.

## See also

[IKsDataTypeHandler::KsSetMediaType](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksdatatypehandler-kssetmediatype)

[KS_BITMAPINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_bitmapinfoheader)