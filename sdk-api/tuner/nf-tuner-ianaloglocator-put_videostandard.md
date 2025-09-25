# IAnalogLocator::put_VideoStandard

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_VideoStandard** method specifies the format of the analog television signal.

## Parameters

### `AVS` [in]

Specifies the format of the analog television signal. This parameter is of type [AnalogVideoStandard](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-analogvideostandard).

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved by using the standard COM **IErrorInfo** interface.

## See also

[IAnalogLocator Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ianaloglocator)

[get_VideoStandard](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ianaloglocator-get_videostandard)