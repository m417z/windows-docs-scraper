# GNSS_DRIVER_REQUEST_DATA structure

## Description

This structure contains driver data request information.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `Request`

The type of request made by the driver.

Represented by the [GNSS_DRIVER_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ne-gnssdriver-gnss_driver_request) enumeration.

### `RequestFlag`

Additional flags along with this information.

## Remarks

Based on certain rules, the HLOS will provide data to the GNSS driver. However, during specific times, if the GNSS driver determines that it needs data it can request it without waiting for the HLOS to send it in its normal operation.