## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The WDI_CAN_SUSTAIN_AP_REASON enumeration defines the reasons the port is ready to receive a [OID_WDI_TASK_START_AP](https://learn.microsoft.com/windows-hardware/drivers/netcx/oid-wdi-task-start-ap) request.

## Constants

### `WDI_CAN_SUSTAIN_AP_REASON_IHV_START:0xFF000000`

The start value of possible IHV-specified reasons.

### `WDI_CAN_SUSTAIN_AP_REASON_IHV_END:0xFFFFFFFF`

The end value of possible IHV-specified reasons.

## Remarks

The **WDI_CAN_SUSTAIN_AP_REASON** enumeration is a value in the [**WDI\_TLV\_INDICATION\_CAN\_SUSTAIN\_AP**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-indication-can-sustain-ap) TLV.

## See also

[OID_WDI_TASK_START_AP](https://learn.microsoft.com/windows-hardware/drivers/netcx/oid-wdi-task-start-ap)

[**WDI\_TLV\_INDICATION\_CAN\_SUSTAIN\_AP**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-indication-can-sustain-ap)