# IMSVidCtl::DisableAudio

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **DisableAudio** method disables the audio output device.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method sets the active audio output device to **NULL**.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::put_AudioRendererActive](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-put_audiorendereractive)