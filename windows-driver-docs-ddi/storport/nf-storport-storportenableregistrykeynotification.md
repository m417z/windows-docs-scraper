## Description

A miniport calls **StorPortEnableRegistryKeyNotification** to enable registry change notifications for a device under the path HKLM\System\CurrentControlSet\Services\<*serviceName*>\Parameters\Device.

## Parameters

### `HwDeviceExtension`

[in] Pointer to the hardware device extension for the host bus adapter (HBA).

### `NotificationCallback`

[in] Pointer to the miniport's [**HW_REGISTRY_NOTIFICATION_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_registry_notification_routine) callback routine.

## Return value

**StorPortEnableRegistryKeyNotification** returns STOR_STATUS_SUCCESS if the node affinity was queried successfully. Possible error return values include the following.

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_INSUFFICIENT_RESOURCES | There was not enough memory to complete the operation. |
| STOR_STATUS_INVALID_PARAMETER | There is an invalid parameter, such as a null **NotificationCallback** pointer. |
| STOR_STATUS_UNSUCCESSFUL | An error occurred for internal reasons. |

## Remarks

 When a change occurs under the HKLM\System\CurrentControlSet\Services\<*serviceName*>\Parameters\Device registry key, Storport will call the miniport's [**HW_REGISTRY_NOTIFICATION_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_registry_notification_routine) callback routine with the device extension.

## See also

[**HW_REGISTRY_NOTIFICATION_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_registry_notification_routine)