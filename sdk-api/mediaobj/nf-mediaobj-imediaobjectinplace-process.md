# IMediaObjectInPlace::Process

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Process` method processes a block of data. The application supplies a pointer to a block of input data. The DMO processes the data in place.

## Parameters

### `ulSize` [in]

Size of the data, in bytes.

### `pData` [in, out]

Pointer to a buffer of size *ulSize*. On input, the buffer holds the input data. If the method returns successfully, the buffer contains the output data.

### `refTimeStart` [in]

Start time of the data.

### `dwFlags` [in]

Either DMO_INPLACE_NORMAL or DMO_INPLACE_ZERO. See Remarks for more information.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure |
| **S_FALSE** | Success. There is still data to process. |
| **S_OK** | Success. There is no remaining data to process. |

## Remarks

If the method fails, the buffer might contain garbage. The application should not use the contents of the buffer.

The DMO might produce output data beyond the length of the input data. This is called an *effect tail*. For example, a reverb effect continues after the input reaches silence. If the DMO has an effect tail, this method returns S_FALSE.

While the application has input data for processing, call the `Process` method with the *dwFlags* parameter set to DMO_INPLACE_NORMAL. If the last such call returns S_FALSE, call `Process` again, this time with a zeroed input buffer and the DMO_INPLACE_ZERO flag. The DMO will now fill the zeroed buffer with the effect tail. Continue calling `Process` in this way until the return value is S_OK, indicating that the DMO has finished processing the effect tail.

If the DMO has no effect tail, this method returns S_TRUE or an error code.

## See also

[IMediaObjectInPlace Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediaobjectinplace)