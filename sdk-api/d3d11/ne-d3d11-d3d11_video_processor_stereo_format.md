# D3D11_VIDEO_PROCESSOR_STEREO_FORMAT enumeration

## Description

Specifies the layout in memory of a stereo 3D video frame.

## Constants

### `D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_MONO:0`

The sample does not contain stereo data. If the stereo format is not specified, this value is the default.

### `D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_HORIZONTAL:1`

Frame 0 and frame 1 are packed side-by-side, as shown in the following diagram.

![Side-by-side packing](https://learn.microsoft.com/windows/win32/api/d3d11/images/dxgistereo3d02.png)

All drivers that support stereo video must support this format.

### `D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_VERTICAL:2`

Frame 0 and frame 1 are packed top-to-bottom, as shown in the following diagram.

![Top-to-bottom packing](https://learn.microsoft.com/windows/win32/api/d3d11/images/dxgistereo3d01.png)

All drivers that support stereo video must support this format.

### `D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_SEPARATE:3`

Frame 0 and frame 1 are placed in separate resources or in separate texture array elements within the same resource.

All drivers that support stereo video must support this format.

### `D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_MONO_OFFSET:4`

The sample contains non-stereo data. However, the driver should create a left/right output of this sample using a specified offset. The offset is specified in the *MonoOffset* parameter of the [ID3D11VideoContext::VideoProcessorSetStreamStereoFormat](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorsetstreamstereoformat) method.

This format is primarily intended for subtitles and other subpicture data, where the entire sample is presented on the same plane.

Support for this stereo format is optional.

### `D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_ROW_INTERLEAVED:5`

Frame 0 and frame 1 are packed into interleaved rows, as shown in the following diagram.

![Interleaved rows](https://learn.microsoft.com/windows/win32/api/d3d11/images/dxgistereo3d03.png)

Support for this stereo format is optional.

### `D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_COLUMN_INTERLEAVED:6`

Frame 0 and frame 1 are packed into interleaved columns, as shown in the following diagram.

![Interleaved columns](https://learn.microsoft.com/windows/win32/api/d3d11/images/dxgistereo3d04.png)

Support for this stereo format is optional.

### `D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_CHECKERBOARD:7`

Frame 0 and frame 1 are packed in a checkerboard format, as shown in the following diagram.

![Checkerboard packing](https://learn.microsoft.com/windows/win32/api/d3d11/images/dxgistereo3d05.png)

Support for this stereo format is optional.

## Remarks

This enumeration designates the two stereo views as "frame 0" and "frame 1". The *LeftViewFrame0* parameter of the [VideoProcessorSetStreamStereoFormat](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorsetstreamstereoformat) method specifies which view is the left view, and which is the right view.

For packed formats, if the source rectangle clips part of the surface, the driver interprets the rectangle in logical coordinates relative to the stereo view, rather than absolute pixel coordinates. The result is that frame 0 and frame 1 are clipped proportionately.

To query whether the device supports stereo 3D video, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) and check for the **D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_STEREO** flag in the **FeatureCaps** member of the [D3D11_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_caps) structure. If this capability flag is present, it means that the driver supports all of the stereo formats that are not listed as optional. To find out which optional formats are supported, call **GetVideoProcessorCaps** and check the **StereoCaps** member of the structure.

## See also

[Direct3D 11 Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-enumerations)

[ID3D11VideoContext::VideoProcessorSetStreamStereoFormat](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorsetstreamstereoformat)