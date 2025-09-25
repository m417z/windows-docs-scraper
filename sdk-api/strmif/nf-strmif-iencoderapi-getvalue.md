# IEncoderAPI::GetValue

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

[[IEncoderAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iencoderapi) is no longer available for use. Instead, use [ICodecAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi).]

The **GetValue** method retrieves the current value of a specified parameter.

## Parameters

### `Api` [in]

Pointer to a GUID that specifies the parameter.

### `Value` [out]

Receives the value for the parameter specified in *Api*. If *Api* was specified as ENCAPIPARAM_BITRATE_MODE, then *Value* will be one of the [VIDEOENCODER_BITRATE_MODE](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-videoencoder_bitrate_mode) constants.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Encoder API](https://learn.microsoft.com/windows/desktop/DirectShow/encoder-api)

[IEncoderAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iencoderapi)