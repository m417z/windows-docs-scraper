# IEncoderAPI::IsSupported

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

[[IEncoderAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iencoderapi) is no longer available for use. Instead, use [ICodecAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi).]

The **IsSupported** method queries whether a given parameter is supported.

## Parameters

### `Api` [in]

Pointer to a GUID that specifies the parameter.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The encoder supports the parameter. |
| **E_NOTIMPL** | The encoder does not support the parameter. |

## Remarks

The method returns S_OK if the encoder recognizes the GUID. To check whether the parameter can be read or modified, call the [IEncoderAPI::IsAvailable](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iencoderapi-isavailable) method.

Any errors besides those in the table above indicate an inability to process the call.

## See also

[Encoder API](https://learn.microsoft.com/windows/desktop/DirectShow/encoder-api)

[IEncoderAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iencoderapi)