# IMSVidVideoRenderer::put_DecimateInput

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_DecimateInput** method specifies whether the Video Mixing Renderer (VMR) will decimate the video (that is, reduce the native video size) before processing it.

This method is currently not supported.

## Parameters

### `pDeci`

Specifies whether to enable or disable video decimation. Use one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_TRUE | Enable video decimation. |
| VARIANT_FALSE | Disable video decimation. |

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This property should be set to true when the native video stream is HDTV but the system monitor is set to a lower resolution. This prevents the VMR from doing unnecessary work by processing the video at high resolution and then shrinking it.

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IVMRMixerControl::SetMixingPrefs](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrmixercontrol-setoutputrect)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)