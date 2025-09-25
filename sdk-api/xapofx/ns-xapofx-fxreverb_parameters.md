# FXREVERB_PARAMETERS structure

## Description

Parameters for use with the FXReverb XAPO.

## Members

### `Diffusion`

Controls the character of the individual wall reflections. Set to minimum value to simulate a hard flat surface and to maximum value to simulate a diffuse surface.Value must be between FXREVERB_MIN_DIFFUSION and FXREVERB_MAX_DIFFUSION.

### `RoomSize`

Size of the room. Value must be between FXREVERB_MIN_ROOMSIZE and FXREVERB_MAX_ROOMSIZE. Note that physical meaning of RoomSize is subjective and not tied to any particular units. A smaller value will result in reflections reaching the listener more quickly while reflections will take longer with larger values for RoomSize.

## Remarks

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)