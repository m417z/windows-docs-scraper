# KSAUDIO_COPY_PROTECTION structure

## Description

The **KSAUDIO_COPY_PROTECTION** structure specifies the copy-protection status of an audio stream.

## Members

### `fCopyrighted`

Indicates whether the stream is copyrighted. If **TRUE**, the stream is copyrighted. If **FALSE**, the stream is not copyrighted and is not subject to copy protection.

### `fOriginal`

Indicates whether the stream is an original, first-generation copy of a stream or a second-generation copy of the original. If **TRUE**, the stream is original. If **FALSE**, it is a second-generation copy.

## Remarks

The [KSPROPERTY_AUDIO_COPY_PROTECTION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-copy-protection) property uses this structure to report whether a stream is copyrighted, and also whether the stream is an original stream or a copy of the original stream.

An audio device that supports copy protection can use copyright and copy-generation information about a stream to prevent unlimited copying of proprietary audio content. For example, the Serial Copy Management System (SCMS) defines one level of copy protection that allows copying of an original, first-generation copy of a stream, but prevents copying of second-generation copies of the stream.

The KSPROPERTY_AUDIO_COPY_PROTECTION property is separate from and unrelated to the implementation of [Digital Rights Management (DRM)](https://learn.microsoft.com/windows-hardware/drivers/audio/digital-rights-management) and the [Secure Audio Path (SAP) for Windows Media](https://learn.microsoft.com/windows/win32/wmformat/the-secure-audio-path-model--deprecated).

## See also

[KSPROPERTY_AUDIO_COPY_PROTECTION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-copy-protection)