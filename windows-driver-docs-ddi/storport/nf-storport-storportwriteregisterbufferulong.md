# StorPortWriteRegisterBufferUlong macro

## Description

The **StorPortWriteRegisterBufferUlong** routine transfers a given number of ULONG values from a buffer to the HBA.

## Parameters

### `h`

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `r`

Pointer to the register. The given *Register* must be in a mapped memory space range that was returned by [**StorPortGetDeviceBase**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdevicebase).

### `b`

Pointer to a buffer containing the data to be written.

### `c`

Specifies the number of ULONG values to be transferred to the HBA.

## See also

[StorPortWriteRegisterBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportwriteregisterbufferulong)