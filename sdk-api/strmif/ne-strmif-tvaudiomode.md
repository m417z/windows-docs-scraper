# TVAudioMode enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the mode of a TV audio control.

## Constants

### `AMTVAUDIO_MODE_MONO:0x1`

Mono.

### `AMTVAUDIO_MODE_STEREO:0x2`

Stereo.

### `AMTVAUDIO_MODE_LANG_A:0x10`

Language A: Main audio channel.

### `AMTVAUDIO_MODE_LANG_B:0x20`

Languag B: Secondary audio program (SAP).

### `AMTVAUDIO_MODE_LANG_C:0x40`

Language C: Either a third language, or the main audio program plus the SAP (for example, English from one speaker and Japanese from the other speaker).

### `AMTVAUDIO_PRESET_STEREO:0x200`

Stereo preset.

### `AMTVAUDIO_PRESET_LANG_A:0x1000`

Languag A preset.

### `AMTVAUDIO_PRESET_LANG_B:0x2000`

Language B preset.

### `AMTVAUDIO_PRESET_LANG_C:0x4000`

Language C preset.

## Remarks

The **TVAudioMode** flags fall into two groups.

* Bits 0 - 7: Mode flags. These flags include mono/stereo and language (A, B, or C).
* Bits 8 and higher: Preset flags.

**Note** The preset flags require Windows Vista or later.

The mode flags represent the tuner's current audio mode. The preset flags represent settings that can take effect in the future, if the audio signal changes. Often, the secondary audio program is not available, or is available only in mono. An application can use the preset flags to store the user's preferred language while providing a reasonable experience when that language is not available.

The following remarks describe how the [IAMTVAudio](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtvaudio) methods interpret these flags.

[IAMTVAudio::put_TVAudioMode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtvaudio-put_tvaudiomode):

* If you set a mode flag, the tuner switches to that mode immediately. If the mode is not immediately available, the method fails.
* If you set a preset flag, the driver switches to that mode immediately if possible; otherwise, the driver stores the request. If the requested mode becomes available later, the driver switches to that mode. The driver maintains the preset flags across program changes or channel changes. A preset mode fails only if the tuner cannot support that mode. It never fails due to the contents of the audio signal.

You may combine one language mode flag (**AMTVAUDIO_MODE_LANG_A**, **AMTVAUDIO_MODE_LANG_B**, or **AMTVAUDIO_MODE_LANG_C**) with one stereo/mono flag (**AMTVAUDIO_MODE_MONO** or **AMTVAUDIO_MODE_STEREO**). Other combinations of mode flags are not valid. For example, **AMTVAUDIO_MODE_LANG_A** | **AMTVAUDIO_MODE_LANG_B** is not valid.

You may combine more than one preset flag. The driver attempts them in the following order:

1. Language C
2. Language B
3. Language A
4. Stereo

You may combine mode flags and preset flags, but you cannot combine a mode flag and a preset flag for the same language. For example, **AMTVAUDIO_MODE_LANG_A** | **AMTVAUDIO_PRESET_LANG_A** is not valid. Mode flags have priority over preset flags.

If the method fails for any reason, the state of the tuner — that is, the current mode plus the stored presets — does not change.

Except for language C, the tuner always streams the same language over both audio channels.

Example: The caller sets **AMTVAUDIO_PRESET_STEREO** | **AMTVAUDIO_PRESET_LANG_B**. Suppose the current program is available in language A with stereo or language B with mono. The driver selects language B (mono), because that flag takes precedence. Later, the program switches to a commercial that is only available in language A. The driver switches to language A, because language B is not available. When the program resumes, the driver switches back to language B.

[IAMTVAudio::GetAvailableTVAudioModes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtvaudio-getavailabletvaudiomodes): This method returns the modes that are currently available in the signal. This method never returns preset flags.

[IAMTVAudio::GetHardwareSupportedTVAudioModes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtvaudio-gethardwaresupportedtvaudiomodes): This method returns all of the modes supported by the hardware, including preset modes.

[IAMTVAudio::get_TVAudioMode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtvaudio-get_tvaudiomode): This method returns the current mode. This method never returns preset flags.

### Mask Constants

The following constants are defined in Strmif.h:

``` syntax
#define TVAUDIO_MODE_MASK 0x000000ff
#define TVAUDIO_PRESET_MASK 0x0000ff00
```

You can use **TVAUDIO_MODE_MASK** to select mode flags and **TVAUDIO_PRESET_MASK** to select preset flags:

| C++ |
| --- |
| ``` DWORD ModeFlags(DWORD AudioMode) {     return AudioMode & TVAUDIO_MODE_MASK; }   <br><br>DWORD PresetFlags(DWORD AudioMode) {     return AudioMode & TVAUDIO_PRESET_MASK; } ``` |

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IAMTVAudio Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtvaudio)