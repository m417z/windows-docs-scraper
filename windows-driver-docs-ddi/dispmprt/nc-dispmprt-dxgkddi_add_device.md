# DXGKDDI_ADD_DEVICE callback function

## Description

The *DxgkDdiAddDevice* function creates a context block for a display adapter and returns a handle that represents the display adapter.

## Parameters

### `PhysicalDeviceObject` [in]

A pointer to a physical device object (PDO) that identifies a display adapter.

### `MiniportDeviceContext` [out]

A pointer to a variable that receives a handle, created by the display miniport driver, that will represent the display adapter identified by **PhysicalDeviceObject**. The display miniport driver can return NULL in this parameter to indicate that it will not support the display adapter identified by **PhysicalDeviceObject**.

## Return value

*DxgkDdiAddDevice* returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

The *DxgkDdiAddDevice* function allocates a private context block that is associated with the display adapter identified by **PhysicalDeviceObject**. You can think of the handle returned in **MiniportDeviceContext** as a handle to the display adapter or as a handle to the context block associated with the display adapter. The DirectX graphics kernel subsystem (*Dxgkrnl.sys*) will supply the handle in subsequent calls to the display miniport driver. The following list gives examples of various components of *Dxgkrnl.sys* passing the handle to functions implemented by the display miniport driver.

* The display port driver supplies the handle in the **MiniportDeviceContext** parameter of the [*DxgkDdiStartDevice*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

* The VidPN manager supplies the handle in the **hAdapter** parameter of the [*DxgkDdiIsSupportedVidPn*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_issupportedvidpn) function.

* The DirectX graphics core supplies the handle in the **hAdapter** parameter of the [*DxgkDdiQueryAdapterInfo*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function.

Do not be confused by the fact that sometimes the handle is named **MiniportDeviceContext** and sometimes it is named **hAdapter**. Also, do not confuse this handle with the **hDevice** parameter that is passed to certain display miniport driver functions.

*DxgkDdiAddDevice* is invoked for one device at a time in serial. Its behavior is the same as the standard [**DRIVER_ADD_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) callback for WDM kernel-mode drivers.

Some display adapter cards have two or more PCI functions that play the role of display adapter. For example, certain older cards implement multiple views by having a separate PCI function for each view. The display port driver calls *DxgkDdiAddDevice* once for each of those PCI functions, at which time the display miniport driver can indicate that it supports the PCI function (by setting **MiniportDeviceContext** to a nonzero value) or that it does not support the PCI function (by setting **MiniportDeviceContext** to NULL). To get information about a particular PCI function, the display miniport driver can pass **PhysicalDeviceObject** to [*IoGetDeviceProperty*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceproperty).

In [*DxgkDdiRemoveDevice*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_remove_device), free your context block and any other resources you allocate during *DxgkDdiAddDevice*.

The *DxgkDdiAddDevice* function should be made pageable.

## See also

[*DxgkDdiRemoveDevice*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_remove_device)

[*DxgkDdiStartDevice*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)