## Description

The **AUDIO_MODULE_ID** structure identifies a specific audio module by its class and instance identifiers. This structure is used to target operations to a particular audio module within the audio system.

## Members

### `ClassId`

A GUID that identifies the audio module class. This provides the type classification for the audio module.

### `InstanceId`

A ULONG value that represents the instance identifier for the audio module. This distinguishes between multiple instances of the same audio module class.

## Remarks

The **AUDIO_MODULE_ID** structure is used throughout the audio sensors interface to specify which audio module should be the target of various operations, such as starting or stopping sensor sessions and managing buffers.

The combination of **ClassId** and **InstanceId** must uniquely identify an audio module within the system.

## See also

- **[EVT_AUDIO_SENSORS_START_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_start_session)**
- **[EVT_AUDIO_SENSORS_STOP_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_stop_session)**
- **[EVT_AUDIO_SENSORS_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_buffer)**