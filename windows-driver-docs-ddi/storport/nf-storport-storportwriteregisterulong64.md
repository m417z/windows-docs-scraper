# StorPortWriteRegisterUlong64 macro

## Description

This **StorPortWriteRegisterUlong64** routine writes a **ULONG64** value to the specified register address.

## Parameters

### `h`

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `r`

Pointer to the register where the data is written to. The register must be a mapped range in memory space

### `v`

A **ULONG64** value to write to the register.

## Remarks

The **StorPortWriteRegisterUlong64** routine is only available on the 64-bit version of Windows.

## See also

[StorPortReadRegisterUlong64](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadregisterulong64)