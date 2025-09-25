# ICodecAPI::GetParameterRange

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetParameterRange** method gets the range of values for a codec property.

This method applies only to properties whose values form a linear range.

## Parameters

### `Api` [in]

Pointer to a GUID that specifies the property to query. For a list of standard codec properties, see [Codec API Properties](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-properties).

### `ValueMin` [out]

Pointer to a **VARIANT** that receives the minimum value of the property. The caller must free the **VARIANT** by calling **VariantClear**.

### `ValueMax` [out]

Pointer to a **VARIANT** that receives the maximum value of the property. The caller must free the **VARIANT** by calling **VariantClear**.

### `SteppingDelta` [out]

Pointer to a **VARIANT** that receives the stepping delta, which defines the valid increments from *ValueMin* to *ValueMax*. The caller must free the **VARIANT** by calling **VariantClear**.

If the **VARIANT** type is VT_EMPTY, any increment is valid.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **S_OK** | The method succeeded. |
| **VFW_E_CODECAPI_ENUMERATED** | The property supports a list of possible values, not a linear range. |

## Remarks

The valid range for the property is [*ValueMin*... *ValueMax*], with increments of *SteppingDelta*. If a property supports a linear range of values, the property must use one of the following variant types:

* Unsigned types: **VT_UI8**, **VT_UI4**, **VT_UI2**, **VT_UI1**
* Signed types: **VT_I8**, **VT_I4**, **VT_I2**
* Floating-point types: **VT_R8**, **VT_R4**

If the property supports a list of values, instead of a range, the method returns **VFW_E_CODECAPI_ENUMERATED**. In that case, call [ICodecAPI::GetParameterValues](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-icodecapi-getparametervalues) to get the list of values.

## See also

[Codec API Reference](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-reference)

[Encoder API](https://learn.microsoft.com/windows/desktop/DirectShow/encoder-api)

[ICodecAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)