# AtaPortWritePortBufferUchar function

## Description

The **AtaPortWritePortBufferUchar** routine transfers the indicated number of unsigned bytes from a buffer to the HBA.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Port` [in]

Pointer to the I/O port. The address value that is assigned to this parameter must be within the range of mapped I/O space addresses that are obtained by a call to [AtaPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportgetdevicebase).

### `Buffer` [in]

A pointer to the source buffer.

### `Count` [in]

Specifies the number of UCHAR values to write to the HBA.

## See also

[AtaPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportgetdevicebase)

[AtaPortWritePortBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportwriteportbufferulong)

[AtaPortWritePortBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportwriteportbufferushort)