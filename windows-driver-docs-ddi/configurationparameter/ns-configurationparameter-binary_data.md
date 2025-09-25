# BINARY_DATA structure

## Description

The BINARY_DATA structure contains the binary data of a named entry in the registry.

## Members

### `Length`

The length, in bytes, of the data that the
**Buffer** member points to.

### `Buffer`

Pointer to a buffer containing the binary data.

## Remarks

The BINARY_DATA structure is used in the
**ParameterData** member of the
[NDIS_CONFIGURATION_PARAMETER](https://learn.microsoft.com/windows-hardware/drivers/ddi/configurationparameter/ns-configurationparameter-_ndis_configuration_parameter) structure.

## See also

[NDIS_CONFIGURATION_PARAMETER](https://learn.microsoft.com/windows-hardware/drivers/ddi/configurationparameter/ns-configurationparameter-_ndis_configuration_parameter)