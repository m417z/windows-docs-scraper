# AUDCLNT_STREAMOPTIONS enumeration

## Description

Defines values that describe the characteristics of an audio stream.

## Constants

### `AUDCLNT_STREAMOPTIONS_NONE`

No stream options.

### `AUDCLNT_STREAMOPTIONS_RAW`

The audio stream is a 'raw' stream that bypasses
all signal processing except for endpoint specific,
always-on processing in the Audio Processing Object (APO), driver, and hardware.

### `AUDCLNT_STREAMOPTIONS_MATCH_FORMAT`

The audio client is requesting that the audio engine match the format proposed by the client. The audio engine
will match this format only if the format is supported by the audio driver and associated APOs.

Supported in Windows 10 and later.

### `AUDCLNT_STREAMOPTIONS_AMBISONICS`

### `AUDCLNT_STREAMOPTIONS_POST_VOLUME_LOOPBACK`

The audio client is requesting that the loopback stream tap into the playing audio after volume and/or mute settings have been applied. The default behavior is for the loopback stream to be tapped before volume and/or mute.

## See also

[Core Audio Enumerations](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-enumerations)