# NdisOpenConfigurationKeyByName function

## Description

The
**NdisOpenConfigurationKeyByName** function opens a named subkey of a given open registry key that is
designated by a caller-supplied handle.

## Parameters

### `Status` [out]

A pointer to a caller-supplied variable in which this function returns the status of its attempt
to open the registry key. Possible return values are one of the following:

#### NDIS_STATUS_SUCCESS

NDIS has initialized accessed to the subkey specified by
*SubKeyName* .

#### NDIS_STATUS_FAILURE

The key could not be opened.

### `ConfigurationHandle` [in]

The handle to a registry key for which a subkey should be opened. Typically,
*ConfigurationHandle* is returned by the
[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationex) function.

### `SubKeyName` [in]

A pointer to an NDIS_STRING type containing a caller-supplied, counted string in the
system-default character set that specifies the name of the registry subkey to open. For Microsoft
Windows 2000 and later drivers, this string contains Unicode characters. That is, for Windows 2000 and
later, NDIS defines the NDIS_STRING type as a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) type.

### `SubKeyHandle` [out]

A pointer to a caller-supplied variable in which this function returns a handle to the opened
subkey if this call is successful.

## Remarks

**NdisOpenConfigurationKeyByName** allows a driver to access configuration information that is stored
in a named subkey in the registry.

Note that the
*ConfigurationHandle* passed in to
**NdisOpenConfigurationKeyByName** can be any valid handle to a registry key already opened by the
caller.
**NdisOpenConfigurationKeyByName** returns configuration information for subkeys relative to any valid
*ConfigurationHandle* .

After a driver has consumed and, possibly, modified the registry configuration information, it must
call the
[NdisCloseConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseconfiguration) function to
release the handle that was obtained from
**NdisOpenConfigurationKeyByName**.
**NdisCloseConfiguration** also frees any temporary storage that NDIS allocated in the driver's calls
to the
[NdisReadConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadconfiguration),
[NdisReadNetworkAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadnetworkaddress), or
[NdisWriteConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteconfiguration) functions
with the
*SubKeyHandle* that
**NdisOpenConfigurationKeyByName** returned.

## See also

[ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisCloseConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseconfiguration)

[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndisopenconfigurationex)

[NdisOpenConfigurationKeyByIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationkeybyindex)

[NdisReadConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadconfiguration)

[NdisWriteConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteconfiguration)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)