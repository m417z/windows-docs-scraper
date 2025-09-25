# IEncoderAPI::IsAvailable

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

[[IEncoderAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iencoderapi) is no longer available for use. Instead, use [ICodecAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi).]

The **IsAvailable** method queries whether a given parameter can be read and modified.

## Parameters

### `Api` [in]

Pointer to a GUID that specifies the parameter.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The parameter can be read and modified. (Set and get operations are supported for this parameter.) |
| **E_NOTIMPL** | The parameter cannot be read or modified. |

## Remarks

Any errors besides those in the table above indicate an inability to process the call.

## See also

[Encoder API](https://learn.microsoft.com/windows/desktop/DirectShow/encoder-api)

[IEncoderAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iencoderapi)