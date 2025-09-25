# NdisOpenProtocolConfiguration function

## Description

**Note** NDIS 5. *x* has been deprecated and is superseded by NDIS 6. *x*. For new NDIS driver development, see [Network Drivers Starting with Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). For information about porting NDIS 5. *x* drivers to NDIS 6. *x*, see [Porting NDIS 5.x Drivers to NDIS 6.0](https://msdn.microsoft.com/library/Ff570059).

**NdisOpenProtocolConfiguration** returns a handle for the registry key in which a protocol driver's per-adapter information is stored.

## Parameters

### `Status` [out]

Pointer to a caller-supplied variable that is set to NDIS\_STATUS\_SUCCESS or a failure status on return from this function.

### `ConfigurationHandle` [out]

Pointer to a caller-supplied variable in which this function returns the handle to the registry key for the named miniport driver to which the caller will bind itself later. Value entries under this key contain protocol-installed, adapter-specific information.

### `ProtocolSection` [in]

Pointer to a caller-supplied NDIS\_STRING type containing a counted string, specified in the system-default character set. This counted string names the NDIS NIC driver, effectively the adapter, for which the per-adapter parameters key in the registry protocol section should be opened. For Windows 2000 and later protocols, this counted string contains Unicode characters. That is, for Windows 2000 and later, NDIS defines the NDIS\_STRING type as a [**UNICODE\_STRING**](https://msdn.microsoft.com/library/Ff564879) type.

This pointer is the *SystemSpecific1* input parameter to the caller's [**ProtocolBindAdapter**](https://msdn.microsoft.com/library/ff562465/(v=vs.85/)) function.

## Remarks

**NdisOpenProtocolConfiguration** returns a handle that the caller can pass subsequently to the *Ndis..Configuration* functions to retrieve or store information in the registry.

A protocol driver calls **NdisOpenProtocolConfiguration** to get a registry key handle to be passed subsequently to other *Ndis..Configuration* functions, such as *NdisRead/WriteConfiguration* or *NdisOpenConfigurationKeyByName/Index*, if its installation file stored adapter-specific configuration information in the protocol section of the registry from which the protocol sets up its bindings.

A protocol can call [**NdisOpenConfigurationKeyByName**](https://msdn.microsoft.com/library/Ff563725) or **NdisOpenConfigurationKeyByIndex** to open any subkey of the registry key for which **NdisOpenProtocolConfiguration** returns the handle.

Windows 2000 and later protocols call kernel-mode support routines to open their own protocol-specific registry keys. For more information about these support routines, see the [Summary of Kernel-Mode Support Routines](https://msdn.microsoft.com/library/Ff563889) and [Power Management Support Routines](https://msdn.microsoft.com/library/Ff559835).

- Target platform: [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356)
- Version: Not supported for NDIS 6.0 drivers in Windows Vista. Use [**NdisOpenConfigurationEx**](https://msdn.microsoft.com/library/Ff563717)instead. Supported for NDIS 5.1 drivers in Windows Vista and Windows XP.

## See also

- [**ANSI\_STRING**](https://msdn.microsoft.com/library/Ff540605)
- [**NdisCloseConfiguration**](https://msdn.microsoft.com/library/Ff561642)
- [**NdisInitializeString**](https://msdn.microsoft.com/library/Ff562741)
- [**NdisInitUnicodeString**](https://msdn.microsoft.com/library/Ff562745)
- [**NdisOpenConfigurationKeyByIndex**](https://msdn.microsoft.com/library/Ff563721)
- [**NdisOpenConfigurationKeyByName**](https://msdn.microsoft.com/library/Ff563725)
- [**NdisReadConfiguration**](https://msdn.microsoft.com/library/Ff564511)
- [**NdisWriteConfiguration**](https://msdn.microsoft.com/library/Ff564659)
- [**ProtocolBindAdapter**](https://msdn.microsoft.com/library/ff562465/(v=vs.85/))
- [**UNICODE\_STRING**](https://msdn.microsoft.com/library/Ff564879)