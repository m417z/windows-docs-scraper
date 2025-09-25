# DEV_BROADCAST_OEM structure

## Description

Contains information about a OEM-defined device type.

## Members

### `dbco_size`

The size of this structure, in bytes.

### `dbco_devicetype`

Set to **DBT_DEVTYP_OEM**.

### `dbco_reserved`

Reserved; do not use.

### `dbco_identifier`

The OEM-specific identifier for the device.

### `dbco_suppfunc`

The OEM-specific function value. Possible values depend on the device.

## See also

[DEV_BROADCAST_HDR](https://learn.microsoft.com/windows/desktop/api/dbt/ns-dbt-dev_broadcast_hdr)

[WM_DEVICECHANGE](https://learn.microsoft.com/windows/desktop/DevIO/wm-devicechange)