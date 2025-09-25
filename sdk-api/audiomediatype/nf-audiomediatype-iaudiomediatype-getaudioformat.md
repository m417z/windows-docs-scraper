## Description

The `GetAudioFormat` method returns the [WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex) structure for the audio data format.

## Return value

The `GetAudioFormat` method returns a pointer to a [WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex) structure.

## Remarks

The pointer that is returned is valid only while the **IAudioMediaType** interface is referenced.

## See also

[WAVEFORMATEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-sysaudio_select_graph)