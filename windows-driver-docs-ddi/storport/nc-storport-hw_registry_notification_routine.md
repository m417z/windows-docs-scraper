## Description

Storport calls a miniport's **HW_REGISTRY_NOTIFICATION_ROUTINE** callback when a change occurs under the HKLM\System\CurrentControlSet\Services\<*serviceName*>\Parameters\Device registry key.

## Parameters

### `HwDeviceExtension`

[in] Pointer to the hardware device extension for the host bus adapter (HBA). The miniport provided this value to Storport in a prior call to [**StorPortEnableRegistryKeyNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportenableregistrykeynotification).

## Remarks

If a miniport has [enabled registry change notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportenableregistrykeynotification), Storport will call the miniport's **HW_REGISTRY_NOTIFICATION_ROUTINE** callback routine with the device extension when a change occurs under the HKLM\System\CurrentControlSet\Services\<*serviceName*>\Parameters\Device registry key.

**HW_REGISTRY_NOTIFICATION_ROUTINE** should call [**StorPortRegistryRead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportregistryread) for each value name, setting the **Global** parameter as 1.

## See also

[**StorPortEnableRegistryKeyNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportenableregistrykeynotification)

[**StorPortRegistryRead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportregistryread)