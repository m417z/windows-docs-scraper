# NdisReadConfiguration function

## Description

The
**NdisReadConfiguration** function returns
the value of a named entry of the specified type from the registry, given the handle to an open registry
key. This function must be invoked serially with respect to itself and the [NdisWriteConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteconfiguration) function.

## Parameters

### `Status` [out]

A pointer to a caller-supplied variable in which this function returns the status of the call as
one of the following values.

| Value | Meaning |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The buffer at *ParameterValue* contains the returned configuration information. |
| **NDIS_STATUS_RESOURCES** | NDIS could not allocate resources, usually enough memory, to return the requested information. |
| **NDIS_STATUS_FAILURE** | The requested information could not be found under the opened registry key designated by the *ConfigurationHandle*. |

### `ParameterValue` [out]

A pointer to a memory location where NDIS supplies a pointer to an
[NDIS_CONFIGURATION_PARAMETER](https://learn.microsoft.com/windows-hardware/drivers/ddi/configurationparameter/ns-configurationparameter-ndis_configuration_parameter) structure if the call to
**NdisReadConfiguration** is
successful. NDIS allocates memory for the
**NDIS_CONFIGURATION_PARAMETER** structure.

### `ConfigurationHandle` [in]

The handle to a registry key that was returned by the
[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndisopenconfigurationex),
[NdisOpenConfigurationKeyByIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationkeybyindex), or
[NdisOpenConfigurationKeyByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationkeybyname) function.

### `Keyword` [in]

A pointer to a caller-supplied NDIS_STRING type describing a counted string, in the system-default
character set, specifying the name of the entry under the open registry key for which to return the
value.

Alternatively, pointer to a caller-supplied NDIS_STRING_CONSTANT specifying one of the following
predefined entry names along with predefined return values:

| Predefined Entry Name | Predefined Return Values |
| --- | --- |
| ProcessorType | * NdisProcessorX86<br>* NdisProcessorAmd64<br>* NdisProcessorIA64<br>* NdisProcessorAlpha<br><br>The following are possible only if an old (pre-NDIS 6.0) driver:<br><br>* NdisProcessorMips<br>* NdisProcessorPpc |
| NdisVersion | 0xMMMMmmmm, where *MMMM* is the major version and *mmmm* is the minor version number. For example, 0x00050000 indicates that the highest NDIS version supported by the system is major version 5, minor version 0. |

### `ParameterType` [in]

The type of the value entry that is specified as one of the
[NDIS_PARAMETER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/configurationparameter/ne-configurationparameter-ndis_parameter_type) enumeration values.
This parameter is ignored in Windows NT and later versions.

## Remarks

In the configuration registry of Windows 2000 and later versions, an NDIS
*keyword* is a synonym for a
*value entry name*. Such a name is a counted sequence of Unicode characters, terminated with a
**NULL**.

Every NDIS driver can set up configuration information in the registry for itself using the
**AddReg** directive in its INF file. For example, a protocol driver might store its
own name as an entry with a preformatted string value that can be passed in calls to the
[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver) function. For more information, see
[Add-registry-sections in
a Network INF File](https://learn.microsoft.com/windows-hardware/drivers/network/add-registry-sections-in-a-network-inf-file).

Each miniport driver also has associated value entries in the registry. The value entries for any
particular miniport driver can be device-dependent in nature. For example, a miniport driver might have
keywords such as *FlowControl, *SpeedDuplex, and *InterruptModeration. The value associated with such an
NDIS keyword can be either an integer (ULONG-type) or a string (NDIS_STRING-type). For example, the set
of possible values for the already mentioned *FlowControl entry might be **NdisParameterInteger** values 0,
1, 2, or 3, or the equivalents in hexadecimal as **NdisParameterHexInteger** values.

NdisReadConfiguration buffers and copies the caller-supplied string at
*Keyword* and releases the storage it allocates for this copy before it returns control to the
caller. The memory it allocates for the
[NDIS_CONFIGURATION_PARAMETER](https://learn.microsoft.com/windows-hardware/drivers/ddi/configurationparameter/ns-configurationparameter-ndis_configuration_parameter) structure is freed when the driver releases the ConfigurationHandle
with the
[NdisCloseConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseconfiguration) function.
The caller of
**NdisReadConfiguration** is responsible
for releasing the buffered string at
*Keyword*.

Note that NDIS does not validate values that a driver reads from the registry. The caller of
**NdisReadConfiguration** must therefore
not make any assumptions about such values and must validate each value read from the registry. If the
caller determines that a value is out of bounds, it should use a default value instead.

For more information about setup and installation files, see
[Device Installation
Overview](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-and-driver-installation).

## See also

[ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string)

[NDIS_CONFIGURATION_PARAMETER](https://learn.microsoft.com/windows-hardware/drivers/ddi/configurationparameter/ns-configurationparameter-ndis_configuration_parameter)

[NDIS_PARAMETER_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/configurationparameter/ne-configurationparameter-ndis_parameter_type)

[NdisAnsiStringToUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisansistringtounicodestring)

[NdisCloseConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseconfiguration)

[NdisFreeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreestring)

[NdisInitAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitansistring)

[NdisInitUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitunicodestring)

[NdisInitializeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializestring)

[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndisopenconfigurationex)

[NdisOpenConfigurationKeyByIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationkeybyindex)

[NdisOpenConfigurationKeyByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationkeybyname)

[NdisReadNetworkAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadnetworkaddress)

[NdisUnicodeStringToAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisunicodestringtoansistring)

[NdisWriteConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteconfiguration)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)