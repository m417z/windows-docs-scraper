# PcUnregisterAdapterPowerManagement function

## Description

The **PcUnregisterAdapterPowerManagement** function unregisters the audio adapter's power management interface from the PortCls class driver. The **PcUnregisterAdapterPowerManagement** function is available in Windows 7 and later versions of Windows.

## Parameters

### `pDeviceObject` [in]

Specifies a pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents the functional device object of the adapter.

## Return value

The **PcUnregisterAdapterPowerManagement** function returns STATUS_SUCCESS if the function call was successful. Otherwise, it returns the appropriate error code.

## Remarks

The **PcUnregisterAdapterPowerManagement** function unregisters a driver's power management interface that was registered with PortCls by using the [PcRegisterAdapterPowerManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisteradapterpowermanagement) function. **PcUnregisterAdapterPowerManagement** helps the system to avoid making a power change request while the adapter driver is being unloaded. This function must only be called if the power management interface for the adapter was previously registered with PortCls.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[PcRegisterAdapterPowerManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregisteradapterpowermanagement)