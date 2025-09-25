# ConnectorType enumeration

## Description

The **ConnectorType** enumeration indicates the type of connection that a connector is part of.

## Constants

### `Unknown_Connector:0`

The connector is part of a connection of unknown type.

### `Physical_Internal`

The connector is part of a physical connection to an auxiliary device that is installed inside the system chassis (for example, a connection to the analog output of an internal CD player, or to a built-in microphone or built-in speakers in a laptop computer).

### `Physical_External`

The connector is part of a physical connection to an external device. That is, the connector is a user-accessible jack that connects to a microphone, speakers, headphones, S/PDIF input or output device, or line input or output device.

### `Software_IO`

The connector is part of a software-configured I/O connection (typically a DMA channel) between system memory and an audio hardware device on an audio adapter.

### `Software_Fixed`

The connector is part of a permanent connection that is fixed and cannot be configured under software control. This type of connection is typically used to connect two audio hardware devices that reside on the same adapter.

### `Network`

The connector is part of a connection to a network.

## Remarks

The [IConnector::GetType](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iconnector-gettype) method uses the constants defined in the **ConnectorType** enumeration.

For more information about connector types, see [Device Topologies](https://learn.microsoft.com/windows/desktop/CoreAudio/device-topologies).

## See also

[Core Audio Constants](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-constants)

[Core Audio Enumerations](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-enumerations)

[IConnector::GetType](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iconnector-gettype)