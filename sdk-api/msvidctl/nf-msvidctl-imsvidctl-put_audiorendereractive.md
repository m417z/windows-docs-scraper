# IMSVidCtl::put_AudioRendererActive

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_AudioRendererActive** method specifies the active audio renderer.

## Parameters

### `pVal` [in]

Pointer to an [IMSVidAudioRenderer](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidaudiorenderer) interface that specifies the audio renderer.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::get_AudioRendererActive](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_audiorendereractive)