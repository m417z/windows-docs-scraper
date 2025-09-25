# PcUnregisterAdapterPnpManagement function

## Description

The **PcUnregisterAdapterPnpManagement** function unregisters the audio adapter's PnP management interface from the PortCls class driver. It is used to support PnP rebalance.

## Parameters

### `DeviceObject` [in]

Specifies a pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents the functional device object of the adapter.

## Return value

The **PcUnregisterAdapterPnpManagement** function returns STATUS_SUCCESS if the function call was successful. Otherwise, it returns the appropriate error code.

## Remarks

The **PcUnregisterAdapterPnpManagement** function unregisters a driver's PnP management interface that was registered with PortCls by using the **PcUnregisterAdapterPnpManagement** function.

 This function must only be called if the PnP management interface for the adapter was previously registered with PortCls using [PcRegisterAdapterPnpManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisteradapterpnpmanagement).

Portcls uses [PcRegisterAdapterPnpManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisteradapterpnpmanagement) and **PcUnregisterAdapterPnpManagement** to support PNP rebalance.

For more information, see [Implement PnP Rebalance for PortCls Audio Drivers](https://learn.microsoft.com/windows-hardware/drivers/audio/implement-pnp-rebalance-for-portcls-audio-drivers).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[PcRegisterAdapterPnpManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisteradapterpnpmanagement)