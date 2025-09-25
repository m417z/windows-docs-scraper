# _UCMUCSI_PPM_CONFIG structure

## Description

Stores configuration information required to create a Platform Policy Manager (PPM). Initialize this structure by calling [**UCMUCSI_PPM_CONFIG_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsi_ppm_config_init). This structure is used in the [**UcmUcsiPpmCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsippmcreate) call.

## Members

### `Size`

### `UsbDeviceControllerEnabled`

A boolean value that indicates whether or not to enable the device controller.

### `ConnectorCollectionHandle`

The **ConnectorCollectionHandle** member must be set to the handle retrieved in a previous call to [**UcmUcsiConnectorCollectionCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsiconnectorcollectioncreate).

## Remarks

## See also

[**UcmUcsiPpmCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsippmcreate)
[**UcmUcsiConnectorCollectionCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsiconnectorcollectioncreate)