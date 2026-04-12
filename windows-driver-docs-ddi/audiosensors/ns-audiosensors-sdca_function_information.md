## Description

The **SDCA_FUNCTION_INFORMATION** structure provides detailed information about an SDCA (Smart Device Class Audio) function, including its location within the SoundWire topology and its functional characteristics.

## Members

### `Size`

The size, in bytes, of the entire structure.

### `Version`

The version of this structure. Must be set to **SDCA_FUNCTION_INFORMATION_VERSION_1** (1).

### `FunctionNumber`

The SDCA function number that identifies this specific function within the device.

### `FunctionType`

The SDCA function type that describes the category of functionality provided by this function.

### `FunctionManufacturerId`

The SDCA function manufacturer identifier, which identifies the vendor that created this function.

### `FunctionId`

The SDCA function identifier that uniquely identifies this function implementation from the manufacturer.

### `ControllerId`

The SoundWire controller identifier that this function is attached to.

### `LinkId`

The link identifier within the SoundWire controller that this function is attached to.

### `UniqueId`

The peripheral device's unique identifier within the SoundWire topology.

## Remarks

The **SDCA_FUNCTION_INFORMATION** structure is used within **[SDCA_ENDPOINT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-sdca_endpoint_config)** to describe the SDCA functions that need to be configured for audio sensor operations.

SDCA (Smart Device Class Audio) is a specification that defines how audio devices connect and operate over SoundWire interfaces. This structure provides the necessary addressing information to identify and configure specific SDCA functions within the SoundWire topology.

## See also

- **[SDCA_ENDPOINT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-sdca_endpoint_config)**
- **[AUDIO_ENDPOINT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/audiosensors/ns-audiosensors-audio_endpoint_config)**