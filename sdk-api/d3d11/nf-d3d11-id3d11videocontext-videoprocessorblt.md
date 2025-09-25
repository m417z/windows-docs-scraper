## Description

Performs a video processing operation on one or more input samples, and writes the result to a Direct3D surface.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call the [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/win32/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor) method.

### `pView` [in]

A pointer to the [ID3D11VideoProcessorOutputView](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11videoprocessoroutputview) interface for the output surface. The output of the video processing operation will be written to this surface.

### `OutputFrame` [in]

The frame number of the output video frame, indexed from zero.

### `StreamCount` [in]

The number of input streams to process.

### `pStreams` [in]

A pointer to an array of [D3D11_VIDEO_PROCESSOR_STREAM](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_video_processor_stream) structures that contain information about the input streams. The caller allocates the array and fills in each structure. The number of elements in the array is given in the *StreamCount* parameter.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The maximum value of *StreamCount* is given in the **MaxStreamStates** member of the [D3D11_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_video_processor_caps) structure. The maximum number of streams that can be enabled at one time is given in the **MaxInputStreams** member of that structure.

If the output stereo mode is **TRUE**:

* The output view must contain a texture array of two elements.
* At least one stereo stream must be specified.
* If multiple input streams are enabled, it is possible that one or more of the input streams may contain mono data.

Otherwise:

* The output view must contain a single element.
* The stereo format cannot be [D3D11_VIDEO_PROCESSOR_STEREO_FORMAT_MONO](https://learn.microsoft.com/windows/win32/api/d3d11/ne-d3d11-d3d11_video_processor_stereo_format) .

This function does not honor a D3D11 predicate that may have been set.

If the application uses [D3D11 queries](https://learn.microsoft.com/windows/win32/api/d3d11/ne-d3d11-d3d11_query), this function may not be accounted for with **D3D11_QUERY_EVENT** and **D3D11_QUERY_TIMESTAMP** when using feature levels lower than 11. **D3D11_QUERY_PIPELINE_STATISTICS** will not include this function for any feature level.

## See also

[ID3D11VideoContext interface](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11videocontext)