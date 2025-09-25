# IMediaBuffer::GetBufferAndLength

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetBufferAndLength` method retrieves the buffer and the size of the valid data in the buffer.

## Parameters

### `ppBuffer` [out]

Address of a pointer that receives the buffer array. Can be **NULL** if *pcbLength* is not **NULL**.

### `pcbLength` [out]

Pointer to a variable that receives the size of the valid data, in bytes. Can be **NULL** if *ppBuffer* is not **NULL**.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument |
| **S_OK** | Success |

## Remarks

Either parameter can be **NULL**, in which case it does not receive a value. At least one parameter must be non-**NULL**. If both parameters are **NULL**, the method returns E_POINTER.

The value returned in the *pcbLength* parameter is the size of the valid data in the buffer, not the buffer's allocated size. To obtain the buffer's allocated size, call the [IMediaBuffer::GetMaxLength](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediabuffer-getmaxlength) method.

## See also

[IMediaBuffer Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediabuffer)

[Implementing IMediaBuffer](https://learn.microsoft.com/windows/desktop/DirectShow/implementing-imediabuffer)