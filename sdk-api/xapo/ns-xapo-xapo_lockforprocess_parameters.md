# XAPO_LOCKFORPROCESS_PARAMETERS structure

## Description

Defines stream buffer parameters that remain constant while an XAPO is locked. Used with the [IXAPO::LockForProcess](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/nf-audioenginebaseapo-iaudioprocessingobjectconfiguration-lockforprocess) method.

## Members

### `pFormat`

A WAVFORMATEX describing the format for the stream buffer.

### `MaxFrameCount`

Maximum number of frames in the stream buffer that [IXAPO::Process](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-process) would ever be required to handle, irrespective of dynamic parameter settings.

## Remarks

The byte size of the respective stream buffer must be at least *MaxFrameCount* × (*pFormat*->nBlockAlign) bytes.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)