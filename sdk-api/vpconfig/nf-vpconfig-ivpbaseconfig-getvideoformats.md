# IVPBaseConfig::GetVideoFormats

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetVideoFormats` method retrieves the video formats the driver supports.

## Parameters

### `pdwNumFormats` [in, out]

Pointer to a variable that specifies the number of **DDPIXELFORMAT** structures in the *pddPixelFormats* array. On input, specifies the size of the array (in number of array elements). On output, contains the actual number of **DDPIXELFORMAT** structures that were copied into the array. If *pddPixelFormat* is **NULL**, the method returns the required array size.

### `pddPixelFormats` [in, out]

Pointer to an array of **DDPIXELFORMAT** structures, allocated by the caller. The device fills in the array with the format information.

## Return value

Returns S_OK if successful, or an error code otherwise.

## Remarks

The client first calls this method with the value **NULL** for the *pddPixelFormats* parameter. The device returns the number of **DDPIXELFORMAT** structures in the *pddPixelFormatso* parameter. The client allocates an array of that size, and calls the method again, passing the address of the array in the *pddPixelFormats* parameter. The device copies the format information into the buffer, and returns the actual number of copied structures in the *pddPixelFormats* parameter.

The **DDPIXELFORMAT** structure is documented in the Windows DDK.

The client sets the format by calling the [IVPBaseConfig::SetVideoFormat](https://learn.microsoft.com/windows/desktop/api/vpconfig/nf-vpconfig-ivpbaseconfig-setvideoformat) method with an index number, which references one of the format structures returned by this method.

Include Dvp.h and Vptype.h before Vpconfig.h.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVPBaseConfig Interface](https://learn.microsoft.com/windows/desktop/api/vpconfig/nn-vpconfig-ivpbaseconfig)