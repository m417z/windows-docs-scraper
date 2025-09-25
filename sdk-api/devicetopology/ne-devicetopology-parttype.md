# PartType enumeration

## Description

The **PartType** enumeration defines constants that indicate whether a part in a device topology is a connector or subunit.

## Constants

### `Connector:0`

The part is a connector. A connector can represent an audio jack, an internal connection to an integrated endpoint device, or a software connection implemented through DMA transfers. For more information about connector types, see [ConnectorType Enumeration](https://learn.microsoft.com/windows/win32/api/devicetopology/ne-devicetopology-connectortype).

### `Subunit`

The part is a subunit. A subunit is an audio-processing node in a device topology. A subunit frequently has one or more hardware control parameters that can be set under program control. For example, an audio application can change the volume setting of a volume-control subunit.

## Remarks

The [IPart::GetPartType](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-ipart-getparttype) method uses the constants defined in the **PartType** enumeration to indicate whether an [IPart](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart) object represents a connector or a subunit. If an **IPart** object represents a connector, a client can query that object for its [IConnector](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iconnector) interface. If an **IPart** object represents a subunit, a client can query that object for its [ISubunit](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-isubunit) interface.

For more information about connectors and subunits, see [Device Topologies](https://learn.microsoft.com/windows/desktop/CoreAudio/device-topologies).

## See also

[Core Audio Constants](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-constants)

[Core Audio Enumerations](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-enumerations)

[IConnector Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iconnector)

[IPart Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipart)

[ISubunit Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-isubunit)