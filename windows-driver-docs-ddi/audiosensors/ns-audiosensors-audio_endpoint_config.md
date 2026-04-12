## Description

The **AUDIO_ENDPOINT_CONFIG** structure defines the configuration for an audio endpoint used in audio sensor sessions. This structure provides information about the audio interface type and allows for additional technology-specific configuration data.

## Members

### `Size`

The size, in bytes, of the entire structure including any additional audio technology-specific endpoint configuration bytes that follow this structure.

### `Version`

The version of this structure. Must be set to **AUDIO_ENDPOINT_CONFIG_VERSION_1** (1).

### `AudioInterfaceType`

A GUID that identifies the audio interface type. For SDCA interfaces, use **AUDIO_INTERFACE_SDCA**. This GUID determines the format of any additional configuration data that follows this structure.

## Remarks

The **AUDIO_ENDPOINT_CONFIG** structure is a variable-length structure. Additional bytes following this structure provide audio interface-specific endpoint configuration. When **AudioInterfaceType** is **AUDIO_INTERFACE_SDCA**, the bytes following this structure will contain a **[SDCA_ENDPOINT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-sdca_endpoint_config)** structure.

This structure is used when starting audio sensor sessions to specify the configuration for render and capture endpoints.

## See also

- **[SDCA_ENDPOINT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-sdca_endpoint_config)**
- **[EVT_AUDIO_SENSORS_START_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_start_session)**