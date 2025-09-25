# IDirectDrawVideo::GetFourCCCodes

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetFourCCCodes` method retrieves the multimedia format type.

## Parameters

### `pCount`

Pointer to the number of FOURCC codes in the *pCodes* array.

### `pCodes`

Pointer to an array of **DWORD** media tags formerly used for Microsoft multimedia types.

## Return value

Returns an **HRESULT** value.

## Remarks

In the original Windows multimedia APIs, media types were tagged with 32-bit values created from four 8-bit characters and were known as *FOURCC* codes. Because FOURCC codes are unique, a one-to-one mapping has been made possible by allocating a range of 4 billion GUIDs representing FOURCCs.

This method retrieves the FOURCC codes that the current display driver can support. The number available is obtained by calling the method with a valid *pCount* pointer, but with *pCodes* set to **NULL**. In this case, the *pCount* variable will be filled in with the number of FOURCC codes available. An application can then allocate enough **DWORD** values for this many FOURCC codes and call the method again with the array pointer in *pCodes*.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDirectDrawVideo Interface](https://learn.microsoft.com/windows/desktop/api/amvideo/nn-amvideo-idirectdrawvideo)