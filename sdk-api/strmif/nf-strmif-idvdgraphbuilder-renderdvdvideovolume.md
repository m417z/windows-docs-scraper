# IDvdGraphBuilder::RenderDvdVideoVolume

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `RenderDvdVideoVolume` method completes building a filter graph according to user specifications for playing a DVD-Video volume.

## Parameters

### `lpcwszPathName` [in]

Pointer to the path for the DVD-Video volume to play. Can be **NULL**.

### `dwFlags` [in]

Bitwise OR of flags from [AM_DVD_GRAPH_FLAGS](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-am_dvd_graph_flags) enumeration, specifying how to build the DVD playback graph.

### `pStatus` [out]

Pointer to a [AM_DVD_RENDERSTATUS](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_dvd_renderstatus) structure. When the method returns, the structure indicates any rendering failures.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface. The DirectShow implementation return values include the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *dwFlags* parameter specifies conflicting options. |
| **S_FALSE** | The method partially succeeded. To find out which errors occurred, examine the *pStatus* parameter. |
| **S_OK** | The method succeeded, and all streams were rendered. |
| **VFW_E_DVD_DECNOTENOUGH** | One or more streams could not be rendered.<br><br>If you specified the AM_DVD_HWDEC_ONLY or AM_DVD_SWDEC_ONLY flag in the *dwFlags* parameter, try calling the method again with the AM_DVD_HWDEC_PREFER or AM_DVD_SWDEC_PREFER flag. |
| **VFW_E_DVD_NON_EVR_RENDERER_IN_FILTER_GRAPH** | The filter graph already contains a video renderer. The method returns this error code if you specify the AM_DVD_EVR_ONLY flag in the *dwFlags* parameter but the graph already contains a video renderer other than the Enhanced Video Renderer (VMR) filter. |
| **VFW_E_DVD_RENDERFAIL** | An error occurred while building the graph. For example, the DVD Graph Builder could not create a required filter or could not render any of the streams. |
| **VFW_E_DVD_TOO_MANY_RENDERERS_IN_FILTER_GRAPH** | The filter graph contains more than one video renderer. |

## Remarks

The [AM_DVD_RENDERSTATUS](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_dvd_renderstatus) structure reflects failure codes for this method. Reasons for this method returning S_FALSE include the following:

* The graph has been completely built, but one of the following is true.
  + Overlay mixing doesn't work—the application did not set the AM_DVD_NOVPE flag and the video stream could not be put through the Overlay Mixer. In this case, if the video is decoded in software the application will have enough information to inform the user that the video won't be visible. Hardware-decoded video will be visible only on a TV connected to the NTSC out port of the hardware video decoder.
  + The video decoder does not produce line 21 data. The application can display a warning or informative message that closed captioning is not available because of the decoder.
  + No volume path is specified and the DVD Navigator did not locate any DVD-Video volume to be played. The application can ask the user to insert a DVD-Video disc if none is available in the drive when playback starts.
* Some streams did not render. The application can indicate to the user that some streams can't be played.

This method builds the graph without any knowledge of the DVD-Video file or volume to play. The DVD-Video graph builder builds the graph even if *lpcwszPathName* is **NULL** or if the DVD Navigator filter does not find a default DVD-Video volume to play.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdGraphBuilder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdgraphbuilder)