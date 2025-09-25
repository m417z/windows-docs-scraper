# IAnalogTVTuningSpace::get_InputType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_InputType** method gets the input type (antenna or cable) intended for the tuning space.

## Parameters

### `InputTypeVal` [out]

Pointer to a variable of type [TunerInputType](https://learn.microsoft.com/previous-versions/windows/desktop/api/strmif/ne-strmif-tunerinputtype) that receives the input type.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IAnalogTVTuningSpace Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ianalogtvtuningspace)