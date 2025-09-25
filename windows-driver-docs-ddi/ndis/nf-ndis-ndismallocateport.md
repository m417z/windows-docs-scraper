# NdisMAllocatePort function

## Description

The
**NdisMAllocatePort** function allocates an NDIS port that is associated with a miniport adapter.

## Parameters

### `NdisMiniportHandle`

The miniport adapter handle that NDIS passed to the
*MiniportAdapterHandle* parameter of the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `PortCharacteristics` [in, out]

A pointer to an
[NDIS_PORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port_characteristics) structure that defines the characteristics of the port.

## Return value

**NdisMAllocatePort** can return one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | NDIS successfully allocated resources for the port. |
| **NDIS_STATUS_RESOURCES** | NDIS could not allocate resources for the port. |
| **NDIS_STATUS_CLOSING** | The port allocation failed because the associated miniport adapter is closing. |
| **NDIS_STATUS_INVALID_DATA** | The data that was supplied at the *PortCharacteristics* parameter was invalid. |

## Remarks

The
**NdisMAllocatePort** function allocates resources and a port number for a port that is associated with
a miniport adapter. The port is not active until the miniport driver issues a
**NetEventPortActivation** Plug and Play (PnP) event for the port.

After the miniport driver activates the port, NDIS generates a PnP notification for the overlying
drivers. If an overlying driver or user-mode application issues the
[OID_GEN_ENUMERATE_PORTS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-enumerate-ports) OID to
enumerate a miniport adapter's ports, NDIS does not include non-active allocated ports in the list of the
ports.

When
**NdisMAllocatePort** successfully returns, the
**PortNumber** member of the
[NDIS_PORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port_characteristics) structure that the
*PortCharacteristics* parameter specifies is set to the port number that NDIS assigned to the
port.

After a port is no longer required, the miniport driver should call the
[NdisMFreePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismfreeport) function to free the port.

## See also

[Allocating an NDIS Port](https://learn.microsoft.com/windows-hardware/drivers/network/allocating-an-ndis-port)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_PORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port_characteristics)

[NdisMFreePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismfreeport)

[OID_GEN_ENUMERATE_PORTS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-enumerate-ports)