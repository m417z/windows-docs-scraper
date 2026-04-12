## Description

The **SDCA_ENDPOINT_CONFIG** structure defines the configuration for SDCA (Smart Device Class Audio) endpoints. This structure contains an array of SDCA function information that describes the functions that need to be configured for the endpoint.

## Members

### `Size`

The size, in bytes, of the entire structure including the size of the **SdcaFunctionInformation** array.

### `Version`

The version of this structure. Must be set to **SDCA_ENDPOINT_CONFIG_VERSION_1** (1).

### `SdcaFunctionInformationCount`

The number of SDCA functions in the **SdcaFunctionInformation** array.

### `SdcaFunctionInformation[ANYSIZE_ARRAY]`

An array of **[SDCA_FUNCTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-sdca_function_information)** structures that provide details about the SDCA functions that need to be configured for this endpoint.

## Remarks

The **SDCA_ENDPOINT_CONFIG** structure is a variable-length structure that follows an **[AUDIO_ENDPOINT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-audio_endpoint_config)** structure when the **AudioInterfaceType** is **AUDIO_INTERFACE_SDCA**.

SDCA (Smart Device Class Audio) is a specification for audio devices that operate over SoundWire interfaces. This structure allows configuration of multiple SDCA functions that collectively implement an audio endpoint for sensor operations.

## See also

- **[SDCA_FUNCTION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-sdca_function_information)**
- **[AUDIO_ENDPOINT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-audio_endpoint_config)**
- **[EVT_AUDIO_SENSORS_START_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/nc-audiosensors-evt_audio_sensors_start_session)**