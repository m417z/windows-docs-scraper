# IMPEG2ComponentType::get_StreamType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_StreamType** method retrieves the stream type.

## Parameters

### `MP2StreamType` [out]

Pointer to a variable of type [MPEG2StreamType](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/mpeg2streamtype) that receives the stream type value.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IMPEG2ComponentType Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-impeg2componenttype)