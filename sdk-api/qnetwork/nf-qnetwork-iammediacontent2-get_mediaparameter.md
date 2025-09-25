# IAMMediaContent2::get_MediaParameter

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_MediaParameter` method retrieves the value of a custom parameter in the ASX file.

This interface is not supported.

## Parameters

### `EntryNum`

Specifies the location of the parameter in the ASX file.

| Value | Description |
| --- | --- |
| 0 | The parameter is a direct child of the ASX node. |
| > 0 | The parameter is located inside an ENTRY tag; *EntryNum* specifies the entry, indexed from 1. |

### `bstrName`

Specifies the name of the parameter.

### `pbstrValue`

Pointer to a variable that receives the value of the parameter.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

The caller must release the **BSTR** returned in *pbstrValue*, by calling **SysFreeString**.

## See also

[IAMMediaContent2 Interface](https://learn.microsoft.com/windows/desktop/api/qnetwork/nn-qnetwork-iammediacontent2)