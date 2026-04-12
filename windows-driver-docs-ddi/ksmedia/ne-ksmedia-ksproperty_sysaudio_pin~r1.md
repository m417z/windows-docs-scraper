# KSPROPERTY_SYSAUDIO_PIN enumeration

## Description

The **KSPROPERTY_SYSAUDIO_PIN** enumeration defines the properties supported for SysAudio pin operations and configuration.

## Constants

### `KSPROPERTY_SYSAUDIO_TOPOLOGY_CONNECTION_INDEX`

Retrieves the topology connection index for a SysAudio pin. This property provides information about how pins are connected within the audio topology.

### `KSPROPERTY_SYSAUDIO_ATTACH_VIRTUAL_SOURCE`

Attaches a virtual source to a SysAudio pin. This property enables the connection of virtual audio sources to specific pins for audio processing.

### `KSPROPERTY_SYSAUDIO_PIN_VOLUME_NODE`

Retrieves or sets volume node information for a SysAudio pin. This property allows volume control at the pin level within the SysAudio filter graph.

## Remarks

The **KSPROPSETID_SysAudio_Pin** property set uses these enumeration values to identify specific properties related to SysAudio pin management and control. These properties provide fine-grained control over individual pins within the SysAudio filter graph.

SysAudio pins represent connection points in the audio filter graph where audio data flows between different components. The properties defined in this enumeration allow applications to manage topology connections, attach virtual sources, and control volume settings at the pin level.

## See also

- [KSPROPERTY_SYSAUDIO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ksproperty_sysaudio-r1)