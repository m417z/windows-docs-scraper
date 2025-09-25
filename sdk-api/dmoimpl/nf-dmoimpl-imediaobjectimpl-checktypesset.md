# IMediaObjectImpl::CheckTypesSet

## Description

The `CheckTypesSet` method determines whether the media type has been set on all of the streams.

## Return value

Returns **TRUE** if the media type has been set on all of the non-optional streams. Otherwise, returns **FALSE**.

## Remarks

Call this method after any operation that changes the media type on a stream. This method sets a private flag within the class. Some **IMediaObjectImpl** methods test this flag to determine whether certain operations are permitted. These methods generally return DMO_E_TYPE_NOT_SET if the flag is **FALSE**.

The only two methods in **IMediaObject** that change the media type on a stream are **SetInputType** and **SetOutputType**. The class template implements both of these methods.

## See also

[IMediaObjectImpl Class Template](https://learn.microsoft.com/windows/desktop/DirectShow/imediaobjectimpl-class-template)