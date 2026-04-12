## Description

The **EVT_AUDIO_SENSORS_STOP_SESSION** callback function is implemented by the audio driver and is called by the audio sensors driver to stop a previously started sensors session.

## Parameters

### `Context`

A pointer to the audio driver-supplied context that was provided when the interface was obtained.

### `ModuleId`

An **[AUDIO_MODULE_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-audio_module_id)** structure that identifies the target audio module for this operation.

### `SensorsSessionId`

The session identifier that was returned by the **[EVT_AUDIO_SENSORS_START_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_start_session)** callback when the session was started.

## Return value

Returns an NTSTATUS value. Return **STATUS_SUCCESS** if the operation succeeds. Otherwise, return an appropriate [NTSTATUS error code](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **EVT_AUDIO_SENSORS_STOP_SESSION** callback is called by the audio driver when it needs to terminate a sensor session that was previously started with **[EVT_AUDIO_SENSORS_START_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_start_session)**.

After this function returns successfully, the **SensorsSessionId** is no longer valid and should not be used in subsequent operations.

The audio driver should clean up any resources associated with the session and ensure that any active sensing operations are properly terminated.

## See also

- **[EVT_AUDIO_SENSORS_START_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_start_session)**
- **[EVT_AUDIO_SENSORS_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_buffer)**
- **[AUDIO_MODULE_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-audio_module_id)**
- **[AUDIO_SENSORS_INTERFACE_V0100](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-audio_sensors_interface_v0100)**