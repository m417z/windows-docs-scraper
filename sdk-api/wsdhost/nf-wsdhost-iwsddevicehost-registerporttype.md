# IWSDDeviceHost::RegisterPortType

## Description

Registers a port type for incoming messages. All port types listed in the service host metadata must be registered.

## Parameters

### `pPortType` [in]

Reference to a [WSD_PORT_TYPE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_port_type) structure that describes the port type.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **S_FALSE** | The port type specified by *pPortType* has already been registered. |

## See also

[IWSDDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehost)