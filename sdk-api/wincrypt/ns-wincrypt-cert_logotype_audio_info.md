# CERT_LOGOTYPE_AUDIO_INFO structure

## Description

The **CERT_LOGOTYPE_AUDIO_INFO** structure contains more detailed information about an audio logotype.

## Members

### `dwFileSize`

The size, in octets, of the audio.

### `dwPlayTime`

The length of play time, in milliseconds, of the audio.

### `dwChannels`

The number of channels in the audio file. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| 1 | The audio file is monaural. |
| 2 | The audio file is stereo. |
| 4 | The audio file contains four channels. |

### `dwSampleRate`

The sample rate of the audio, in samples per second. This member is optional and may be zero.

### `pwszLanguage`

The address of a null-terminated IA5 string that contains the RFC 3066 language identifier that specifies the language of the audio. This member is optional and may be **NULL**.

## See also

[CERT_LOGOTYPE_AUDIO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_logotype_audio)