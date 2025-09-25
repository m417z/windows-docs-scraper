# NdisQueryAdapterInstanceName function

## Description

The
**NdisQueryAdapterInstanceName** function retrieves the friendly name of a physical NIC or a virtual
adapter that the calling protocol driver is bound to.

## Parameters

### `pAdapterInstanceName`

A pointer to a caller-supplied NDIS_STRING type that receives a counted Unicode string. This
string specifies the friendly name of the interface to which the binding refers. This interface is
either a physical NIC or a virtual adapter. For Windows 2000 and later, NDIS defines the NDIS_STRING
type as a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) type.

### `NdisBindingHandle` [in]

A handle that identifies the binding to the target physical NIC or virtual adapter of the
next-lower driver to which the caller is bound. Typically,
*NdisBindingHandle* was returned by the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function.

## Return value

**NdisQueryAdapterInstanceName** returns NDIS_STATUS_SUCCESS if memory for the string at
*AdapterInstanceName* was successfully allocated; otherwise, it returns
NDIS_STATUS_RESOURCES.

## Remarks

A protocol driver uses
**NdisQueryAdapterInstanceName** to retrieve the friendly name of a physical NIC or a virtual adapter
to which the protocol driver is bound. The protocol driver specifies the handle to such a NIC or virtual
adapter in
*NdisBindingHandle* . The protocol driver calls the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function to retrieve
this handle.

**NdisQueryAdapterInstanceName** allocates memory for the string that specifies the friendly name.
After the caller finishes using this memory, the caller must call the
[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory) function to release the
memory.

Friendly names are intended to help the user quickly and accurately identify a physical NIC or virtual
adapter--for example, "PCI Ethernet Adapter" and "Virtual Private Networking Adapter" are considered
friendly names.

## See also

[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)