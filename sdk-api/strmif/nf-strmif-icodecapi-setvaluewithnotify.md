# ICodecAPI::SetValueWithNotify

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetValueWithNotify** method sets a property on a codec and returns a list of other properties that changed as a result.

## Parameters

### `Api` [in]

Pointer to a GUID that specifies the property to set.
For a list of standard codec properties, see [Codec API Properties](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-properties).

### `Value` [in]

Pointer to a **VARIANT** that contains the new value for the property.

### `ChangedParam` [out]

Receives a pointer to an array of GUIDs. The array contains the GUIDs of any properties that changed as a result of this method call. The caller must free the array by calling **CoTaskMemFree**.

### `ChangedParamCount` [out]

Receives the number of elements in the *ChangedParam* array.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | Not implemented. |

## Remarks

Codecs that implement [ICodecAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi) are not required to support this method.

## See also

[Codec API Reference](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-reference)

[Encoder API](https://learn.microsoft.com/windows/desktop/DirectShow/encoder-api)

[ICodecAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)

[ICodecAPI::GetValue](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-icodecapi-getvalue)