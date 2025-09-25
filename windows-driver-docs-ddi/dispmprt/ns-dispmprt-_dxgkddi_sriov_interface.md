# _DXGKDDI_SRIOV_INTERFACE structure

## Description

The SRIOV device interface exposes the PCIe virtual devices.

Functions to interact with the virtual device’s (GPU partitions) configuration space are exposed along with how the device will appear in the guest (BARs, vendor ID etc.). Finally, power state control functions are exposed to enable/disable/reset VFs. This interface is exposed even for devices that do not directly support SR-IOV in hardware. In the case of no hardware SR-IOV support, the virtual functions are managed by the kernel mode driver itself and are in effect virtualized themselves.

A miniport driver must support all functions in this group.

## Members

### `Size`

Size.

### `Version`

Version.

### `Context`

The context.

### `InterfaceReference`

Reference.

### `InterfaceDereference`

Deference.

### `DxgkDdiReadVirtualFunctionConfig`

[DxgkDdiReadVirtualFunctionConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_readvirtualfunctionconfig)

### `DxgkDdiWriteVirtualFunctionConfig`

[DxgkDdiWriteVirtualFunctionConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_writevirtualfunctionconfig)

### `DxgkDdiReadVirtualFunctionConfigBlock`

[DxgkDdiReadVirtualFunctionConfigBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_readvirtualfunctionconfigblock)

### `DxgkDdiWriteVirtualFunctionConfigBlock`

[DxgkDdiWriteVirtualFunctionConfigBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_writevirtualfunctionconfigblock)

### `DxgkDdiQueryProbedBars`

[DxgkDdiQueryProbedBars](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_queryprobedbars)

### `DxgkDdiGetVendorAndDevice`

[DxgkDdiGetVendorAndDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getvendoranddevice)

### `DxgkDdiGetDeviceLocation`

[DxgkDdiGetDeviceLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdevicelocation)

### `DxgkDdiResetVirtualFunction`

[DxgkDdiResetVirtualFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_resetvirtualfunction)

### `DxgkDdiSetVirtualFunctionPowerState`

[DxgkDdiSetVirtualFunctionPowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_setvirtualfunctionpowerstate)

### `DxgkDdiGetResourceForBar`

[DxgkDdiGetResourceForBar](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getresourceforbar)

### `DxgkDdiQueryVirtualFunctionLuid`

[DxgkDdiQueryVirtualFunctionLuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_queryvirtualfunctionluid)

## Remarks

## See also