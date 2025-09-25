# _NDIS_CONFIGURATION_PARAMETER structure

## Description

The NDIS_CONFIGURATION_PARAMETER structure contains the data and type of a named entry in the
registry.

## Members

### `ParameterType`

The type of the parameter specified as one of the
[NDIS_PARAMETER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/configurationparameter/ne-configurationparameter-_ndis_parameter_type) enumeration values.

For successful calls to the
[NdisReadConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadconfiguration) function, the
**ParameterType** value matches the value at the
*ParameterType* parameter. However, when the
*ParameterType* parameter is
**NdisParameterHexInteger**, the resulting
**ParameterType** member value is
**NdisParameterInteger**.

### `ParameterData`

A union that contains the value of the given named entry. If ParameterType is a string type, this
member is an NDIS_STRING type describing a counted string in the system-default character set. For
Microsoft Windows 2000 and later drivers, such a string contains Unicode characters. That is, for
Windows 2000 and later, NDIS defines the NDIS_STRING type as a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) type.

This union contains the following members:

### `ParameterData.IntegerData`

A ULONG value that is used when the
**ParameterType** member is set to
**NdisParameterInteger** or
**NdisParameterHexInteger**.

### `ParameterData.StringData`

An NDIS_STRING value that is used when the
**ParameterType** member is set to
**NdisParameterString** or
**NdisParameterMultiString**.

### `ParameterData.BinaryData`

A [BINARY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/configurationparameter/ns-configurationparameter-binary_data) structure that is used when the **ParameterType** member is set to **NdisParameterBinary**.

## Remarks

To read parameters in the registry, an NDIS driver can call the
[NdisReadConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadconfiguration) function. If
the call is successful, NDIS returns a pointer to an NDIS_CONFIGURATION_PARAMETER structure at the
*ParameterValue* parameter of
**NdisReadConfiguration**.

To write parameters to the registry, an NDIS driver can call the
[NdisWriteConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteconfiguration) function. In
this case, the driver initializes an NDIS_CONFIGURATION_PARAMETER structure and passes it at the
*ParameterValue* parameter of
**NdisWriteConfiguration**.

## See also

[BINARY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/configurationparameter/ns-configurationparameter-binary_data)

[NDIS_PARAMETER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/configurationparameter/ne-configurationparameter-_ndis_parameter_type)

[NdisReadConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadconfiguration)

[NdisWriteConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteconfiguration)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)