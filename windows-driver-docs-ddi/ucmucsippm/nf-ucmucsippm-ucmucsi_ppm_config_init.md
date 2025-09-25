# UCMUCSI_PPM_CONFIG_INIT function

## Description

Initializes a [**UCMUCSI_PPM_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/ns-ucmucsippm-_ucmucsi_ppm_config) structure.

## Parameters

### `Config`

A pointer to a [**UCMUCSI_PPM_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/ns-ucmucsippm-_ucmucsi_ppm_config) structure to initialize.

### `CollectionObject`

The handle to the connector collection object that the client driver retrieved in a previous call to [**UcmUcsiConnectorCollectionCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsiconnectorcollectioncreate).

## Remarks

## See also

[**UcmUcsiPpmCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsippmcreate)
[**UcmUcsiConnectorCollectionCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsiconnectorcollectioncreate)