# AMGetErrorTextA function

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AMGetErrorText** function retrieves the error message for a given return code, using the current language setting.

This function converts **HRESULT** return codes to error messages. The constant MAX_ERROR_TEXT_LEN specifies the maximum number of characters in an error message.

## Parameters

### `hr`

**HRESULT** value.

### `pbuffer`

Pointer to a character buffer that receives the error message.

### `MaxLen`

Number of characters in *pBuffer*.

## Return value

Returns the number of characters returned in the buffer, or zero if an error occurred.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/DirectShow/functions)

## Remarks

> [!NOTE]
> The errors.h header defines AMGetErrorText as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).