# NdisReadNetworkAddress function

## Description

The
**NdisReadNetworkAddress** function returns the software-configurable network address that was stored in
the registry for a NIC when it was installed in the machine.

## Parameters

### `Status` [out]

A pointer to a caller-supplied variable in which this function returns the status of the call as
one of the following:

#### NDIS_STATUS_SUCCESS

The caller can use the address returned at
*NetworkAddress* for the NIC.

#### NDIS_STATUS_FAILURE

There was no NIC address information available in the caller's registry
**Parameters** key or the value stored was not a string.

### `NetworkAddress` [out]

A pointer to a caller-supplied variable in which this function returns a pointer to a buffer that contains the
network address (typically the MAC address), stored as a sequence of byte integers, if the call is successful.

### `NetworkAddressLength` [out]

A pointer to a caller-supplied variable in which this function returns the number of bytes that
are returned at
*NetworkAddress*.

### `ConfigurationHandle` [in]

The configuration handle returned by the
[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationex) function.

## Remarks

**NdisReadNetworkAddress** searches the registry
**Parameters** key designated by the given
*ConfigurationHandle* for the keyword
**NetworkAddress**, converts the value of this string-type entry into a sequence of byte integers, and
stores the requested information internally. The storage that NDIS allocates for such an address remains
valid until the miniport driver calls the
[NdisCloseConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseconfiguration) function,
which frees the memory.

The caller cannot use the variable at
*NetworkAddress* as a pointer unless
**NdisReadNetworkAddress** returns NDIS_STATUS_SUCCESS at
*Status*.

The installation program for a NIC that supports software-configurable network addressing should store
a value entry named with the
**NetworkAddress** keyword in the
**HKLM\System\CurrentControlSet\Control\Class\{4d36e972...}\00*xx*** key of the registry.

A NIC installer usually stores the value of a
**NetworkAddress** entry in the registry as a string of hexadecimal digits. Optionally, an installer
can store such an address as a string of paired digits, with each pair separated from the next by a
hyphen.
**NdisReadNetworkAddress** discards hyphens and converts each such pair into a single byte.

In either form,
**NdisReadNetworkAddress** converts the address specified as a string, one character at a time, into
the equivalent integer until the string is exhausted.

In the registry of Windows 2000 and later versions, such an installed address string contains Unicode
characters.

Note that NDIS does not validate the value at
*NetworkAddress*. NDIS does not guarantee that this value is a valid address, that the value has the
proper length, or even that the value is a network address. The caller of
**NdisReadNetworkAddress** must therefore not make any assumptions about this value and must itself
validate the value. If the caller determines that the value is out of bounds, it should not use the
value; instead, it should use the permanent medium access control (MAC) address or a default address.

## See also

[NdisCloseConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscloseconfiguration)

[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndisopenconfigurationex)