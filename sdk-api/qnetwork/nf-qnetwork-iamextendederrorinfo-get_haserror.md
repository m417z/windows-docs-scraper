# IAMExtendedErrorInfo::get_HasError

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_HasError` method queries whether an error occurred.

## Parameters

### `pHasError`

Pointer to a variable that receives one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_FALSE | No error. |
| VARIANT_TRUE | An error occurred. |

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

If *pHasError* is true, you can call the **get_ErrorCode** and **get_ErrorDescription** methods to determine the nature of the error.

## See also

[IAMExtendedErrorInfo Interface](https://learn.microsoft.com/windows/desktop/api/qnetwork/nn-qnetwork-iamextendederrorinfo)