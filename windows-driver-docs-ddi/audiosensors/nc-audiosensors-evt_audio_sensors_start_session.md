## Description

The **EVT_AUDIO_SENSORS_START_SESSION** callback function is implemented by the audio driver and is called by the audio sensors driver to start a new sensors session. This function configures audio endpoints for use in presence sensing scenarios.

## Parameters

### `Context`

A pointer to the audio driver-supplied context that was provided when the interface was obtained.

### `ModuleId`

An **[AUDIO_MODULE_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-audio_module_id)** structure that identifies the target audio module for this session.

### `AudioRenderEndpointConfig`

An optional pointer to an **[AUDIO_ENDPOINT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-audio_endpoint_config)** structure that contains the audio render endpoint configuration details to be used for this session. This parameter can be NULL if no render endpoint configuration is needed.

### `AudioCaptureEndpointConfig`

An optional pointer to an **[AUDIO_ENDPOINT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-audio_endpoint_config)** structure that contains the audio capture endpoint configuration details to be used for this session. This parameter can be NULL if no capture endpoint configuration is needed.

### `SensorsSessionId`

A pointer to a ULONG that receives a non-zero session identifier returned by the audio driver. This identifier is used in subsequent calls to identify this specific session.

## Return value

Returns an NTSTATUS value. Return **STATUS_SUCCESS** if the operation succeeds. Otherwise, return an appropriate [NTSTATUS error code](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **EVT_AUDIO_SENSORS_START_SESSION** callback is called by the audio driver when it needs to start a sensor session for presence sensing operations. The session associates audio endpoints with sensor functionality, typically for ultrasound-based presence detection.

The **SensorsSessionId** returned by this function must be a non-zero value that uniquely identifies the session. This identifier is used in subsequent calls to **[EVT_AUDIO_SENSORS_STOP_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_stop_session)** and **[EVT_AUDIO_SENSORS_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_buffer)** functions.

Both **AudioRenderEndpointConfig** and **AudioCaptureEndpointConfig** are optional, allowing flexibility in configuring sessions that may only need one direction of audio flow.

## See also

- **[EVT_AUDIO_SENSORS_STOP_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_stop_session)**
- **[EVT_AUDIO_SENSORS_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_buffer)**
- **[AUDIO_ENDPOINT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-audio_endpoint_config)**
- **[AUDIO_MODULE_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-audio_module_id)**
- **[AUDIO_SENSORS_INTERFACE_V0100](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-audio_sensors_interface_v0100)**