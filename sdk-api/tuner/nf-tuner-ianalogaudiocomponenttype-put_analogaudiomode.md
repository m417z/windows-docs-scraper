# IAnalogAudioComponentType::put_AnalogAudioMode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_AnalogAudioMode** method specifies the analog audio mode.

## Parameters

### `Mode` [in]

Specifies the analog audio mode. This parameter is a variable of type [TVAudioMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/strmif/ne-strmif-tvaudiomode).

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved by using the standard COM **IErrorInfo** interface.

## See also

[IAnalogAudioComponentType Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ianalogaudiocomponenttype)

[get_AnalogAudioMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ianalogaudiocomponenttype-get_analogaudiomode)