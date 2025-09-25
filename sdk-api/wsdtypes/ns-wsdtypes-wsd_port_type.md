# WSD_PORT_TYPE structure

## Description

Supplies data about a port type. This structure is populated by [generated code](https://learn.microsoft.com/windows/desktop/WsdApi/web-services-for-devices-code-generator).

## Members

### `EncodedName`

The encoded qualified name of the port type.

### `OperationCount`

The number of operations in the array referenced by the **Operations** member.

### `Operations`

Reference to an array of [WSD_OPERATION](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_operation) structures that specifies the operations comprising the port type.

### `ProtocolType`

A [WSD_PROTOCOL_TYPE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ne-wsdtypes-wsd_protocol_type) value that specifies the protocol(s) supported by the port type.