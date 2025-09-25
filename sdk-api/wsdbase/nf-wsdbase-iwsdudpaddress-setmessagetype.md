# IWSDUdpAddress::SetMessageType

## Description

Sets the message type for this UDP address configuration. There are two types of messages: one-way messages, which do not require responses, and two-way messages, which do require responses.

## Parameters

### `messageType` [in]

A [WSDUdpMessageType](https://learn.microsoft.com/windows/desktop/api/wsdbase/ne-wsdbase-wsdudpmessagetype) value that specifies the message type used for this address configuration.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |

## See also

[IWSDUdpAddress](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdudpaddress)