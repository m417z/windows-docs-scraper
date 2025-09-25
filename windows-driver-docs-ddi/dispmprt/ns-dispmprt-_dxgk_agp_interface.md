# DXGK_AGP_INTERFACE structure

## Description

The **DXGK_AGP_INTERFACE** structure contains pointers to functions in the Accelerated Graphics Port (AGP) interface, which is implemented by the display port driver.

## Members

### `Size`

The size, in bytes, of this structure.

### `Version`

The version number of the AGP interface. Version number constants are defined in *Dispmprt.h* (for example, DXGK_AGP_INTERFACE_VERSION_1).

### `Context`

A pointer to a context that is provided by the display port driver.

### `InterfaceReference`

A pointer to an interface reference function that is implemented by the display port driver.

### `InterfaceDereference`

A pointer to an interface dereference function that is implemented by the display port driver.

### `AgpAllocatePool`

A pointer to the display port driver's [**AgpAllocatePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_agp_allocate_pool) function.

### `AgpFreePool`

A pointer to the display port driver's [**AgpFreePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_agp_free_pool) function.

### `AgpSetCommand`

A pointer to the display port driver's [**AgpSetCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_agp_set_command) function.

## Remarks

The display miniport driver supplies the **Size** and **Version** members of this structure, and then calls [**DxgkCbQueryServices**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_query_services), which fills in the remaining members of this structure.