# IAnalogLocator::get_VideoStandard

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_VideoStandard** method retrieves the format of the analog television signal.

## Parameters

### `AVS` [out]

Pointer to an [AnalogVideoStandard](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-analogvideostandard) variable that receives the format of the analog television signal.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved by using the standard COM **IErrorInfo** interface.

## See also

[IAnalogLocator Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ianaloglocator)

[put_VideoStandard](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ianaloglocator-put_videostandard)