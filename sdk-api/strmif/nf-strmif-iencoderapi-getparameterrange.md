# IEncoderAPI::GetParameterRange

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

[[IEncoderAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iencoderapi) is no longer available for use. Instead, use [ICodecAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi).]

The **GetParameterRange** method retrieves the valid range of values that the parameter supports, in cases where the parameter supports a stepped range as opposed to a list of specific values.

## Parameters

### `Api` [in]

Pointer to a GUID that specifies the parameter.

### `ValueMin` [out]

Pointer to a **VARIANT** type that receives the minimum value of the parameter.

### `ValueMax` [out]

Pointer to a **VARIANT** type that receives the maximum value of the parameter.

### `SteppingDelta` [out]

Pointer to a **VARIANT** type that receives the stepping delta, which defines the valid increments from *ValueMin* to *ValueMax*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The property supports a list of possible values, not a linear range. |

## Remarks

The valid range for the parameter is [*ValueMax*...*ValueMax*], with increments of *SteppingDelta*. If a parameter supports a stepped range of values, it must use one of the following variant types:

* Unsigned types : **VT_UI8**, **VT_UI4**, **VT_UI2**, **VT_UI1**
* Signed types : **VT_I8**, **VT_I4**, **VT_I2**
* Float types : **VT_R8**, **VT_R4**

By definition, the parameter will return a specific type.

Any stepping value is valid. If the range has no stepping delta (that is, you can increment by any value), the encoder should return an empty value (**VT_EMPTY**) for *SteppingDelta*.

If *Api* equals **ENCAPIPARAM_BITRATE_MODE**, the method returns **E_NOTIMPL**, because the bitrate mode constants are a list of specific values.

## See also

[Encoder API](https://learn.microsoft.com/windows/desktop/DirectShow/encoder-api)

[IEncoderAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iencoderapi)