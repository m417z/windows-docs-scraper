# _USBPM_CONNECTOR_PROPERTIES structure

## Description

Describes the properties of a connector. This structure is used in the [**UsbPm_RetrieveConnectorProperties**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_retrieveconnectorproperties) call.

## Members

### `ConnectorHandle`

A handle of this connector.

### `ParentHubHandle`

The handle of the parent hub to which this connector belongs.

### `ConnectorId`

A system-assigned identifier.

### `SupportedTypeCOperatingModes`

A bitwise OR of the values defined in the [**USBC_TYPEC_OPERATING_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbctypes/ne-usbctypes-_usbc_typec_operating_mode) enumeration.

### `SupportedTypeCSourceCurrentAdvertisements`

A bitwise OR of the values defined in the [**USBC_CURRENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbctypes/ne-usbctypes-_usbc_current) enumeration.

### `IsTypeCAudioAccessorySupported`

Indicates whether audio accessories are supported by this connector.

### `IsPdSupported`

Indicates whether PD is supported on this connector.

### `SupportedPowerRoles`

A bitwise OR of the values defined in the [**USBC_POWER_ROLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbctypes/ne-usbctypes-_usbc_power_role) enumeration.

## Remarks

## See also