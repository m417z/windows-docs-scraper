# DXGKCB_HARDWARECONTENTPROTECTIONTEARDOWN callback function

## Description

**DXGKCB_HARDWARECONTENTPROTECTIONTEARDOWN** is called when a hardware content protection tear-down event occurs.

## Parameters

### `hAdapter` [in]

A handle to the graphics adapter where the tear-down event is occurring.

### `Flags` [in]

Additional flags defined by the [**DXGK_HARDWARE_CONTENT_PROTECTION_TEARDOWN_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_hardware_content_protection_teardown_flags) enumeration.

## Remarks

The kernel-mode display miniport driver should always call **DXGKCB_HARDWARECONTENTPROTECTIONTEARDOWN** both before and after a hardware content protection tear-down event occurs.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, call **DxgkCbHardwareContentProtectionTeardown** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface). The driver can call this callback at either passive level or at dispatch level.

## See also

[**DXGK_HARDWARE_CONTENT_PROTECTION_TEARDOWN_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_hardware_content_protection_teardown_flags)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)