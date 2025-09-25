# USBPM_CLIENT_CONFIG_EXTRA_INFO_INIT function

## Description

Initializes a [**USBPM_CLIENT_CONFIG_EXTRA_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ns-usbpmapi-_usbpm_client_config_extra_info) structure.

## Parameters

### `ExtraInfo` [Out]

A pointer to a [**USBPM_CLIENT_CONFIG_EXTRA_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ns-usbpmapi-_usbpm_client_config_extra_info) structure to initialize.

### `WdmDeviceObject` [In]

If the client is a kernel mode driver, it should set it to the kernel mode WDM device object after calling [**USBPM_CLIENT_CONFIG_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_client_config_init). In user mode, it is not used.

## Remarks

## See also