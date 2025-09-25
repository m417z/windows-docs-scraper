# NdisIMDeInitializeDeviceInstance function

## Description

The
**NdisIMDeInitializeDeviceInstance** function calls an NDIS intermediate driver's
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function to tear down the
driver's virtual miniport.

## Parameters

### `NdisMiniportHandle` [in]

The handle that NDIS supplied to the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

## Return value

**NdisIMDeInitializeDeviceInstance** returns NDIS_STATUS_SUCCESS if the NIC has been torn down.
Otherwise, it can return NDIS_STATUS_FAILURE if the given
*NdisMiniportHandle* is invalid.

## Remarks

For NDIS intermediate drivers,
**NdisIMDeInitializeDeviceInstance** is the reciprocal of the
[NdisIMInitializeDeviceInstanceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisiminitializedeviceinstanceex) function. Such a driver usually calls
**NdisIMDeInitializeDeviceInstance** from its
[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex) function, when the underlying miniport adapter to which it was bound is
being removed from the system, possibly because it is being reconfigured.

The call to
**NdisIMDeInitializeDeviceInstance** causes an NDIS call to the intermediate driver's
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function after NDIS has
told all higher level protocol drivers that had bound themselves to the intermediate's virtual miniport
that they must unbind.

## See also

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[NdisIMInitializeDeviceInstanceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisiminitializedeviceinstanceex)

[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex)