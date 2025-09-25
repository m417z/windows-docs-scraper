# IAMVideoAccelerator::GetUncompFormatsSupported

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetUncompFormatsSupported** method gets a list of uncompressed pixel formats that can be rendered using a specified DirectX Video Acceleration (DXVA) profile.

## Parameters

### `pGuid` [in]

Pointer to a GUID that specifies the DXVA profile. To get a list of supported profiles, call
[IAMVideoAccelerator::GetVideoAcceleratorGUIDs](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-getvideoacceleratorguids).

### `pdwNumFormatsSupported` [in, out]

On input, specifies the number of elements in the *pFormatsSupported* array.
If *pFormatsSupported* is **NULL**, the value of `*pdwNumFormatsSupported` must be zero.

On output, if *pFormatsSupported* is **NULL**, *pdwNumFormatsSupported* receives the number of supported pixel formats. Otherwise, *pdwNumFormatsSupported* receives the actual number of pixel formats copied to the *pFormatsSupported* array.

### `pFormatsSupported` [in, out]

Address of an array of **DDPIXELFORMAT** structures, or **NULL**. If the value is non-**NULL**, the array receives a list of pixel formats.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **DDERR_MOREDATA** | The method returned fewer formats than the total number that are supported, because the array was too small. Although this value is a failure code, you can ignore the error if you intentionally allocated a smaller array. |
| **S_OK** | The method succeeded. |

## Remarks

Call this method twice. On the first call, set *pFormatsSupported* to **NULL**. The *pdwNumFormatsSupported* parameter receives the number of formats. Allocate an array of **DDPIXELFORMAT** structures with the required size, and call the method again. This time, set *pFormatsSupported* to the address of the array. The method fills the array with the list of pixel formats.

The driver should return the formats in decreasing order of preference, with the most preferred format listed first.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[How Decoders Use IAMVideoAccelerator](https://learn.microsoft.com/windows/desktop/DirectShow/how-decoders-use-iamvideoaccelerator)

[IAMVideoAccelerator Interface](https://learn.microsoft.com/windows/desktop/api/videoacc/nn-videoacc-iamvideoaccelerator)