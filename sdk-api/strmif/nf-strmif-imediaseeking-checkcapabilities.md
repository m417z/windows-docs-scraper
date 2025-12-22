# IMediaSeeking::CheckCapabilities

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **CheckCapabilities** method queries whether a stream has specified seeking capabilities.

## Parameters

### `pCapabilities` [in, out]

On input, a pointer to a variable that contains a bitwise **OR** of one or more [AM_SEEKING_SEEKING_CAPABILITIES](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-am_seeking_seeking_capabilities) attributes. When the method returns, the value indicates which of those attributes are available.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | Some but not all of the capabilities in *pCapabilities* are present. |
| **S_OK** | All capabilities in *pCapabilities* are present. |
| **E_FAIL** | No capabilities in *pCapabilities* are present. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

If you are only interested in a few specific capabilities, calling this method is more efficient than calling [IMediaSeeking::GetCapabilities](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-getcapabilities), which checks all the stream's seeking capabilities.

To call this method, declare a **DWORD** variable and set the value to the bitwise-**OR** combination of the [AM_SEEKING_SEEKING_CAPABILITIES](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-am_seeking_seeking_capabilities) flags that you want to test. Pass the address of this value in the *pCapabilities* parameter. When the method returns, *pCapabilities* contains a subset of the original bits, indicating which capabilities are present. The return value indicates whether some, none, or all of the requested capabilities are present.

The following code example shows how to find out whether the stream supports forward seeking, backward seeking, and absolute seeking.

| C++ |
| --- |
| ``` // Set flags for the capabilities you want to check.<br><br>DWORD dwCaps = AM_SEEKING_CanSeekAbsolute \|                 AM_SEEKING_CanSeekForwards \|                AM_SEEKING_CanSeekBackwards;<br><br>HRESULT hr = pMediaSeeking->CheckCapabilities(&dwCaps); if(FAILED(hr))  {     // The stream cannot seek. } else if (hr == S_OK)  {        // The stream can seek forward, backward, and to an absolute position. } else if (hr == S_FALSE) // The stream has some of the capabilities. {     if (dwCaps & AM_SEEKING_CanSeekAbsolute)     {         // The stream can seek to an absolute position.     }     if (dwCaps & AM_SEEKING_CanSeekForwards)     {         // The stream can seek forward.     }     if (dwCaps & AM_SEEKING_CanSeekBackwards)     {         // The stream can seek backward.     } } ``` |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaSeeking Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediaseeking)