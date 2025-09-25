## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_IHV_TASK_PRIORITY** enumeration defines IHV task priorities.

## Constants

### `WDI_IHV_TASK_PRIORITY_HIGH:1`

High priority.

### `WDI_IHV_TASK_PRIORITY_MEDIUM:2`

Medium priority.

### `WDI_IHV_TASK_PRIORITY_LOW:3`

Low priority.

## Remarks

The **WDI_IHV_TASK_PRIORITY** enum is a value in the [**WDI_TLV_ASSOCIATION_RESULT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-ihv-task-request-parameters) TLV.

## See also

[**WDI_TLV_ASSOCIATION_RESULT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/netcx/wdi-tlv-ihv-task-request-parameters)