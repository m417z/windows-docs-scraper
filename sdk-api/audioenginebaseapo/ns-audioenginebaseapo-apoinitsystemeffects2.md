# APOInitSystemEffects2 structure

## Description

The APOInitSystemEffects2 structure was introduced with Windows 8.1, to make it possible to provide additional initialization context to the audio processing object (APO) for
initialization.

## Members

### `APOInit`

An [APOInitBaseStruct](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/ns-audioenginebaseapo-apoinitbasestruct) structure.

### `pAPOEndpointProperties`

A pointer to an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) object.

### `pAPOSystemEffectsProperties`

A pointer to an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) object.

### `pReserved`

Reserved for future use.

### `pDeviceCollection`

A pointer to an IMMDeviceCollection object. The last item in the *pDeviceCollection* is always the [IMMDevice](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nn-mmdeviceapi-immdevice) representing the audio endpoint.

### `nSoftwareIoDeviceInCollection`

Specifies the MMDevice that implements the DeviceTopology that includes the software connector for which the APO is initializing. The MMDevice is contained in *pDeviceCollection*.

### `nSoftwareIoConnectorIndex`

Specifies the index of a Software_IO connector in the DeviceTopology.

### `AudioProcessingMode`

Specifies the processing mode for the audio graph.

### `InitializeForDiscoveryOnly`

Indicates whether the audio system is initializing the APO for effects discovery only.

## See also

[APOInitSystemEffects](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/ns-audioenginebaseapo-apoinitsystemeffects)