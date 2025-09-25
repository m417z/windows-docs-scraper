# IMSVidCtl::get_AudioRendererActive

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_AudioRendererActive** method retrieves the audio renderer that is currently active.

## Parameters

### `pVal` [out]

Receives an [IMSVidAudioRenderer](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidaudiorenderer) interface pointer. The caller must release the interface. If no audio renderer is active, this parameter receives the value **NULL**.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | **NULL** pointer argument. |

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::put_AudioRendererActive](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-put_audiorendereractive)