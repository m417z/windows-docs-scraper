# NdisMFreePort function

## Description

The
**NdisMFreePort** function frees an NDIS port that was previously allocated with the
[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport) function.

## Parameters

### `NdisMiniportHandle`

The miniport adapter handle that NDIS passed to the
*MiniportAdapterHandle* parameter of the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `PortNumber` [in]

The number of the NDIS port that NDIS should free. The
*PortNumber* value is an NDIS_PORT_NUMBER value, which has a ULONG data type. NDIS provided the port
number in the
**PortNumber** member of the
[NDIS_PORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port_characteristics) structure when the miniport driver called the
[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport) function.

The port number can be a number from 1 through 0xffffff. You cannot set
*PortNumber* to zero, which indicates the default port.

## Return value

**NdisMFreePort** can return one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | NDIS successfully freed the resources for the port. |
| **NDIS_STATUS_INVALID_PORT** | NDIS could not free the resources for the port because the port number was invalid. |
| **NDIS_STATUS_INVALID_PORT_STATE** | NDIS could not free the resources for the port because the port was is in a state where the free operation is invalid. To free the port, the port must be in the allocated state. |
| **NDIS_STATUS_INVALID_DATA** | The port number that was supplied at the *PortNumber* parameter was invalid. |

## Remarks

If a miniport driver allocated a port by calling the
[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport) function, the driver
must free the port before it returns from its
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function. If the miniport
driver activated the port by issuing a
**NetEventPortActivation** Plug and Play (PnP) event, the driver must issue a
**NetEventPortDeactivation** PnP event for the port before freeing the port.

When a miniport driver calls **NdisMFreePort** to free a port, NDIS also frees the port number that is assigned to the freed port so that NDIS can reuse the port number.

The miniport driver must not attempt to free the default port.

## See also

[Default NDIS Port](https://learn.microsoft.com/windows-hardware/drivers/network/default-ndis-port)

[Freeing an NDIS Port](https://learn.microsoft.com/windows-hardware/drivers/network/freeing-an-ndis-port)

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_PORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port_characteristics)

[NdisMAllocatePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocateport)