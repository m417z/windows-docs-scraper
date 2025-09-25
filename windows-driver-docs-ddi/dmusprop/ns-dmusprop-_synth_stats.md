# _SYNTH_STATS structure

## Description

The SYNTH_STATS structure specifies synthesizer performance statistics such as the number of voices playing, CPU usage, number of notes lost, amount of free memory, and peak volume level.

## Members

### `ValidStats`

Specifies which members of the SYNTH_STATS structure contain valid data. This member is a bitfield whose value is either zero or a bitwise OR of one or more of the following flag bits:

#### SYNTH_STATS_VOICES

The **Voices** field contains valid data.

#### SYNTH_STATS_TOTAL_CPU

The **TotalCPU** field contains valid data.

#### SYNTH_STATS_CPU_PER_VOICE

The **CPUPerVoice** field contains valid data.

#### SYNTH_STATS_LOST_NOTES

The **LostNotes** field contains valid data.

#### SYNTH_STATS_PEAK_VOLUME

The **PeakVolume** field contains valid data.

#### SYNTH_STATS_FREE_MEMORY

The **FreeMemory** field contains valid data.

### `Voices`

Specifies the average number of voices playing.

### `TotalCPU`

Specifies the total CPU usage (all voices), which is expressed as a percentage (a fraction multiplied by 100).

### `CPUPerVoice`

Specifies the CPU usage per voice, which is expressed as a percentage (a fraction multiplied by 100).

### `LostNotes`

Specifies the number of notes lost. Notes can be dropped if the number of simultaneous voices exceeds the maximum specified by the [KSPROPERTY_SYNTH_PORTPARAMETERS](https://learn.microsoft.com/previous-versions/ff537405(v=vs.85)) property. For additional information, see [Voice Allocation](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-allocation).

### `FreeMemory`

Specifies the amount of free memory in bytes. This is the storage that remains available for downloading additional DLS data resources.

### `PeakVolume`

Specifies the peak volume level expressed as decibels multiplied by 100.

## Remarks

The [KSPROPERTY_SYNTH_RUNNINGSTATS](https://learn.microsoft.com/previous-versions/ff537406(v=vs.85)) property uses the SYNTH_STATS structure to query a DirectMusic miniport driver for statistics about a synthesizer.

The SYNTH_STATS structure is similar to the DMUS_SYNTHSTATS structure, which is described in the Microsoft Windows SDK documentation.

## See also

[KSPROPERTY_SYNTH_PORTPARAMETERS](https://learn.microsoft.com/previous-versions/ff537405(v=vs.85))

[KSPROPERTY_SYNTH_RUNNINGSTATS](https://learn.microsoft.com/previous-versions/ff537406(v=vs.85))