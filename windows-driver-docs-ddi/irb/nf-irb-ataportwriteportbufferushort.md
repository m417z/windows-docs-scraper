# AtaPortWritePortBufferUshort function

## Description

The **AtaPortWritePortBufferUshort** routine transfers the indicated number of USHORT values from a buffer to the HBA.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Port` [in]

The pointer to the I/O port. The address value that is assigned to this parameter must be within the range of mapped I/O space addresses that are obtained by a call to [AtaPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportgetdevicebase).

### `Buffer` [in]

A pointer to the source buffer.

### `Count` [in]

Specifies the number of USHORT values to write to the HBA.

## See also

[AtaPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportgetdevicebase)

[AtaPortWritePortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportwriteportbufferuchar)

[AtaPortWritePortBufferUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportwriteportbufferulong)