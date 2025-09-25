# IPortClsPower::RegisterAdapterPowerManagement

## Description

The `RegisterAdapterPowerManagement` method registers the power management interface of the adapter with PortCls.

## Parameters

### `_pUnknown` [in]

Specifies a pointer to **IUnknown**. . PortCls queries this **IUnknown** object for the [IAdapterPowerManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iadapterpowermanagement) or the [IAdapterPowerManagement2](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iadapterpowermanagement2) interface of the adapter.

### `_DeviceObject` [in]

Specifies a pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents the functional device object of the adapter.

## Return value

The `RegisterAdapterPowerManagement` method returns STATUS_SUCCESS if the call is successful. Otherwise, it returns the appropriate error code.

## Remarks

When the `RegisterAdapterPowerManagement` method registers the power management interface for the adapter with PortCls, it allows the adapter driver to be notified of power state change events.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IAdapterPowerManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iadapterpowermanagement)

[IAdapterPowerManagement2](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iadapterpowermanagement2)

[IPortClsPower](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportclspower)