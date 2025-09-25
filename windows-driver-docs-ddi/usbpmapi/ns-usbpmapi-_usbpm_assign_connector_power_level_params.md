# _USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS structure

## Description

Describes the parameters for the [**UsbPm_AssignConnectorPowerLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_assignconnectorpowerlevel) function. Initialize this structure by calling [**USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_assign_connector_power_level_params_init).

## Members

### `PowerRole`

The USB Type-C power role of the connector, defined in the [**USBC_POWER_ROLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbctypes/ne-usbctypes-_usbc_power_role) enumeration.

### `Format`

The power level format, defined in the [**USBPM_ASSIGN_POWER_LEVEL_PARAMS_FORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ne-usbpmapi-_usbpm_assign_power_level_params_format) enumeration.

### `Ucsi`

Description for the USCI inner structure.

### `Ucsi.MaximumPdPowerIn500mW`

Maximum power in 500mW unit for the connector to provide/consume.

### `Ucsi.MaximumTypeCCurrent`

Maximum current for the connector to provide/consume, defined in the [**USBC_UCSI_SET_POWER_LEVEL_C_CURRENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbctypes/ne-usbctypes-_usbc_ucsi_set_power_level_c_current) enumeration.

### `Rdo`

Description for the RDO inner structure.

### `Rdo.Rdo`

The PD Request Data Object that has sent to the port partner of this connector. See [**USBC_PD_REQUEST_DATA_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbctypes/ns-usbctypes-_usbc_pd_request_data_object).

## Remarks

## See also