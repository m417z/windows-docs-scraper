# PcRegisterAdapterPnpManagement function

## Description

The PcRegisterAdapterPnpManagement function registers the adapter's PnP-management interface with the PortCls system driver. It is used to support PnP rebalance.

## Parameters

### `Unknown`

Pointer to an adapter driver object's [**IUnknown**](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) interface. The PortCls system driver queries this object for its [IAdapterPnpManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iadapterpnpmanagement) interface.

### `DeviceObject` [in]

Specifies a pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents the functional device object of the adapter.

## Return value

**PcRegisterAdapterPnpManagement** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

Portcls uses **PcRegisterAdapterPnpManagement** and [PcUnregisterAdapterPnpManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcunregisteradapterpnpmanagement) to support PNP rebalance.

For more information, see [Implement PnP Rebalance for PortCls Audio Drivers](https://learn.microsoft.com/windows-hardware/drivers/audio/implement-pnp-rebalance-for-portcls-audio-drivers).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IAdapterPnpManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iadapterpnpmanagement)

[Implement PnP Rebalance for PortCls Audio Drivers](https://learn.microsoft.com/windows-hardware/drivers/audio/implement-pnp-rebalance-for-portcls-audio-drivers)

[PcUnregisterAdapterPnpManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcunregisteradapterpnpmanagement)