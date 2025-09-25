## Description

Provides audio processing object (APO) initialization parameters, extending [APOInitSystemEffects2](https://learn.microsoft.com/windows/win32/api/audioenginebaseapo/ns-audioenginebaseapo-apoinitsystemeffects2) to add the ability to specify a service provider for logging.

## Members

### `APOInit`

An [APOInitBaseStruct](https://learn.microsoft.com/windows/win32/api/audioenginebaseapo/ns-audioenginebaseapo-apoinitbasestruct) structure.

### `pAPOEndpointProperties`

A pointer to an [IPropertyStore](https://learn.microsoft.com/windows/win32/api/propsys/nn-propsys-ipropertystore) object.

### `pServiceProvider`

An [IServiceProvider](https://learn.microsoft.com/windows/win32/api/servprov/nn-servprov-iserviceprovider) interface.

### `pDeviceCollection`

A pointer to an [IMMDeviceCollection](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nn-mmdeviceapi-immdevicecollection) object. The last item in the *pDeviceCollection* is always the [IMMDevice](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nn-mmdeviceapi-immdevice) representing the audio endpoint.

### `nSoftwareIoDeviceInCollection`

Specifies the **MMDevice** that implements the DeviceTopology that includes the software connector for which the APO is initializing. The **MMDevice** is contained in *pDeviceCollection*.

### `nSoftwareIoConnectorIndex`

Specifies the index of a **Software_IO** connector in the [DeviceTopology](https://learn.microsoft.com/windows/win32/api/devicetopology/nn-devicetopology-idevicetopology).

### `AudioProcessingMode`

Specifies the processing mode for the audio graph.

### `InitializeForDiscoveryOnly`

Indicates whether the audio system is initializing the APO for effects discovery only.

## Remarks

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also

[APOInitSystemEffects](https://learn.microsoft.com/windows/win32/api/audioenginebaseapo/ns-audioenginebaseapo-apoinitsystemeffects)
[APOInitSystemEffects2](https://learn.microsoft.com/windows/win32/api/audioenginebaseapo/ns-audioenginebaseapo-apoinitsystemeffects2)