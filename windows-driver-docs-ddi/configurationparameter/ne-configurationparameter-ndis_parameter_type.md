# _NDIS_PARAMETER_TYPE enumeration

## Description

The NDIS_PARAMETER_TYPE enumeration type identifies the type of a registry entry.

## Constants

### `NdisParameterInteger`

An integer in decimal notation.

### `NdisParameterHexInteger`

An integer in hexadecimal notation.

### `NdisParameterString`

A string of type NDIS_STRING.

### `NdisParameterMultiString`

A multistring parameter of the REG_MULTI_SZ type.

### `NdisParameterBinary`

A binary value of type REG_BINARY.

## Remarks

The NDIS_PARAMETER_TYPE enumeration type is used in the
[NDIS_CONFIGURATION_PARAMETER](https://learn.microsoft.com/windows-hardware/drivers/ddi/configurationparameter/ns-configurationparameter-_ndis_configuration_parameter) structure and in the
*ParameterType* parameter of the
[NdisReadConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadconfiguration) function.

## See also

[NDIS_CONFIGURATION_PARAMETER](https://learn.microsoft.com/windows-hardware/drivers/ddi/configurationparameter/ns-configurationparameter-_ndis_configuration_parameter)

[NdisReadConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadconfiguration)