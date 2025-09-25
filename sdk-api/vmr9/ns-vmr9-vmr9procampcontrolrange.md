# VMR9ProcAmpControlRange structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `VMR9ProcAmpControlRange` structure specifies the valid range for an image adjustment property. The range depends on the graphics device driver. This structure is used with the Video Mixing Renderer 9 Filter (VMR-9).

## Members

### `dwSize`

Size of the structure, in bytes. The value must be `sizeof(VMR9ProcAmpControlRange)`.

### `dwProperty`

Specifies the image adjustment property to query, as a member of the [VMR9ProcAmpControlFlags](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ne-vmr9-vmr9procampcontrolflags) enumeration. The caller should set this field.

### `MinValue`

Specifies the minimum value for the property. The driver sets this field.

### `MaxValue`

Specifies the maximum value for the property. The driver sets this field.

### `DefaultValue`

Specifies the default value for the property. The default value is the value that does not alter the image. The driver sets this field.

### `StepSize`

Specifies the valid increments from **MinValue** to **MaxValue**. The driver sets this field.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[IVMRMixerControl9::GetProcAmpControlRange](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrmixercontrol9-getprocampcontrolrange)