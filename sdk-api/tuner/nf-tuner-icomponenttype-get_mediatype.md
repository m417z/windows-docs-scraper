# IComponentType::get_MediaType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_MediaType** method retrieves the DirectShow [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure for the component.

## Parameters

### `MediaType` [out]

Pointer to an [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure that will be filled in with the values associated with the current [ComponentType](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd693036(v=vs.85)).

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type)

[IComponentType Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponenttype)