# NdisOpenConfigurationKeyByIndex function

## Description

The
**NdisOpenConfigurationKeyByIndex** function opens a subkey of a given open registry key that is
designated by a caller-supplied handle.

## Parameters

### `Status` [out]

A pointer to a caller-supplied variable in which this function returns the status of its attempt
to open the designated registry key. Possible return values are one of the following:

#### NDIS_STATUS_SUCCESS

NDIS has initialized accessed to the subkey specified by
*KeyName* and
*Index* .

#### NDIS_STATUS_FAILURE

The key could not be opened.

### `ConfigurationHandle` [in]

The handle to a registry key for which a subkey is to be opened. Typically,
*ConfigurationHandle* is returned by the
[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationex) function.

### `Index` [in]

The index of the subkey to be opened. This zero-based value designates the subkey to be opened
under the key already opened with
*ConfigurationHandle* .

### `KeyName` [out]

A pointer to an NDIS_STRING type containing a caller-supplied buffer in which this functions
returns a counted string in the system-default character set. This string specifies the name of the
opened subkey if the call succeeds. For Microsoft Windows 2000 and later drivers, this string contains
Unicode characters. That is, for Windows 2000 and later, NDIS defines the NDIS_STRING type as a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) type.

### `KeyHandle` [out]

A pointer to a caller-supplied variable in which this function returns a handle to the opened
subkey if the call succeeds.

## Remarks

**NdisOpenConfigurationKeyByIndex** allows a driver to access configuration information that its
installation file stored in a registry subkey.

Note that the
*ConfigurationHandle* passed in to
**NdisOpenConfigurationKeyByIndex** can be any valid handle to a registry key already opened by the
caller.
**NdisOpenConfigurationKeyByIndex** returns configuration information for subkeys relative to any valid
*ConfigurationHandle* .

Since
**NdisOpenConfigurationKeyByIndex** references a subkey through an index, the driver does not have to
specify subkey names. A driver can sequence through a set of registry subkeys by repeatedly calling
**NdisOpenConfigurationKeyIndex** after incrementing the index until the function returns
NDIS_STATUS_FAILURE, thereby indicating that there are no more subkeys to open.

After a driver has consumed and, possibly, modified the configuration information stored in the
registry, it must call the
[NdisCloseConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseconfiguration) function to
release the handle that is obtained from
**NdisOpenConfigurationKeyByIndex**.
**NdisCloseConfiguration** also frees any temporary storage that NDIS allocated for the driver's calls
to the
[NdisReadConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadconfiguration),
[NdisReadNetworkAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadnetworkaddress), or
[NdisWriteConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteconfiguration) functions
with the
*SubKeyHandle* that
**NdisOpenConfigurationKeyByIndex** returned.

## See also

[ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisCloseConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseconfiguration)

[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndisopenconfigurationex)

[NdisOpenConfigurationKeyByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationkeybyname)

[NdisReadConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadconfiguration)

[NdisWriteConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteconfiguration)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)