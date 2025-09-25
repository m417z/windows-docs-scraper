## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_P2P_ACTION_FRAME_TYPE** enumeration defines the Wi-Fi Direct action frame types.

## Constants

### `WDI_P2P_ACTION_FRAME_GO_NEGOTIATION_REQUEST:1`

Wi-Fi Direct Group Owner Negotiation Request.

### `WDI_P2P_ACTION_FRAME_GO_NEGOTIATION_RESPONSE:2`

Wi-Fi Direct Group Owner Negotiation Response.

### `WDI_P2P_ACTION_FRAME_GO_NEGOTIATION_CONFIRM:3`

Wi-Fi Direct Group Owner Negotiation Confirmation.

### `WDI_P2P_ACTION_FRAME_INVITATION_REQUEST:4`

Wi-Fi Direct Invitation Request.

### `WDI_P2P_ACTION_FRAME_INVITATION_RESPONSE:5`

Wi-Fi Direct Invitation Response.

### `WDI_P2P_ACTION_FRAME_PROVISION_DISCOVERY_REQUEST:6`

Wi-Fi Direct Provision Discovery Request.

### `WDI_P2P_ACTION_FRAME_PROVISION_DISCOVERY_RESPONSE:7`

Wi-Fi Direct Provision Discovery Response.

### `WDI_P2P_ACTION_FRAME_MAX_VALUE:0xFFFFFFFF`

The maximum value for this type.

## Remarks

The **WDI_P2P_ACTION_FRAME_TYPE** enum is a value in the [**WDI_TLV_P2P_SEND_ACTION_REQUEST_FRAME_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-send-action-request-frame-parameters) and [**WDI_TLV_P2P_ACTION_FRAME_RESPONSE_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-action-frame-response-parameters) TLVs.

## See also

[**WDI_TLV_P2P_SEND_ACTION_REQUEST_FRAME_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-send-action-request-frame-parameters)

[**WDI_TLV_P2P_ACTION_FRAME_RESPONSE_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-p2p-action-frame-response-parameters)