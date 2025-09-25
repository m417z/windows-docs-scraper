## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is now in maintenance mode and will only receive high priority fixes.

The WDI_MESSAGE_HEADER structure defines the WiFi message header. All WiFi command messages must start with this header.

## Members

### `PortId`

Specifies the identifier for the Port object that this command is targeted for. For commands on the Adapter object, this is 0xFFFF.

### `Reserved`

This member is reserved.

### `Status`

Specifies the operation completion status for output messages. For input messages, this field is reserved.

### `TransactionId`

Specifies the transaction ID. This value is used to match host-sent messages with function responses. This value must be unique among all outstanding transactions. For notifications, the TransactionId must be set to 0 by the function.

### `IhvSpecificId`

Specifies an IHV-specific ID for this message. This can be used by IHVs for debugging purpose.

## See also

[Introduction to the Wi-Fi WDF class extension (WiFiCx)](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx)

[WiFiCx message structure](https://learn.microsoft.com/windows-hardware/drivers/netcx/wificx-message-structure)