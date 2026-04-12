## Description

The **EVT_AUDIO_SENSORS_BUFFER** callback function is used for buffer operations between audio drivers and audio sensors drivers. This callback has multiple uses including getting buffers, setting buffers, and submitting read reports.

## Parameters

### `Context`

A pointer to the audio sensors driver-supplied context.

### `ModuleId`

An **[AUDIO_MODULE_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-audio_module_id)** structure that identifies the target audio module.

### `SensorsSessionId`

The session identifier returned by the **[EVT_AUDIO_SENSORS_START_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_start_session)** callback. A value of 0 indicates a request that is not associated with any specific audio sensors session.

### `BufferSize`

A pointer to a ULONG that contains the size of the buffer in bytes. On input, this specifies the size of the buffer provided. On output, this may be updated to indicate the actual buffer size used or required.

### `Buffer`

An optional pointer to a proprietary buffer used for data exchange. The buffer size is specified by the **BufferSize** parameter.

## Return value

Returns an NTSTATUS value. Return **STATUS_SUCCESS** if the operation succeeds. Otherwise, return an appropriate [NTSTATUS error code](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **EVT_AUDIO_SENSORS_BUFFER** callback function type is used for three different buffer operations in the audio sensors interface:

- **EvtAudioSensorsGetBuffer** - Used to retrieve buffer data from the audio sensors driver
- **EvtAudioSensorsSetBuffer** - Used to set buffer data in the audio sensors driver
- **EvtAudioSensorsSubmitReadReport** - Used by the audio driver to submit read reports to the sensors driver

The specific operation depends on which function pointer in the **[AUDIO_SENSORS_INTERFACE_V0100](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-audio_sensors_interface_v0100)** structure is being used.

The **SensorsSessionId** parameter links operations to a specific sensor session created by **EVT_AUDIO_SENSORS_START_SESSION**. When the value is 0, the operation is not associated with any specific session.

## See also

- **[AUDIO_SENSORS_INTERFACE_V0100](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-audio_sensors_interface_v0100)**
- **[AUDIO_MODULE_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-audio_module_id)**
- **[EVT_AUDIO_SENSORS_START_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_start_session)**
- **[EVT_AUDIO_SENSORS_STOP_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_stop_session)**