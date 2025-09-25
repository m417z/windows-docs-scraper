# PcRegisterAdapterPowerManagement function

## Description

The **PcRegisterAdapterPowerManagement** function registers the adapter's power-management interface with the PortCls system driver.

## Parameters

### `Unknown`

Pointer to an adapter driver object's [**IUnknown**](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) interface. The PortCls system driver queries this object for its [IAdapterPowerManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iadapterpowermanagement) interface.

### `pvContext1` [in]

Pointer to the adapter's [functional device object (FDO)](https://learn.microsoft.com/windows-hardware/drivers/). This parameter is a pointer to a system structure of type [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) but is cast to type PVOID.

## Return value

**PcRegisterAdapterPowerManagement** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IAdapterPowerManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iadapterpowermanagement)