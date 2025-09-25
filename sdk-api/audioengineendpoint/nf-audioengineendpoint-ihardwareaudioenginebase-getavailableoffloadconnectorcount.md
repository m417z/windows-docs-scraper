# IHardwareAudioEngineBase::GetAvailableOffloadConnectorCount

## Description

The **GetAvailableOffloadConnectorCount** method retrieves the number of available endpoints that can handle offloaded streams on the hardware audio engine.

## Parameters

### `_pwstrDeviceId` [in]

A pointer to the device ID of the hardware audio engine device.

### `_uConnectorId` [in]

The identifier for the endpoint connector.

### `_pAvailableConnectorInstanceCount` [out]

A pointer to the number of available endpoint connectors that can handle offloaded audio streams.

## Return value

The **GetAvailableOffloadConnectorCount** method returns **S_OK** to indicate that it has completed successfully. Otherwise it returns an appropriate error code.

## See also

[IHardwareAudioEngineBase](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-ihardwareaudioenginebase)