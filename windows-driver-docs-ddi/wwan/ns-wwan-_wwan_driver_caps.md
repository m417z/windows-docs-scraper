# _WWAN_DRIVER_CAPS structure

## Description

The WWAN_DRIVER_CAPS structure represents the capabilities of the miniport driver.

## Members

### `ulMajorVersion`

The major version of the MB driver model that the miniport driver supports. Miniport drivers
should set this member to WWAN_MAJOR_VERSION.

### `ulMinorVersion`

The minor version of the MB driver model that the miniport driver supports. Miniport drivers
should set this member to WWAN_MINOR_VERSION.

### `ulDriverCaps`

This member is reserved for future use. Miniport drivers should set this member to the value in
the following table.

#### WWAN_DRIVER_CAPS_NONE

The miniport driver has no special capabilities.

## See also

[NDIS_WWAN_DRIVER_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_driver_caps)