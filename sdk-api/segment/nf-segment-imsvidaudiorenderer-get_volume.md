# IMSVidAudioRenderer::get_Volume

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Volume** method retrieves the audio renderer's volume level.

## Parameters

### `lVol` [out]

Pointer to a variable that receives the volume level, in units of .01 decibel (dB).

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Full volume is 0 and silence is 10,000. Divide by 100 to get the equivalent decibel value; for example, 10,000 is 100 dB.

## See also

[IBasicAudio::get_Volume](https://learn.microsoft.com/windows/desktop/api/control/nf-control-ibasicaudio-get_volume)

[IMSVidAudioRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidaudiorenderer)

[IMSVidAudioRenderer::put_Volume](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidaudiorenderer-put_volume)