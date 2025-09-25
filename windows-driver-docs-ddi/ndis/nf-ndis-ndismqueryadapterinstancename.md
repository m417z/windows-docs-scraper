# NdisMQueryAdapterInstanceName function

## Description

The
**NdisMQueryAdapterInstanceName** function retrieves the friendly name of a miniport adapter.

## Parameters

### `pAdapterInstanceName`

A pointer to a caller-supplied NDIS_STRING type that receives a counted Unicode string. This
string specifies the friendly name of the interface for the given miniport adapter. For Windows Vista
and later versions of the Windows operating system, NDIS defines the NDIS_STRING type as a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) type.

### `MiniportHandle`

The handle to the miniport adapter that was previously input to the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

## Return value

Returns NDIS_STATUS_SUCCESS if memory for the string at
*AdapterInstanceName* was successfully allocated; otherwise, it returns
NDIS_STATUS_RESOURCES.

## Remarks

A miniport driver uses
**NdisMQueryAdapterInstanceName** to retrieve the friendly name of an interface that the miniport
driver controls. This interface is either a physical NIC or a virtual adapter and is called a
*miniport adapter*. The miniport driver specifies the handle to a miniport adapter in
*MiniportAdapterHandle* . This handle to the miniport adapter is passed to the miniport driver's
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function to
set up the miniport adapter for network I/O operations.

**NdisMQueryAdapterInstanceName** allocates memory for the string that specifies the friendly name.
After the caller finishes using this memory, the caller must call the
[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory) function to release the
memory.

Friendly names are intended to help the user quickly and accurately identify a physical NIC or virtual
adapter--for example, "PCI Ethernet Adapter" and "Virtual Private Networking Adapter" are considered
friendly names.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)