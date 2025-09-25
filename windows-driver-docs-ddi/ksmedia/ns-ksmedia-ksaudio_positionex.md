# KSAUDIO_POSITIONEX structure

## Description

The KSAUDIO_POSITIONEX structure specifies the stream position and the associated timestamp information for a kernel streaming (KS)-based audio driver.

## Members

### `TimerFrequency`

Specifies the number of ticks per second for the timer that produces the timestamps.

### `TimeStamp1`

Specifies the timestamp that is taken immediately prior to the acquisition of the position information.

### `Position`

Specifies the position of the read cursor and the write cursor in the audio buffer of an audio stream.

### `TimeStamp2`

Specifies the timestamp that is taken immediately after the acquisition of the position information.

## Remarks

A KS-based audio driver can use the KSAUDIO_POSITIONEX structure along with the [KSPROPERTY_AUDIO_POSITIONEX](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-positionex) property to return a stream position and a timestamp.

## See also

[KSPROPERTY_AUDIO_POSITIONEX](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-positionex)