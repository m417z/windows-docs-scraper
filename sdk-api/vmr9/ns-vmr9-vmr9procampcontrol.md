# VMR9ProcAmpControl structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `VMR9ProcAmpControl` structure specifies the image adjustments to be performed on a video stream. This structure is used with the [Video Mixing Renderer Filter 9](https://learn.microsoft.com/windows/desktop/DirectShow/video-mixing-renderer-filter-9) (VMR-9).

## Members

### `dwSize`

Size of the structure, in bytes. The value must be `sizeof(VMR9ProcAmpControl)`.

### `dwFlags`

Bitwise combination of flags from the [VMR9ProcAmpControlFlags](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ne-vmr9-vmr9procampcontrolflags) enumeration, indicating which properties the driver supports.

### `Brightness`

Specifies the image brightness. Brightness, also called black-level setup, specifies the viewing black level. Functionally, it adds or subtracts the same number of quantizing steps (bits) from all the luminance words in a picture.

### `Contrast`

Specifies the image contrast. Contrast alters the relative light-to-dark values in a picture. Functionally it maps the range of input values to a smaller or larger range of output values.

### `Hue`

Specifies the image hue. Perceptually, hue corresponds approximately to "color." Functionally, hue is a phase relationship of the chrominance components. It is specified in degrees, with a nominal valid range from –180 to 180 degrees and a default value of 0.

### `Saturation`

Specifies the image saturation. Saturation alters the color intensity of the image. Functionally it is similar to contrast, but operates on the chroma components of the image.

## Remarks

The valid range of values for each property depends on the graphics device driver. Call the [IVMRMixerControl9::GetProcAmpControlRange](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrmixercontrol9-getprocampcontrolrange) method to get the range for each property.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)