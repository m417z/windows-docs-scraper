# IMediaObjectImpl::InputType

## Description

The `InputType` method retrieves the current media type for a specified input stream.

## Parameters

### `ulInputStreamIndex`

Index of an input stream.

## Return value

Returns a pointer to a [DMO_MEDIA_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/mediaobj/ns-mediaobj-dmo_media_type) structure, or **NULL** if the media type is not set for this stream.

## See also

[IMediaObjectImpl Class Template](https://learn.microsoft.com/windows/desktop/DirectShow/imediaobjectimpl-class-template)