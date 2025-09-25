# NdisIfRegisterInterface function

## Description

The
**NdisIfRegisterInterface** function registers an NDIS network interface.

## Parameters

### `NdisProviderHandle` [in]

A handle that identifies the network interface provider that is registering the interface. The
caller obtained this handle from a previous call to the
[NdisIfRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterprovider) function.

### `NetLuid` [in]

The caller-supplied
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) value that is associated with the
interface. The interface provider used the
[NDIS_MAKE_NET_LUID](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-make-net-luid) macro to create this
NET_LUID value. The interface provider should recover the NET_LUID value from persistent storage after
the computer restarts and provide the same NET_LUID value each time it registers a particular
interface.

### `ProviderIfContext` [in]

A handle to a caller-allocated context area that is associated with the interface. NDIS passes
this handle to the callback functions that the caller registered with
**NdisIfRegisterProvider**.

### `pIfInfo` [in]

A pointer to a caller-allocated
[NET_IF_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_if_information) structure that
provides information about the interface. This structure contains information that remains constant
while the interface exists.

### `pfIndex`

A pointer to a caller-supplied interface index variable. If NDIS successfully registers an
interface, NDIS allocates an interface index for that interface and sets the value at
*pIfIndex* . The interface index is a 24-bit value that is unique on the local computer. NDIS might
not return the same interface index every time a provider registers an interface with the same NET_LUID
value . The interface index value zero is reserved, and NDIS does not assign it to any interface. Do not
confuse the interface index with a NET_LUID index.

## Return value

**NdisIfRegisterInterface** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The operation completed successfully. |
| **NDIS_STATUS_RESOURCES** | The operation failed because of insufficient resources. |
| **NDIS_STATUS_INVALID_PARAMETER** | **NdisIfRegisterInterface** failed because some of the input parameters are invalid. |
| **NDIS_STATUS_DUPLICATE_OBJECTID** | **NdisIfRegisterInterface** failed because there is already an interface registered with the same NET_LUID value that the *NetLuid* parameter specified. |

## Remarks

NDIS interface providers call the
**NdisIfRegisterInterface** function to register a network interface. A call to this function does not
imply that the interface is active.

Whenever a computer restarts, NDIS starts with an empty list of registered network interfaces. An
interface provider calls the
**NdisIfRegisterInterface** function whenever an interface is started (or detected) and the interface's
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) is known.

The method for detecting or starting an interface is application dependent. For example, if an LBFO
MUX intermediate driver is an interface provider, that driver might register an internal interface when
NDIS calls the driver's
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function
for the first underlying miniport adapter.

An interface provider can put information about an interface in persistent storage and restore the
interface as required for the particular application. For example, the provider can store additional
information about the interface with the
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) and it can reregister the interface after
the computer restarts.

If
**NdisIfRegisterInterface** is successful, NDIS adds the interface to the list of known interfaces and
allocates a new interface index for this interface. Interface providers should register both enabled and
disabled interfaces, wherever possible. All enabled interfaces
must be registered.

NDIS might not return the same interface index every time a provider registers an interface with the
same NET_LUID value. For example, NDIS does not necessarily assign the same interface index when an
interface is reregistered after a computer restarts or when the interface is deregistered and
re-registered. The interface index value zero is reserved, and NDIS does not assign it to any
interface.

To indicate that an interface should be removed from the list of known interfaces on the computer, an
interface provider calls the
[NdisIfDeregisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifderegisterinterface) function, for example, because the interface has been uninstalled. .

## See also

[NDIS_MAKE_NET_LUID](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-make-net-luid)

[NET_IF_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_if_information)

[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh)

[NdisIfDeregisterInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifderegisterinterface)

[NdisIfRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterprovider)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)