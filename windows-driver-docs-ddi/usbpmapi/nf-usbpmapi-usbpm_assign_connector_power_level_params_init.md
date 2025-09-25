# USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS_INIT function

## Description

Initializes a **[USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ns-usbpmapi-_usbpm_assign_connector_power_level_params)** structure. The client driver must call this function before calling [**UsbPm_AssignConnectorPowerLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_assignconnectorpowerlevel).

## Parameters

### `Params` [Out]

A pointer to a **USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS** structure to initialize.

### `PowerRole` [In]

The USB Type-C power role of the connector to set. The values are defined in the [**USBC_POWER_ROLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbctypes/ne-usbctypes-_usbc_power_role) enumeration.

### `Format` [In]

The USB Type-C format, defined in [**USBPM_ASSIGN_POWER_LEVEL_PARAMS_FORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ne-usbpmapi-_usbpm_assign_power_level_params_format)

## Remarks

## See also