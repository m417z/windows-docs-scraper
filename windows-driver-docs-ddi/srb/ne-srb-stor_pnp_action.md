## Description

Enumerates Plug and Play minor function codes.

## Constants

### `StorStartDevice`

Sends a request to start the device.

### `StorRemoveDevice`

Sends a request to remove the device.

### `StorStopDevice`

Indicates that the device is stopping.

### `StorQueryCapabilities`

Sends a request to query the capabilities of the device.

### `StorQueryResourceRequirements`

Sends a request to query the resource requirements of the device.

### `StorFilterResourceRequirements`

Sends a request to filter the resource requirements of the device.

### `StorSurpriseRemoval`

Indicates that the device has been removed.

## Remarks

These values are passed in through the PnPAction field of a **[SRBEX_DATA_PNP](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_pnp)** structure.

## See also

- **[SRBEX_DATA_PNP](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_srbex_data_pnp)**