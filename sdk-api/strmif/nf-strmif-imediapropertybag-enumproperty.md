# IMediaPropertyBag::EnumProperty

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `EnumProperty` method retrieves a property/value pair.

## Parameters

### `iProperty` [in]

Index value of the pair.

### `pvarPropertyName` [in, out]

Pointer to a **VARIANT** that receives the property's name.

### `pvarPropertyValue` [in, out]

Pointer to a **VARIANT** that receives the property's value.

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer argument. |
| **HRESULT_FROM_WIN32(ERROR_NO_MORE_ITEMS)** | Index out of range. |

## Remarks

The name is always a string. Set the variant type of the *pvarPropertyName* parameter to VT_EMPTY or VT_BSTR before calling this method.

The value can be a string (for INFO chunks) or an array of bytes (for DISP chunks). Set the variant type of the *pvarPropertyName* parameter to VT_EMPTY, VT_BSTR, or (VT_ARRAY | VT_UI1).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaPropertyBag Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediapropertybag)