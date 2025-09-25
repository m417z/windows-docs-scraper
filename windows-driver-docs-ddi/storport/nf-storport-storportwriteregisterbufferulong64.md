# StorPortWriteRegisterBufferUlong64 macro

## Description

This **StorPortWriteRegisterBufferUlong64** routine writes a number of **ULONG64** values from a specified 64-bit register address.

## Parameters

### `h`

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `r`

Pointer to the register where the data is written to. The given *Register* must be in a mapped memory-space range returned by [**StorPortGetDeviceBase**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdevicebase).

### `b`

Pointer to the buffer to write the **ULONG64** values from.

### `c`

Specifies the number of data values to write. Each data item has a size of **sizeof**(ULONG64).

## Remarks

The **StorPortWriteRegisterBufferUlong64** routine is only available on the 64-bit version of Windows.

## See also

[StorPortReadRegisterBufferUlong64](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreadregisterbufferulong64)