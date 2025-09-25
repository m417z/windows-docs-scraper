# DXGK_DISPLAY_DIAGNOSTICS_INTERFACE structure

## Description

A kernel-mode component that needs to use the display diagnostics interface calls the display miniport driver's **DxgkDdiQueryInterface** function.

## Members

### `Size` [in]

Size, in bytes, of this structure.

### `Version` [in]

Version number of the display diagnostics interface. Version number constants are defined in *dispmprt.h* (for example, DXGK_DISPLAY_DIAGNOSTICS_INTERFACE_VERSION_1).

### `Context` [out]

Pointer to a private context block provided by the display miniport driver. The operating system will provide this *Context* back to the driver in interface DDI calls. The driver should ensure that this context is adapter-specific and not driver-global because the operating system stores the interface information per adapter.

### `InterfaceReference` [out]

Pointer to the display miniport driver's [interface reference function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference).

### `InterfaceDereference` [out]

Pointer the display miniport driver's [interface dereference function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference).

### `DxgkDdiGetDisplayStateNonIntrusive` [out]

Pointer to the display miniport driver's [**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive) function.

### `DxgkDdiGetDisplayStateIntrusive` [out]

Pointer to the display miniport driver's [**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive) function.

## Remarks

The operating system will query the display diagnostics interface for each graphics adapter when they are started.

## See also

[**DxgkDdiGetDisplayStateIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystateintrusive)

[**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive)

[**PINTERFACE_DEREFERENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference)

[**PINTERFACE_REFERENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference)