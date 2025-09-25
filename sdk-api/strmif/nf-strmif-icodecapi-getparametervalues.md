# ICodecAPI::GetParameterValues

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetParameterValues** method gets the list of possible values for a codec property.

This method applies only to properties that support a list of possible values, as opposed to a linear range.

## Parameters

### `Api` [in]

Pointer to a GUID that specifies the property to query. For a list of standard codec properties, see [Codec API Properties](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-properties).

### `Values` [out]

Receives a pointer to an array of **VARIANT** types. The array contains the list of values that the encoder supports for this property. The caller must free each **VARIANT** by calling **VariantClear**. The caller must also free the array by calling **CoTaskMemFree**.

### `ValuesCount` [out]

Receives the number of elements in the *Values* array.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |
| **VFW_E_CODECAPI_LINEAR_RANGE** | The property supports a range of values, not a list. |

## Remarks

If the property supports a range of values, instead of a list, the method returns **VFW_E_CODECAPI_LINEAR_RANGE**. In that case, call [ICodecAPI::GetParameterRange](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-icodecapi-getparameterrange) to get the range of values.

## See also

[Codec API Reference](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-reference)

[Encoder API](https://learn.microsoft.com/windows/desktop/DirectShow/encoder-api)

[ICodecAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)