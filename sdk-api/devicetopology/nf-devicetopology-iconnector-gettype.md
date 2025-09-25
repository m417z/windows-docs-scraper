# IConnector::GetType

## Description

The **GetType** method gets the type of this connector.

## Parameters

### `pType` [out]

Pointer to a variable into which the method writes the connector type. The connector type is one of the following [ConnectorType](https://learn.microsoft.com/windows/win32/api/devicetopology/ne-devicetopology-connectortype) enumeration constants:

Unknown_Connector

Physical_Internal

Physical_External

Software_IO

Software_Fixed

Network

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pType* is **NULL**. |

## Remarks

A connector corresponds to a "pin" in kernel streaming (KS) terminology. The mapping of KS pins to connectors is as follows:

* If the KS pin communication type is KSPIN_COMMUNICATION_SINK, KSPIN_COMMUNICATION_SOURCE, or KSPIN_COMMUNICATION_BOTH, then the connector type is Software_IO.
* Else, if the pin is part of a physical connection between two KS filters (devices) in the same audio adapter or in different audio adapters, then the connector type is Software_Fixed.
* Else, if the KS pin category is KSNODETYPE_SPEAKER, KSNODETYPE_MICROPHONE, KSNODETYPE_LINE_CONNECTOR, or KSNODETYPE_SPDIF_INTERFACE, the connector type is Physical_External.
* Else, for a pin that does not meet any of the preceding criteria, the connector type is Physical_Internal.

For more information about KS pins, see the Windows DDK documentation.

For a code example that calls the **GetType** method, see the implementation of the SelectCaptureDevice function in [Device Topologies](https://learn.microsoft.com/windows/desktop/CoreAudio/device-topologies).

## See also

[IConnector Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iconnector)