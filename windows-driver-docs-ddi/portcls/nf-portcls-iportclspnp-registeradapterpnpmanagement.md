# IPortClsPnp::RegisterAdapterPnpManagement

## Description

The `RegisterAdapterPowerManagement` method registers the PnP management interface of the adapter with PortCls.

## Parameters

### `pUnknown` [in]

Specifies a pointer to **IUnknown** of [IAdapterPnpManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iadapterpnpmanagement).

### `DeviceObject` [in]

Specifies a pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents the functional device object of the adapter.

## Return value

The `RegisterAdapterPowerManagement` method returns STATUS_SUCCESS if the call is successful. Otherwise, it returns the appropriate error code.

## Remarks

When the `RegisterAdapterPowerManagement` method registers the PnP management interface for the adapter with PortCls, it allows the adapter driver to be notified of PnP state change events.

For more information, see [Implement PnP Rebalance for PortCls Audio Drivers](https://learn.microsoft.com/windows-hardware/drivers/audio/implement-pnp-rebalance-for-portcls-audio-drivers).

## See also

[IPortClsPnp](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportclspnp)

[IPortClsPower::UnregisterAdapterPowerManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportclspower-unregisteradapterpowermanagement)