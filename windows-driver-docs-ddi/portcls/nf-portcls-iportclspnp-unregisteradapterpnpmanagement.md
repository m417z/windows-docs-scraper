# IPortClsPnp::UnregisterAdapterPnpManagement

## Description

The `UnRegisterAdapterPowerManagement` method unregisters the PnP management interface of the adapter from PortCls.

## Parameters

### `DeviceObject` [in]

Specifies a pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents the functional device object of the adapter that the PnP management was registered with earlier using [IPortClsPnp::RegisterAdapterPnpManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportclspnp-registeradapterpnpmanagement).

## Return value

The `UnregisterAdapterPowerManagement` method returns STATUS_SUCCESS if the call is successful. Otherwise, it returns the appropriate error code.

## Remarks

For more information, see [Implement PnP Rebalance for PortCls Audio Drivers](https://learn.microsoft.com/windows-hardware/drivers/audio/implement-pnp-rebalance-for-portcls-audio-drivers).

## See also

[IPortClsPnp](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportclspnp)

[IPortClsPnp::RegisterAdapterPnpManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportclspnp-registeradapterpnpmanagement)