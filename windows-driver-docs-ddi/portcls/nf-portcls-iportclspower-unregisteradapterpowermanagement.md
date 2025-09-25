# IPortClsPower::UnregisterAdapterPowerManagement

## Description

The `UnregisterAdapterPowerManagement` method unregisters the adapter's power management interface with PortCls.

## Parameters

### `_DeviceObject` [in]

Specifies a pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents the functional device object of the adapter.

## Return value

The `UnregisterAdapterPowerManagement` method returns STATUS_SUCCESS if the call is successful. Otherwise, it returns the appropriate error code.

## Remarks

The `UnregisterAdapterPowerManagement` method unregisters the adapter's power management interface that was registered by the [IPortClsPower::RegisterAdapterPowerManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportclspower-registeradapterpowermanagement) method.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IPortClsPower](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportclspower)

[IPortClsPower::RegisterAdapterPowerManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportclspower-registeradapterpowermanagement)