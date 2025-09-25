# VMR9PresentationInfo structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `VMR9PresentationInfo` structure is used with the VMR-9 in the [IVMRImagePresenter9::PresentImage](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrimagepresenter9-presentimage) method.

## Members

### `dwFlags`

Contains a bitwise combination of flags from the [VMR9PresentationFlags](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ne-vmr9-vmr9presentationflags) enumeration type. These flags describe the status of the video sample with respect to its presentation time.

### `lpSurf`

Pointer to the DirectDraw surface that contains the video frame.

### `rtStart`

Specifies the start time for the video frame.

### `rtEnd`

Specifies the end time for the video frame

### `szAspectRatio`

Specifies the aspect ratio of the video, as a **SIZE** structure.

### `rcSrc`

Specifies the source rectangle.

### `rcDst`

Specifies the destination rectangle.

### `dwReserved1`

Reserved.

### `dwReserved2`

Reserved.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)