# StorPortWriteRegisterUchar macro

## Description

The **StorPortWriteRegisterBufferUshort** routine transfers a given number of character values from a buffer to the indicated HBA register address.

## Parameters

### `h`

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `r`

Pointer to the register. The given *Register* must be in a mapped memory space range returned by [**StorPortGetDeviceBase**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdevicebase).

### `v`

Specifies the value to be written to the HBA's register.

## See also

[ScsiPortWriteRegisterBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportwriteregisterbufferushort)