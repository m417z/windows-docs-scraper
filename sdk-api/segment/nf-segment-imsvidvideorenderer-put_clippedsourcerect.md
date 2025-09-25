# IMSVidVideoRenderer::put_ClippedSourceRect

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_ClippedSourceRect** method specifies the clipping rectangle on the video source.

## Parameters

### `pRect` [in]

Pointer to an [IMSVidRect](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidrect) interface that specifies the rectangle.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

If the current clipping mode is **sslClipByClipRect**, the VMR clips the video image to the video source rectangle and stretches this to fill the Video Control's video window. For more information, see [IMSVidVideoRenderer::put_SourceSize](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_sourcesize).

#### Examples

The following example clips the video image to the upper left corner of the source rectangle.

```cpp

CComPtr<IMSVidVideoRenderer> pVideo;
HRESULT hr = pVideoControl->get_VideoRendererActive(&pVideo);
if (SUCCEEDED(hr))
{
    long lWidth, lHeight;
    CComPtr<IMSVidRect> pRect;

    hr = pVideo->get_AvailableSourceRect(&pRect);
    pRect->get_Height(&lHeight);
    pRect->get_Width(&lWidth);
    pRect->put_Height(lHeight / 2);
    pRect->put_Width(lWidth / 2);
    pVideo->put_SourceSize(sslClipByClipRect);
    hr = pVideo->put_ClippedSourceRect(pRect);
}

```

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IMSVidVideoRenderer::get_ClippedSourceRect](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-get_clippedsourcerect)