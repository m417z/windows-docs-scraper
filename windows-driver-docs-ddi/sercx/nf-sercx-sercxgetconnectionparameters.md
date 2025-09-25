# SerCxGetConnectionParameters function

## Description

The **SerCxGetConnectionParameters** method retrieves the connection parameters for the associated peripheral device.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

### `ConnectionParameters` [out]

A pointer to a location into which the method writes a pointer to the connection parameters. The caller must cast this pointer to the appropriate pointer type, parse the data structure for the connection parameters, read the configuration settings from this structure, and apply these settings to the serial controller hardware.

## Remarks

The serial framework extension (SerCx) obtains the connection parameters for the peripheral device from the ACPI resource descriptors in the platform firmware.

For more information about the data format of the connection parameters, see [EvtSerCxApplyConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_apply_config).

## See also

[EvtSerCxApplyConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nc-sercx-evt_sercx_apply_config)