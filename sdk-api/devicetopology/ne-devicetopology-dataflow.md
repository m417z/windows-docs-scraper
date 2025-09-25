# DataFlow enumeration

## Description

The **DataFlow** enumeration indicates the data-flow direction of an audio stream through a connector.

## Constants

### `In:0`

Input stream. The audio stream flows into the device through the connector.

### `Out`

Output stream. The audio stream flows out of the device through the connector.

## Remarks

The [IConnector::GetDataFlow](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iconnector-getdataflow) method uses the constants defined in the **DataFlow** enumeration.

The topology of a rendering or capture device on an audio adapter typically has one or more connectors with a data-flow direction of "In" through which audio data enters the device, and one or more connectors with a data-flow direction of "Out" through which audio data exits the device. For example, a typical rendering device on an adapter has a connector with data-flow direction "In" through which the Windows audio engine streams PCM data into the device. The same device has a connector with data-flow direction "Out" through which the device transmits an audio signal to speakers or headphones.

The topology of a rendering endpoint device (for example, headphones) has a single connector with data-flow direction "In" through which audio data (in the form of an analog signal) enters the device.

The topology of a capture endpoint device (for example, a microphone) has a single connector with data-flow direction "Out" through which audio data exits the device.

For more information, see [Device Topologies](https://learn.microsoft.com/windows/desktop/CoreAudio/device-topologies).

## See also

[Core Audio Constants](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-constants)

[Core Audio Enumerations](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-enumerations)

[IConnector::GetDataFlow](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iconnector-getdataflow)