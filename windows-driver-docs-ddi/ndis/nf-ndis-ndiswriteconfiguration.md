# NdisWriteConfiguration function

## Description

The
**NdisWriteConfiguration** function writes a caller-supplied value for a specified entry into the
registry. This function must be invoked serially with respect to itself and the [NdisReadConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadconfiguration) function.

## Parameters

### `Status` [out]

A pointer to a caller-supplied variable in which this function returns the status of the call as
one of the following:

#### NDIS_STATUS_SUCCESS

The supplied value at
*ParameterValue* was written into the registry. If this is a new entry, the name at
*Keyword* also was written into the registry.

#### NDIS_STATUS_NOT_SUPPORTED

The supplied
**ParameterType** is invalid.

#### NDIS_STATUS_RESOURCES

NDIS could not allocate resources, usually enough memory, to transfer the requested information
to the registry.

#### NDIS_STATUS_FAILURE

The requested information could not be written.

### `ConfigurationHandle` [in]

The handle to a registry key that was returned by the
[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndisopenconfigurationex),
[NdisOpenConfigurationKeyByIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationkeybyindex), or
[NdisOpenConfigurationKeyByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationkeybyname) function.

### `Keyword` [in]

A pointer to an NDIS_STRING type describing a caller-supplied counted string, in the
system-default character set, specifying the name of an entry for which to write the value. For
Microsoft Windows 2000 and later drivers, this string contains Unicode characters. That is, for Windows
2000 and later, NDIS defines the NDIS_STRING type as a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) type.

### `ParameterValue` [in]

Pointer to a caller-supplied
[NDIS_CONFIGURATION_PARAMETER](https://learn.microsoft.com/windows-hardware/drivers/ddi/configurationparameter/ns-configurationparameter-ndis_configuration_parameter) structure.

## Remarks

If an entry of the same name as at
*Keyword* already exists under the opened registry key,
**NdisWriteConfiguration** replaces its current value with the caller-supplied value. Otherwise,
**NdisWriteConfiguration** adds a new value entry with the given name and supplied value to the
registry.

In the configuration registry of Windows 2000 and later versions, an NDIS
*Keyword* is a synonym for a
*value entry name*. Such a name is a counted sequence of Unicode characters, terminated with a
null character.

**NdisWriteConfiguration** buffers and copies the caller-supplied string at
*Keyword* and the caller-supplied data specified at
*ParameterValue* . This memory is freed when the driver releases the
*ConfigurationHandle* with the
[NdisCloseConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseconfiguration) function.
The caller of
**NdisWriteConfiguration** is responsible for releasing the buffered string at
*Keyword* and the memory allocated for the
[NDIS_CONFIGURATION_PARAMETER](https://learn.microsoft.com/windows-hardware/drivers/ddi/configurationparameter/ns-configurationparameter-ndis_configuration_parameter) structure.

As an alternative to calling
**NdisWriteConfiguration**, every NDIS driver can set up configuration information in the registry for
itself using the AddReg directive in the driver's INF file.

For more information about setup and installation files for Windows 2000 and later versions, see
[Device Installation
Overview](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-and-driver-installation).

## See also

[ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_CONFIGURATION_PARAMETER](https://learn.microsoft.com/windows-hardware/drivers/ddi/configurationparameter/ns-configurationparameter-ndis_configuration_parameter)

[NdisAnsiStringToUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisansistringtounicodestring)

[NdisCloseConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseconfiguration)

[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory)

[NdisFreeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreestring)

[NdisInitAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitansistring)

[NdisInitUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitunicodestring)

[NdisInitializeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializestring)

[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndisopenconfigurationex)

[NdisOpenConfigurationKeyByIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationkeybyindex)

[NdisOpenConfigurationKeyByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationkeybyname)

[NdisReadConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadconfiguration)

[NdisUnicodeStringToAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisunicodestringtoansistring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)