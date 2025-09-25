# IMSVidAudioRenderer::put_Balance

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_Balance** method specifies the audio renderer's balance level.

## Parameters

### `lBal` [in]

Specifies the balance level.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The balance level is a value between 10,000 and 10,000, measured in hundredths of a decibel (dB). If the value is -10,000, the left channel is at full volume and the right channel is attenuated by 100 dB. If the value is 10,000, the right channel is at full volume and the left channel is attenuated by 100 dB. If the value is zero, both channels are at full volume.

## See also

[IBasicAudio::put_Balance](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ibasicaudio-put_balance)

[IMSVidAudioRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidaudiorenderer)

[IMSVidAudioRenderer::get_Balance](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidaudiorenderer-get_balance)