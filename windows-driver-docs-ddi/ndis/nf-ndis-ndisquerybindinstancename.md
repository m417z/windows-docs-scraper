# NdisQueryBindInstanceName function

## Description

The
**NdisQueryBindInstanceName** function retrieves the friendly name of a physical NIC or a virtual adapter
that the calling protocol driver will bind to.

## Parameters

### `pAdapterInstanceName` [out]

A pointer to a caller-supplied NDIS_STRING type that receives a counted Unicode string. This
string specifies the friendly name of the interface to which the binding refers. This interface is
either a physical NIC or a virtual adapter. For Microsoft Windows 2000 and later operating systems, NDIS
defines the NDIS_STRING type as a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) type.

### `BindingContext` [in]

A handle that identifies the NDIS context area for the bind operation. NDIS passed this handle to
the
*BindContext* parameter of the
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function.

## Return value

**NdisQueryBindInstanceName** returns NDIS_STATUS_SUCCESS if memory for the string at
*pAdapterInstanceName* was successfully allocated; otherwise, it returns
NDIS_STATUS_RESOURCES.

## Remarks

A protocol driver uses
**NdisQueryBindInstanceName** to retrieve the friendly name of a physical NIC or a virtual adapter to
which the protocol driver will be bound. The protocol driver specifies the binding context that NDIS
provided in the
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) function.

Protocol drivers can use
**NdisQueryBindInstanceName** to obtain the friendly name before they bind to the adapter.

**NdisQueryBindInstanceName** allocates memory for the string that specifies the friendly name. After
the caller finishes using this memory, the caller must call the
[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory) function to release the
memory.

Friendly names are intended to help the user quickly and accurately identify a physical NIC or virtual
adapter--for example, "PCI Ethernet Adapter" and "Virtual Private Networking Adapter" are considered
friendly names.

## See also

[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)