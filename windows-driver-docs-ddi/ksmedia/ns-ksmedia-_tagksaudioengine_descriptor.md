# _tagKSAUDIOENGINE_DESCRIPTOR structure

## Description

The **KSAUDIOENGINE_DESCRIPTOR** structure describes the static, external properties of the audio engine.

## Members

### `nHostPinId`

Specifies the ID of the pin factory that is connected to the audio engine node that handles host-processed audio data. This is the pin factory on which a software audio engine will run.

### `nOffloadPinId`

Specifies the ID of the pin factory that is connected to the audio engine node that handles offloaded streams.

### `nLoopbackPinId`

Specifies the ID of the pin factory that is connected to the audio engine node that supplies a post-mix loopback or reference stream.

## See also

[GetAudioEngineDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportaudioenginenode-getaudioenginedescriptor)

[KSPROPERTY_AUDIOENGINE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audioengine-descriptor)