# KSDSOUND_BUFFERDESC structure

## Description

The KSDSOUND_BUFFERDESC structure describes a DirectSound buffer.

## Members

### `Flags`

Specifies the buffer configuration. This member can be set to the bitwise OR of one or more of the following flag bits:

#### KSDSOUND_BUFFER_PRIMARY

Indicates that the buffer is a primary sound buffer (the buffer the user hears when a game is playing).

#### KSDSOUND_BUFFER_STATIC

Indicates that the buffer will be used for static sound data.

#### KSDSOUND_BUFFER_LOCHARDWARE

Forces the buffer to use hardware mixing.

#### KSDSOUND_BUFFER_LOCSOFTWARE

Forces the buffer to be stored in system memory and use software mixing.

### `Control`

Specifies the capabilities of the buffer. The capabilities of a buffer are represented by a set of control flags. This member can be set to the bitwise OR of one or more of the following flag bits:

#### KSDSOUND_BUFFER_CTRL_3D

Indicates that the buffer is either a primary buffer or a secondary buffer with 3D-control capability. If this bit is set, the KS pin representing the buffer implements a 3D node ([KSNODETYPE_3D_EFFECTS](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-3d-effects)). If the KSDSOUND_BUFFER_CTRL_HRTF_3D bit is set, the 3D node supports the optional [KSPROPSETID_Hrtf3d](https://learn.microsoft.com/windows-hardware/drivers/audio/kspropsetid-hrtf3d) property set.

#### KSDSOUND_BUFFER_CTRL_FREQUENCY

Indicates that the buffer has frequency-control capability. If this bit is set, the pin representing the buffer implements a sample-rate conversion ([KSNODETYPE_SRC](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-src)) node.

#### KSDSOUND_BUFFER_CTRL_HRTF_3D

Indicates that the buffer uses a head-related transfer function (HRTF) for 3D control. If this bit is set, then the KSDSOUND_BUFFER_CTRL_3D bit must also be set.

#### KSDSOUND_BUFFER_CTRL_PAN

Indicates that the buffer has pan-control capability. If this bit is set, the pin representing the buffer implements a volume node ([KSNODETYPE_VOLUME](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-volume)) to control panning. For more information, see [DirectSound Node-Ordering Requirements](https://learn.microsoft.com/windows-hardware/drivers/audio/directsound-node-ordering-requirements).

#### KSDSOUND_BUFFER_CTRL_VOLUME

Indicates that the buffer has volume-control capability. If this bit is set, the pin representing the buffer implements a volume node ([KSNODETYPE_VOLUME](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-volume)) to control the stream's volume level.

#### KSDSOUND_BUFFER_CTRL_POSITIONNOTIFY

Indicates that the buffer has position-notification capability. If this bit is set, the pin representing the buffer supports the [KSPROPERTY_AUDIO_POSITION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-position) property.

### `WaveFormatEx`

Specifies the wave-data format of the buffer. This member is a structure of type [WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex).

## Remarks

The [KSDATAFORMAT_DSOUND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdataformat_dsound) structure contains a **BufferDesc** member that is a KSDSOUND_BUFFERDESC structure.

Note that the **WaveFormatEx** member of the KSDSOUND_BUFFERDESC structure can be extended to include additional format information (for example, a channel configuration mask). For details, see [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-waveformatextensible).

## See also

[KSDATAFORMAT_DSOUND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdataformat_dsound)

[KSNODETYPE_3D_EFFECTS](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-3d-effects)

[KSNODETYPE_SRC](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-src)

[KSNODETYPE_VOLUME](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-volume)

[KSPROPERTY_AUDIO_POSITION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-position)

[KSPROPSETID_Hrtf3d](https://learn.microsoft.com/windows-hardware/drivers/audio/kspropsetid-hrtf3d)

[WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex)

[WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-waveformatextensible)