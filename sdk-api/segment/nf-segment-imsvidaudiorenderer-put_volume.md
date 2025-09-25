# IMSVidAudioRenderer::put_Volume

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_Volume** method specifies the audio renderer's volume level.

## Parameters

### `lVol` [in]

Specifies the volume level, in units of .01 decibel (dB).

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Full volume is 0 and silence is 10,000. Multiply the desired decibel level by 100; for example, 100 dB is 10,000.

## See also

[IBasicAudio::put_Volume](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ibasicaudio-put_volume)

[IMSVidAudioRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidaudiorenderer)

[IMSVidAudioRenderer::get_Volume](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidaudiorenderer-get_volume)