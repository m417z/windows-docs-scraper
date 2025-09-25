# IComponentType::get__MediaMajorType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get__MediaMajorType** method retrieves the DirectShow media format type as a GUID.

## Parameters

### `MediaMajorTypeGuid` [out]

Pointer to a GUID that will receive the major type.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

This method is available through C++ only. Note the two underscores in the method name as compared to the one underscore for the method that uses a **BSTR** as a parameter.

## See also

[AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type)

[IComponentType Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponenttype)