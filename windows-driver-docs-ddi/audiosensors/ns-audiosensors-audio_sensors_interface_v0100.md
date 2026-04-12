## Description

The **AUDIO_SENSORS_INTERFACE_V0100** structure defines version 1.0 of the audio sensors interface. This interface enables communication between audio drivers and sensors drivers for presence sensing scenarios using ultrasound audio.

## Members

### `InterfaceHeader`

An **[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)** structure that contains standard interface information including size, version, and reference counting functions.

### `EvtAudioSensorsStartSession`

A pointer to the **[EVT_AUDIO_SENSORS_START_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_start_session)** callback function that starts an audio sensors session.

### `EvtAudioSensorsStopSession`

A pointer to the **[EVT_AUDIO_SENSORS_STOP_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_stop_session)** callback function that stops an audio sensors session.

### `EvtAudioSensorsGetBuffer`

A pointer to the **[EVT_AUDIO_SENSORS_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_buffer)** callback function that retrieves buffer data from the audio sensors driver.

### `EvtAudioSensorsSetBuffer`

A pointer to the **[EVT_AUDIO_SENSORS_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_buffer)** callback function that sets buffer data in the audio sensors driver.

### `EvtAudioSensorsSubmitReadReport`

A pointer to the **[EVT_AUDIO_SENSORS_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_buffer)** callback function used by the audio driver to submit read reports to the sensors driver.

## Remarks

This structure defines the complete audio sensors interface version 1.0. The interface is divided into two categories:

**Audio Sensors Driver to Audio Driver** - Functions that the audio driver calls:
- **EvtAudioSensorsStartSession** - Starts a sensor session
- **EvtAudioSensorsStopSession** - Stops a sensor session
- **EvtAudioSensorsGetBuffer** - Gets buffer data from sensors driver
- **EvtAudioSensorsSetBuffer** - Sets buffer data in sensors driver

**Audio Driver to Audio Sensors Driver** - Functions that the sensors driver calls:
- **EvtAudioSensorsSubmitReadReport** - Submits read reports to sensors driver

The interface version is **AUDIO_SENSORS_INTERFACE_VERSION_0100** (0x0100).

## See also

- **[EVT_AUDIO_SENSORS_START_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_start_session)**
- **[EVT_AUDIO_SENSORS_STOP_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_stop_session)**
- **[EVT_AUDIO_SENSORS_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_buffer)**
- **[AUDIO_MODULE_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-audio_module_id)**