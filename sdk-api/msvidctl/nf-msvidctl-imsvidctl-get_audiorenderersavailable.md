# IMSVidCtl::get_AudioRenderersAvailable

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_AudioRenderersAvailable** method retrieves the available audio renderers.

## Parameters

### `pVal` [out]

Receives an [IMSVidAudioRendererDevices](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidaudiorendererdevices) interface pointer. The caller must release the interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method returns a read-only collection of input devices. Use the returned [IMSVidAudioRendererDevices](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidaudiorendererdevices) pointer to enumerate the collection.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::get_AudioRendererActive](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_audiorendereractive)