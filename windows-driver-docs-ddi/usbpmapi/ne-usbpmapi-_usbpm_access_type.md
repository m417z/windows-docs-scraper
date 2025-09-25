# _USBPM_ACCESS_TYPE enumeration

## Description

Defines the access types that the client driver can specify in [**USBPM_CLIENT_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ns-usbpmapi-_usbpm_client_config) when calling [**UsbPm_Register**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_register).

## Constants

### `UsbPmAccessQuery`

Access for calling **UsbPm_Retrieve*** functions.

### `UsbPmAccessAssignConnectorPowerLevel`

Access for calling [**UsbPm_AssignConnectorPowerLevelAsync**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_assignconnectorpowerlevel).

### `UsbPmAccessAll`

Access to all functions.

## Remarks

## See also